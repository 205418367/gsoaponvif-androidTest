#include "soapPrint.h"

static const char* kTAG = "IntelligentPatrol-native";
#define LOGI(...) \
  ((void)__android_log_print(ANDROID_LOG_INFO, kTAG, __VA_ARGS__))

void SM_Trace(const char* const format, ...)
{
    char strBuffer[1024] = { 0 };
#ifdef _WINDOWS
    va_list vlArgs;
    va_start(vlArgs, format);
    _vsnprintf_s(strBuffer, sizeof(strBuffer) - 1, format, vlArgs);
    va_end(vlArgs);
    OutputDebugStringA(strBuffer);
#else
    va_list vlArgs;
    va_start(vlArgs, format);
    vsnprintf(strBuffer, sizeof(strBuffer) - 1, format, vlArgs);
    va_end(vlArgs);
    LOGI("%s\n", strBuffer);
#endif//_WINDOWS
}