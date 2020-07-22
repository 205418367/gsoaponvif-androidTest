#include "onvifdevice.h"

int main(){ 
  vector<string> addr;
  detectDevice(addr);

  for(vector<string>::iterator it = addr.begin(); it != addr.end(); ++it)
  {
    //cout<<"addr: "<<it<<endl;
    OnvifDevice onvifDevice(*it, "admin", "leinao123");
    string mediaAddr;
    onvifDevice.getMediaUrl(mediaAddr);
    cout<<"mediaAddr: "<<mediaAddr<<endl;
    string profileToken;
    onvifDevice.getProfile(mediaAddr.c_str(),profileToken);
    cout<<"profileToken: "<<profileToken<<endl;
    string rtspUrl;
    onvifDevice.getRTSPUrl(mediaAddr.c_str(),rtspUrl);
    cout<<"rtspUrl: "<<rtspUrl<<endl;
    string PTZUrl;
    onvifDevice.getPTZUrl(PTZUrl);
    cout<<"PTZUrl: "<<rtspUrl<<endl;
    onvifDevice.setDateTime();
    int year,month,day,hour,minute,second;
    onvifDevice.getDateTime(year, month, day, hour, minute, second);
    cout<<year<<"-"<<month<<"-"<<day<<endl;
    cout<<hour<<":"<<minute<<":"<<second<<endl;
    onvifDevice.ptzContinuousMove(DOWN);
    //onvifDevice.ptzRelativeMove(DOWN);
  }
return 0;
}
