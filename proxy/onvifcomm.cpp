#include "onvifcomm.h"

OnvifComm::OnvifComm(){};
OnvifComm::~OnvifComm(){};
void OnvifComm::make_uri_withauth(char* src_uri, char* username, char* password, char* uri_auth){
    char* p = strstr(src_uri, "//");
    p += 2;
    memcpy(uri_auth, src_uri, p - src_uri);
    sprintf(uri_auth + strlen(uri_auth), "%s:%s@", username, password);
    strcat(uri_auth, p);
}

int OnvifComm::open_rtsp(char* uri_auth){
    int result = 0;
    AVPacket packet;
    ofstream outfile;
    avformat_network_init();
    av_register_all(); 
    AVFormatContext* pFormatCtx=NULL;
    AVDictionary* options = NULL;
    av_dict_set(&options, "rtsp_transport", "tcp", 0);
    av_dict_set(&options, "stimeout", "2000000", 0);
    avformat_open_input(&pFormatCtx, uri_auth, NULL, NULL);
    avformat_find_stream_info(pFormatCtx, NULL);
    av_dump_format(pFormatCtx, 0, uri_auth, 0);
    outfile.open("vedio.dat", ios::out | ios::trunc );
    
    while (true){
		result = av_read_frame(pFormatCtx, &packet); 
           if (result != 0){
			return result;
		}
           outfile << &packet << endl;
    }
    outfile.close();
    avformat_close_input(&pFormatCtx);
    return result;        
}
