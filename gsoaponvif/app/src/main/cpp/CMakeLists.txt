cmake_minimum_required(VERSION 3.4.1)
project(gsoap-onvif)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o0 -g -ggdb -Wall -w -fPIC -fno-use-cxa-atexit -fexceptions")
add_definitions(-DWITH_NONAMESPACES -DWITH_DOM -DWITH_OPENSSL -DSOAP_DEBUG)
set(3rdlib_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs)

#add_library(libssl SHARED IMPORTED)
#set_target_properties(libssl PROPERTIES IMPORTED_LOCATION
#        ${3rdlib_DIR}/armeabi-v7a)
#add_library(libcrypto SHARED IMPORTED)
#set_target_properties(libcrypto PROPERTIES IMPORTED_LOCATION
#        ${3rdlib_DIR}/armeabi-v7a)

include_directories(gsoap-onvif/onvif
        gsoap-onvif/proxy/include
        gsoap-onvif/plugin
        gsoap-onvif/proxy
        gsoap-onvif
        ${CMAKE_CURRENT_SOURCE_DIR})

#openssl
set(ssl-cpp gsoap-onvif/sslcpp/p_lib.c
        gsoap-onvif/sslcpp/x509_cmp.c
        gsoap-onvif/sslcpp/x509_lu.c
        gsoap-onvif/sslcpp/x_x509.c
        gsoap-onvif/sslcpp/x509_vfy.c
        gsoap-onvif/sslcpp/x509_obj.c
        gsoap-onvif/sslcpp/by_file.c
        gsoap-onvif/sslcpp/x509_d2.c
        gsoap-onvif/sslcpp/pem_pkey.c
        )

#框架源码
set(gsoap-cpp gsoap-onvif/plugin/dom.cpp
        gsoap-onvif/plugin/duration.cpp
        gsoap-onvif/plugin/mecevp.cpp
        gsoap-onvif/plugin/smdevp.cpp
        gsoap-onvif/plugin/stdsoap2.cpp
        gsoap-onvif/plugin/threads.cpp
        gsoap-onvif/plugin/wsaapi.cpp
        gsoap-onvif/plugin/wsseapi.cpp)

#功能源码
set(onvif-cpp gsoap-onvif/onvif/soapC.cpp
        gsoap-onvif/onvif/soapClient.cpp
        gsoap-onvif/proxy/src/soapDeviceBindingProxy.cpp
        gsoap-onvif/proxy/src/soapMediaBindingProxy.cpp
        gsoap-onvif/proxy/src/soapPTZBindingProxy.cpp
        gsoap-onvif/proxy/src/soapPullPointSubscriptionBindingProxy.cpp
        gsoap-onvif/proxy/src/soapRemoteDiscoveryBindingProxy.cpp)

#添加所有cpp文件，包括自己实现的cpp
add_library( native-lib
             SHARED
             ${ssl-cpp}
             ${gsoap-cpp}
             ${onvif-cpp}
             soapPrint.cpp
             onvifdevice.cpp
             native-lib.cpp )

find_library( log-lib log )
target_link_libraries( native-lib
                       #libssl
                       #libcrypto
                       ${log-lib})