//#include "OnvifPTZ.h"
//#include "OnvifImaging.h"
#include "onvifdevice.h"
#include <unistd.h>
#include <vector>

using namespace std;
int main(){ 
    //vector<string> addr;
    //detectDevice(addr);
    //for(vector<string>::iterator it = addr.begin(); it != addr.end(); ++it){
        //cout<<"####"<<*it<<"####"<<endl;
    //}
        //string::size_type idx = (*it).find("192.168.8.220");
        //if(idx == string::npos)
            //continue;

        //cout<<"####"<<*it<<"####"<<endl;
        string it = "http://192.168.8.220/onvif/device_service";
        string user = "admin";
        string pass = "leinao123";
        OnvifDevice onvifdevice(it,user,pass);        

        //int speed;
        //OnvifPTZ.setPtzMoveSpeed(2);
        //OnvifPTZ.getPtzMoveSpeed(speed);
        //cout<<"speed: "<<speed<<endl;
        //ImagingSet imageSet;
        //OnvifPTZ.ptzContinuousMove(LEFT);
        //OnvifPTZ.ptzContinuousStop();
	//OnvifPTZ.ptzRelativeMove(UP);
        //sleep(3);
        //OnvifPTZ.SetPreset("3","onvif");
        //vector<PreInfo> allpresets;
        //onvifdevice.GetAllPresets(allpresets);
        //for (int i=0;i<allpresets.size();i++){
        //    PreInfo preset = allpresets[i];
	//    cout<<"name :"<<preset.name<<endl;
        //    cout<<"token :"<<preset.token<<endl;
        //    cout<<"p :"<<preset.p<<endl;
        //    cout<<"t :"<<preset.t<<endl;
        //    cout<<"z :"<<preset.z<<endl;
        //}
        float x,y,z;
        string prename;
        onvifdevice.GetOnePresets("5",prename,x,y,z);
        cout<<"prename: "<<prename<<endl;
        cout<<"x: "<<x<<endl;
        cout<<"y: "<<x<<endl;
        cout<<"z: "<<x<<endl;

        //OnvifImaging Imaging(it, user, pass);
        //ImagingSet imageSet;
        //Imaging.GetImagingSettings(imageSet);
        //cout<<"ExposureTime: "<<imageSet.ExposureTime<<endl;
      
        //onvifDevice.SetImagingSettings();
        //string videoSourceToken;
        //onvifDevice.GetVideoSources(videoSourceToken);
        //cout<<"video :"<<videoSourceToken<<endl;
        //onvifDevice.ContinuousFocusMove(0.1);
        //sleep(2);
        //onvifDevice.ContinuousFocusStop();
    return 0;
}
