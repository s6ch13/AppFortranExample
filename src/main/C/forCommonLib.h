/*
******************************************************************************
* Pile Foundations
* Geotechnical Engineering Modelling Software (GEMS) LLP
* Copyright (c) V.S.Chandrasekaran 1998 - 2019
******************************************************************************
 */

#ifndef FOR_COMMON_LIB

#define FOR_COMMON_LIB

#include "jni.h"

// LIBRARY ROUTINES
// These library routines aid transfer of two dimensional arrays or matrics
// between java and fortran


void matFloatCopyBack(JNIEnv* env, jobjectArray *oA,jfloat *c);

void matDoubleCopyBack(JNIEnv* env, jobjectArray *oA,jdouble *c);

jfloat * matFloatCopy(JNIEnv* env, jobjectArray oA );

jdouble * matDoubleCopy(JNIEnv* env, jobjectArray oA );

#endif
