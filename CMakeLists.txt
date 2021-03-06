cmake_minimum_required(VERSION 3.5)
project(ONVIF_CLEINT)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o0 -g -ggdb -Wall -w -fPIC -fno-use-cxa-atexit -fexceptions")
add_definitions(-DWITH_NONAMESPACES -DWITH_DOM -DWITH_OPENSSL -DWITH_COOKIES)

include_directories(gsoap-onvif/onvif    
                    gsoap-onvif/plugin
                    gsoap-onvif/source/include
                    gsoap-onvif/
                    ${PROJECT_SOURCE_DIR}/
                    )

set(ProxyOBJ 
    gsoap-onvif/source/src/soapDeviceBindingProxy.cpp
    gsoap-onvif/source/src/soapMediaBindingProxy.cpp
    gsoap-onvif/source/src/soapPTZBindingProxy.cpp
    gsoap-onvif/source/src/soapPullPointSubscriptionBindingProxy.cpp
    gsoap-onvif/source/src/soapRemoteDiscoveryBindingProxy.cpp
    gsoap-onvif/source/src/soapImagingBindingProxy.cpp
    )
set(PluginOBJ
    gsoap-onvif/plugin/wsaapi.cpp
    gsoap-onvif/plugin/wsseapi.cpp
    gsoap-onvif/plugin/threads.cpp
    gsoap-onvif/plugin/duration.cpp
    gsoap-onvif/plugin/smdevp.cpp
    gsoap-onvif/plugin/mecevp.cpp
    gsoap-onvif/plugin/dom.cpp
    gsoap-onvif/plugin/stdsoap2.cpp
    gsoap-onvif/onvif/soapC.cpp
    gsoap-onvif/onvif/soapClient.cpp
    gsoap-onvif/onvif/wsdd.nsmap
    )
set(Onvifobj
    #gsoap-onvif/OnvifPTZ.cpp
    #gsoap-onvif/OnvifImaging.cpp
    onvifdevice.cpp
    )

#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdlib/linux)
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdlib/armeabi-v7a/openssl)
add_executable(client main.cpp ${ProxyOBJ} ${PluginOBJ} ${Onvifobj})
target_link_libraries(client ssl crypto)
#add_library(onvifdevice STATIC onvifdevice.cpp ${ProxyOBJ} ${PluginOBJ} ${Onvifobj})
#target_link_libraries(onvifdevice ssl crypto)

#set_target_properties(onvifdevice PROPERTIES OUTPUT_NAME "onvifdevice")
#install(TARGETS onvifdevice DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build)     
