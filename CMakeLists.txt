cmake_minimum_required(VERSION 3.10)
project(ONVIF_CLEINT)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o0 -g -ggdb -Wall -w -fPIC -fno-use-cxa-atexit -fexceptions")
add_definitions(-DWITH_NONAMESPACES -DWITH_DOM -DWITH_OPENSSL -DWITH_COOKIES)

include_directories(${PROJECT_SOURCE_DIR}/
                    ${PROJECT_SOURCE_DIR}/proxy/include
                    ${PROJECT_SOURCE_DIR}/onvif
                    ${PROJECT_SOURCE_DIR}/plugin
                 )
set(ProxyOBJ proxy/src/soapDeviceBindingProxy.cpp
    proxy/src/soapMediaBindingProxy.cpp
    proxy/src/soapPTZBindingProxy.cpp
    proxy/src/soapPullPointSubscriptionBindingProxy.cpp
    proxy/src/soapRemoteDiscoveryBindingProxy.cpp
    )
set(PluginOBJ
    plugin/wsaapi.cpp
    plugin/wsseapi.cpp
    plugin/threads.cpp
    plugin/duration.cpp
    plugin/smdevp.cpp
    plugin/mecevp.cpp
    plugin/dom.cpp
    plugin/stdsoap2.cpp
    )
set(Onvifobj
    onvif/soapC.cpp
    onvif/soapClient.cpp
    onvif/wsdd.nsmap
    )
add_executable(client proxy/main.cpp proxy/onvifdevice.cpp 
	        proxy/onvifcomm.cpp ${ProxyOBJ} ${PluginOBJ} ${Onvifobj})
target_link_libraries(client ssl crypto avcodec avformat avutil swscale)
