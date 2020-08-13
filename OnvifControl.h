#ifndef __ONVIFDEVICE_H
#define __ONVIFDEVICE_H
#pragma once
#include "OnvifImaging.h"
#include "OnvifPTZ.h"

using namespace std;
class OnvifControl{
public:
  OnvifControl(string url,string username,string passwd);
  ~OnvifControl();

  int getMediaUrl(string& mediaAddr);
  int getProfile(string& profileToken);
  int getPTZUrl(string& PTZAddr);
  int GetVideoSources(string& videoSourceToken);
  int getIMAGEUrl(string& imageUrl);

  int ptzContinuousMove(int command);
  int ptzContinuousStop();
  int getPtzMoveSpeed(int& speed);
  int setPtzMoveSpeed(const int& speed);
  int ptzRelativeMove(int command);
  
  //功能：控制预置位; command: GOTO REMOVE presettoken:1~300
  int ptzPreset(int command, string presettoken);
  //功能：根据预置点token查询name和position
  int GetOnePresets(const string& pretoken,float& x,float& y,float& z,string& prename);
  //功能：查询所有已设置的预置点token、name和ptz值
  int GetAllPresets(vector<PreInfo>& allpresets);
  //功能：设置预置点位。presetToken:1~300 ; presetName:name
  int SetPreset(string presetToken,string presetName);
  //功能：Continuous Focus Move command:FOCUSIN FOCUSOUT
  int ContinuousFocusMove(int command);
  //功能：Continuous Focus Stop
  int ContinuousFocusStop();
  // 1< speed <10
  int getFocusMoveSpeed(int& speed);
  int setFocusMoveSpeed(const int& speed);

  //功能：复位
  int GotoHomePosition();
  //功能：设置ImagingSettings
  int SetImagingSettings();
  //功能：获取ImagingSettings
  int GetImagingSettings(ImagingSet& imageSet);
  
private:
  string m_deviceurl;
  string m_username;
  string m_passwd;
  string mediaAddr;
  string PTZAddr;
  string imageUrl;
  string strProfileToken;
  string videoSourceToken;

  int ptzMoveSpeed = 3;
  int focusMoveSpeed = 5;
  float Brightness = 50.0;
  float ColorSaturation = 35.0;
  float Contrast = 25.0;
  bool ForcePersistence = true; 
  float ExposureTime = 10000.0;
};
//功能: 发现设备获取设备地址
void detectDevice(vector<string>& vecDevAddr);
#endif
