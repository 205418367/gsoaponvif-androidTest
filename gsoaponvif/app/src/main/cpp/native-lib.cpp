#include <jni.h>
#include <string>
#include "onvifdevice.h"
#include "soapPrint.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_gsoaponvif_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    vector<string> addr;
    detectDevice(addr);
    for(vector<string>::iterator it = addr.begin(); it != addr.end(); ++it) {
        SM_Trace("addr: %s","######");
    }
    return env->NewStringUTF(hello.c_str());
}
