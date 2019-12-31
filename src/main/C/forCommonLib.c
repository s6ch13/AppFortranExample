/*
    forCommonLib.c
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

