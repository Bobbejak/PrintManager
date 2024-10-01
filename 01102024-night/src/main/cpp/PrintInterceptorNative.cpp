#include <jni.h>
#include "com_example_PrintInterceptor.h"

JNIEXPORT jboolean JNICALL Java_com_example_PrintInterceptor_interceptPrintJob
  (JNIEnv* env, jobject obj, jstring jobName) {
    // Implementation will go here
    return JNI_TRUE;
}