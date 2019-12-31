/*
	App Fortran example 	
    Copyright (C) 2019  Sriram C.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
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


