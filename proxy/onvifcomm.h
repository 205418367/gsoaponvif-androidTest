#ifndef __ONVIFCOMM_H
#define __ONVIFCOMM_H
#pragma once
#include <cstring>
#include <fstream>
#include "onvifdevice.h"

extern "C" { 
#include <libavformat/avformat.h>  
#include <libavcodec/avcodec.h>  
#include <libswscale/swscale.h>  
#include <libavformat/avformat.h>  
#include <libavcodec/avcodec.h>  
#include <libswscale/swscale.h>  
#include <libavutil/opt.h>
#include <libavcodec/avcodec.h>
#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/imgutils.h>
#include <libavutil/mathematics.h>
#include <libavutil/samplefmt.h>
}

using namespace std;
class OnvifComm{
public:
    OnvifComm();
    ~OnvifComm();
    void make_uri_withauth(char* src_uri, char* username, char* password, char* uri_auth);
    int open_rtsp(char* uri_auth);
};
#endif
