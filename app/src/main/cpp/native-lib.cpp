#include <jni.h>
#include <string>
#include "onvifdevice.h"
#include "soapPrint.h"

static const char* kTAG = "IntelligentPatrol";
#define LOGI(...) \
  ((void)__android_log_print(ANDROID_LOG_INFO, kTAG, __VA_ARGS__))

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_gsoaponvif_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    vector<string> addr;
    detectDevice(addr);
    for(vector<string>::iterator it = addr.begin(); it != addr.end(); ++it){
        OnvifDevice onvifDevice(*it, "admin", "123456");
        onvifDevice.ptzContinuousMove(UP);
        onvifDevice.ptzContinuousStop();
    }
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
