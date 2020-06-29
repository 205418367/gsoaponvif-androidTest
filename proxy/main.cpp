#include "onvifdevice.h"
#include "onvifcomm.h"

int main(){ 
    vector<string> addr;
    detectDevice(addr);
    OnvifComm comm;
    char uri_auth[200]={0};
    for(vector<string>::iterator it = addr.begin(); it != addr.end(); ++it){
        //cout<<"addr: "<<it<<endl;
        OnvifDevice onvifDevice(*it, "admin", "leinao123");
        string mediaAddr;
        onvifDevice.getMediaUrl(mediaAddr);
        cout<<"mediaAddr: "<<mediaAddr<<endl;
        string profileToken;
        onvifDevice.getProfile(mediaAddr.c_str(), profileToken);
        cout<<"profileToken: "<<profileToken<<endl;
        string rtspUrl;
        onvifDevice.getRTSPUrl(mediaAddr.c_str(), rtspUrl);
        cout<<"rtspUrl: "<<rtspUrl<<endl;
        /*
        string imageUrl;
        onvifDevice.getIMAGEUrl(mediaAddr.c_str(), imageUrl);
        comm.make_uri_withauth((char *)(imageUrl).c_str(), "admin", "leinao123", uri_auth);
        cout<<"uri_auth: "<<uri_auth<<endl;
        char uri_auth[200]={0};
        comm.make_uri_withauth((char *)(rtspUrl).c_str(), "admin", "leinao123", uri_auth);
        cout<<"uri_auth: "<<uri_auth<<endl;
        comm.open_rtsp(uri_auth); 
        string PTZUrl;
        onvifDevice.getPTZUrl(PTZUrl);
        cout<<"PTZUrl: "<<rtspUrl<<endl;
        string Manufacturer,Model,FirmwareVersion,SerialNumber,HardwareId;
        onvifDevice.getDeviceInformation(Manufacturer, Model,FirmwareVersion,
                               SerialNumber,HardwareId);
        cout<<"Manufacturer: "<<Manufacturer<<" Model: "<<Model<<endl;
        cout<<"HardwareId: "<<HardwareId<<" SerialNumber: "<<Model<<endl;
        onvifDevice.setDateTime();
        int year,month,day,hour,minute,second;
        onvifDevice.getDateTime(year, month, day, hour, minute, second);
        cout<<year<<"-"<<month<<"-"<<day<<endl;
        cout<<hour<<":"<<minute<<":"<<second<<endl;
        //onvifDevice.ptzContinuousMove(DOWN);
        //onvifDevice.ptzContinuousStop();
        onvifDevice.ptzRelativeMove(RIGHT);
        */
    }
    return 0;
}
