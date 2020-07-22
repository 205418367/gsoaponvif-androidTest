#ifndef __ONVIFDEVICE_H
#define __ONVIFDEVICE_H
#pragma once
#include <iostream>
#include <algorithm>
#include "openssl/rsa.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <ctime>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define ZOOMIN 4
#define ZOOMOUT 5
#define speed 1
#define MAX_HOSTNAME_LEN 128
#define MAX_LOGMSG_LEN 256 

#define SOAP_TO         "urn:schemas-xmlsoap-org:ws:2005:04:discovery"
#define SOAP_ACTION     "http://schemas.xmlsoap.org/ws/2005/04/discovery/Probe"
#define SOAP_MCAST_ADDR "soap.udp://239.255.255.250:3702"                       // onvif规定的组播地址
#define SOAP_ITEM       ""                                                      // 寻找的设备范围
#define SOAP_TYPES      "dn:NetworkVideoTransmitter"                            // 寻找的设备类型

using namespace std;
class OnvifDevice{
public:
  OnvifDevice(string url,string username,string passwd);
  ~OnvifDevice();
  int getMediaUrl(string& mediaAddr);
  int getPTZUrl(string& PTZAddr);
  int getProfile(const char *mediaAddr,string& profileToken);
  int getRTSPUrl(const char* mediaAddr,string& rtspUrl);
  int getDateTime(int& year, int& month, int& day,
                             int& hour, int& minute, int& second);
  int setDateTime();
  int ptzContinuousMove(int command);
  int ptzRelativeMove(int command);
private:
  string m_deviceurl;
  string m_username;
  string m_passwd;
};
//搜索设备不需要鉴权，获取设备ip地址
void detectDevice(vector<string>& vecDevAddr);
#endif
