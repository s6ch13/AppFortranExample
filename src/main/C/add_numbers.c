/*
App Fortran example 	
Copyright (C) 2019  Sriram C.


Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    
*/ 

/*
  C code for interfacing the java and fortran routines.
*/


#include <stdio.h>
#include <stdlib.h>
#include "forCommonLib.h"

// Format of include should be "packagename_classname"
// this header file is created during jni generation
#include "appFortranExample_AddNumbers.h"


// Prototype Fortran routines as extern, and we pass params to Fortran by
// reference. Name mangling for gfortran is Fortran lowercase routine name
// (here, "add") + "_".
extern void add_(

                 int *,      // l
                 int *,      // m
		 int *       // n
);

// Note the name mangling here. Instead of main(), this function is
// "Java_" + mangled_fully_qualified_class_name + "_" + C function that
// Java calls.
JNIEXPORT jint JNICALL Java_appFortranExample_AddNumbers_add(
                                                     JNIEnv *env,         /* interface pointer */
                                                     jobject obj,         /* "this" pointer */

                                                     jint l,
                                                     jint m,
                                                     jintArray jn)


{
    
  jint *n = (*env)->GetIntArrayElements(env,jn,0);

  // Call the Fortran routine.  
  add_(&l,&m,n);

    
  // Clear the pointers before returning to Java.  copy back values in C back into jc.
  (*env)->ReleaseIntArrayElements(env, jn, n, 0);
  
  return 1;
}

// Prototype Fortran routines as extern, and we pass params to Fortran by
// reference. Name mangling for gfortran is Fortran lowercase routine name
// (here, "matrixadd") + "_".
// routine to add two matrices.
extern void matrixadd_(

                 float *,      // a
                 float *,      // b
		 float *      // c
);


// Note the name mangling here. Instead of main(), this function is
// "Java_" + mangled_fully_qualified_class_name + "_" + C function that
// Java calls.
// routines to add two matrices.  Fortran passes 
JNIEXPORT jint JNICALL Java_appFortranExample_AddNumbers_matrixAdd(
                                                     JNIEnv* env,         /* interface pointer */
                                                     jobject obj,         /* "this" pointer */

                                                     jobjectArray ja,
                                                     jobjectArray jb,
                                                     jobjectArray jc)


{
  // Copy the java 2 dimensional arrays to c arrays
  // this copy ensures the correct row column order to be understood
  // by fortran
  jfloat * a = matFloatCopy(env,ja);
  jfloat * b = matFloatCopy(env,jb);
  jfloat * c = matFloatCopy(env,jc);

  // Call the Fortran routine to add the matrices a and b.  results are stored in c
  matrixadd_(a,b,c);

  // copy back the results into the object array jc
  matFloatCopyBack(env,&jc,c);

  // free the pointers
  free(a);
  free(b);
  free(c);
    
  return 1;
}


