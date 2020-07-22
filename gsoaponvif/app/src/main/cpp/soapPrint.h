#include <stdio.h>
#include <android/log.h>

// const char* const _Format(c中常见) 等价于 const string& _Format(c++中常见);
void SM_Trace(const char* const _Format, ...);