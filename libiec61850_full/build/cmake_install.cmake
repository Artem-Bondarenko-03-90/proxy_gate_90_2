# Install script for directory: F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/libiec61850")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libiec61850" TYPE FILE FILES
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/hal/inc/hal_base.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/hal/inc/hal_time.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/hal/inc/hal_thread.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/hal/inc/hal_filesystem.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/hal/inc/hal_ethernet.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/hal/inc/hal_socket.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/hal/inc/tls_config.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/hal/inc/tls_ciphers.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/common/inc/libiec61850_common_api.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/common/inc/linked_list.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/common/inc/sntp_client.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/iec61850/inc/iec61850_client.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/iec61850/inc/iec61850_common.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/iec61850/inc/iec61850_server.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/iec61850/inc/iec61850_model.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/iec61850/inc/iec61850_cdc.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/iec61850/inc/iec61850_dynamic_model.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/iec61850/inc/iec61850_config_file_parser.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/mms/inc/mms_value.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/mms/inc/mms_common.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/mms/inc/mms_types.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/mms/inc/mms_type_spec.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/mms/inc/mms_client_connection.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/mms/inc/mms_server.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/mms/inc/iso_connection_parameters.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/goose/goose_subscriber.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/goose/goose_receiver.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/goose/goose_publisher.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/sampled_values/sv_subscriber.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/sampled_values/sv_publisher.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/r_session/r_session.h"
    "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/src/logging/logging_api.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES
    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Redist/MSVC/14.44.35112/x64/Microsoft.VC143.CRT/msvcp140.dll"
    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Redist/MSVC/14.44.35112/x64/Microsoft.VC143.CRT/msvcp140_1.dll"
    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Redist/MSVC/14.44.35112/x64/Microsoft.VC143.CRT/msvcp140_2.dll"
    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Redist/MSVC/14.44.35112/x64/Microsoft.VC143.CRT/msvcp140_atomic_wait.dll"
    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Redist/MSVC/14.44.35112/x64/Microsoft.VC143.CRT/msvcp140_codecvt_ids.dll"
    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Redist/MSVC/14.44.35112/x64/Microsoft.VC143.CRT/vcruntime140_1.dll"
    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Redist/MSVC/14.44.35112/x64/Microsoft.VC143.CRT/vcruntime140.dll"
    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Redist/MSVC/14.44.35112/x64/Microsoft.VC143.CRT/concrt140.dll"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE DIRECTORY FILES "")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/hal/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/src/cmake_install.cmake")

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
