/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_PrintInterceptor */

#ifndef _Included_com_example_PrintInterceptor
#define _Included_com_example_PrintInterceptor
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_PrintInterceptor
 * Method:    interceptPrintJob
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_PrintInterceptor_interceptPrintJob
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_example_PrintInterceptor
 * Method:    initializeNative
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_PrintInterceptor_initializeNative
  (JNIEnv *, jobject);

/*
 * Class:     com_example_PrintInterceptor
 * Method:    cleanupNative
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_PrintInterceptor_cleanupNative
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
