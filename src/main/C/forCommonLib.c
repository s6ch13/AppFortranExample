/*
    forCommonLib.c
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


#include "forCommonLib.h"
#include <stdlib.h>

// LIBRARY ROUTINES
// These library routines aid transfer of two dimensional arrays or matrics
// between java and fortran.  The order of arrays is different in java & 
// fortran.  This copies the data into one memory block so it can be
// accessed by fortran

// copy the jfloat array c into jobjectArray oA
// pass return values from Fortran to Java
void matFloatCopyBack(JNIEnv* env, jobjectArray *oA,jfloat *c)
{

  int numRows = (*env)->GetArrayLength(env,*oA);
  int numCols = (*env)->GetArrayLength(env,(*env)->GetObjectArrayElement(env,*oA, 0));
  //  //printf("matFloatCopyBack\n");

  ////printf("%d %d\n\n",numRows,numCols);
  for(int i=0; i<numRows; i++) {

    jfloatArray oneDim = (jfloatArray)(*env)->GetObjectArrayElement(env,*oA, i);

    for(int j = 0; j < numCols;j++) {
       (*env)->SetFloatArrayRegion(env,oneDim,j,1,c+ j * numRows + i);
    }
  }
}

// copy the jdouble array c into jobjectArray oA
// pass return values from Fortran to Java
void matDoubleCopyBack(JNIEnv* env, jobjectArray *oA,jdouble *c)
{

  int numRows = (*env)->GetArrayLength(env,*oA);
  int numCols = (*env)->GetArrayLength(env,(*env)->GetObjectArrayElement(env,*oA, 0));
  //  //printf("matDoubleCopyBack\n");

  ////printf("%d %d\n\n",numRows,numCols);
  for(int i=0; i<numRows; i++) {

    jdoubleArray oneDim = (jdoubleArray)(*env)->GetObjectArrayElement(env,*oA, i);

    for(int j = 0; j < numCols;j++) {
       (*env)->SetDoubleArrayRegion(env,oneDim,j,1,c+ j * numRows + i);
    }
  }
}



// Pass a 2 dimensional float array from Java to Fortran
jfloat * matFloatCopy(JNIEnv* env, jobjectArray oA )
{
  int numRows = (*env)->GetArrayLength(env,oA);
  int numCols = (*env)->GetArrayLength(env,(*env)->GetObjectArrayElement(env,oA, 0));

  jfloat* r = (jfloat* )malloc(numRows * numCols * sizeof(jfloat ));

  for(int i=0; i<numRows; i++) {

    jfloatArray oneDimRow = (jfloatArray)(*env)->GetObjectArrayElement(env,oA, i);

    jfloat *element = (*env)->GetFloatArrayElements(env,oneDimRow,0);
    for(int j=0; j<numCols; j++) {
      // store array in column first notation for fortran processing
      *(r+ j*numRows + i) = *(element+j);
     }
  }
  return r;
}

// Pass a 2 dimensional double array from Java to Fortran
jdouble * matDoubleCopy(JNIEnv* env, jobjectArray oA )
{
  int numRows = (*env)->GetArrayLength(env,oA);
  int numCols = (*env)->GetArrayLength(env,(*env)->GetObjectArrayElement(env,oA, 0));

  jdouble* r = (jdouble* )malloc(numRows * numCols * sizeof(jdouble));

  for(int i=0; i<numRows; i++) {

    jdoubleArray oneDimRow = (jdoubleArray)(*env)->GetObjectArrayElement(env,oA, i);

    jdouble *element = (*env)->GetDoubleArrayElements(env,oneDimRow,0);
    for(int j=0; j<numCols; j++) {
      // store array in column first notation for fortran processing
      *(r+ j*numRows + i) = *(element+j);
     }
  }
  return r;
}

