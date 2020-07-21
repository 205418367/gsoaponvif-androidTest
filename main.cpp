#include "onvifdevice.h"
#include <unistd.h>

int main(){ 
    vector<string> addr;
    detectDevice(addr);
    for(vector<string>::iterator it = addr.begin(); it != addr.end(); ++it){
        OnvifDevice onvifDevice(*it, "admin", "leinao123");
        onvifDevice.ptzContinuousMove(LEFT);
        onvifDevice.ptzContinuousStop();
    }
    return 0;
}
