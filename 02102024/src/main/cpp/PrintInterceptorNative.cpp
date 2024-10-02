#include <jni.h>
#include "com_example_PrintInterceptor.h"
#include <windows.h>
#include <detours.h>
#include <winspool.h>

// Declare function prototypes for the Windows API functions we want to hook
static DWORD(WINAPI* TrueStartDocPrinterW)(HANDLE hPrinter, DWORD Level, LPBYTE pDocInfo) = StartDocPrinterW;
static BOOL(WINAPI* TrueEndDocPrinter)(HANDLE hPrinter) = EndDocPrinter;

// Global variable to store the intercepted job name
static WCHAR g_InterceptedJobName[256] = { 0 };

// Implement hook functions
DWORD WINAPI HookedStartDocPrinterW(HANDLE hPrinter, DWORD Level, LPBYTE pDocInfo) {
    if (Level == 1) {
        DOC_INFO_1* docInfo = (DOC_INFO_1*)pDocInfo;
        wcscpy_s(g_InterceptedJobName, 256, docInfo->pDocName);
        OutputDebugStringW(L"StartDocPrinterW called for job: ");
        OutputDebugStringW(g_InterceptedJobName);
        OutputDebugStringW(L"\n");
    }
    return TrueStartDocPrinterW(hPrinter, Level, pDocInfo);
}

BOOL WINAPI HookedEndDocPrinter(HANDLE hPrinter) {
    OutputDebugStringW(L"EndDocPrinter called\n");
    return TrueEndDocPrinter(hPrinter);
}

// Functions to install and remove hooks
BOOL InstallHooks() {
    LONG error = DetourTransactionBegin();
    if (error != NO_ERROR) {
        return FALSE;
    }
    error = DetourUpdateThread(GetCurrentThread());
    if (error != NO_ERROR) {
        DetourTransactionAbort();
        return FALSE;
    }
    error = DetourAttach(&(PVOID&)TrueStartDocPrinterW, HookedStartDocPrinterW);
    if (error != NO_ERROR) {
        DetourTransactionAbort();
        return FALSE;
    }
    error = DetourAttach(&(PVOID&)TrueEndDocPrinter, HookedEndDocPrinter);
    if (error != NO_ERROR) {
        DetourTransactionAbort();
        return FALSE;
    }
    error = DetourTransactionCommit();
    return (error == NO_ERROR);
}

BOOL RemoveHooks() {
    LONG error = DetourTransactionBegin();
    if (error != NO_ERROR) {
        return FALSE;
    }
    error = DetourUpdateThread(GetCurrentThread());
    if (error != NO_ERROR) {
        DetourTransactionAbort();
        return FALSE;
    }
    error = DetourDetach(&(PVOID&)TrueStartDocPrinterW, HookedStartDocPrinterW);
    if (error != NO_ERROR) {
        DetourTransactionAbort();
        return FALSE;
    }
    error = DetourDetach(&(PVOID&)TrueEndDocPrinter, HookedEndDocPrinter);
    if (error != NO_ERROR) {
        DetourTransactionAbort();
        return FALSE;
    }
    error = DetourTransactionCommit();
    return (error == NO_ERROR);
}

JNIEXPORT jboolean JNICALL Java_com_example_PrintInterceptor_interceptPrintJob
(JNIEnv* env, jobject obj, jstring jobName) {
    const jchar* jJobName = env->GetStringChars(jobName, NULL);
    jsize jJobNameLength = env->GetStringLength(jobName);

    // Compare the intercepted job name with the provided job name
    if (wcsncmp(g_InterceptedJobName, (const wchar_t*)jJobName, jJobNameLength) == 0) {
        env->ReleaseStringChars(jobName, jJobName);
        return JNI_TRUE;
    }

    env->ReleaseStringChars(jobName, jJobName);
    return JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_example_PrintInterceptor_initializeNative
(JNIEnv* env, jobject obj) {
    InstallHooks();
}

JNIEXPORT void JNICALL Java_com_example_PrintInterceptor_cleanupNative
(JNIEnv* env, jobject obj) {
    RemoveHooks();
}