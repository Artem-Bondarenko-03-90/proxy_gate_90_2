# Install script for directory: F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/examples

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_simple/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_basic_io/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_password_auth/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_write_handler/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_control/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_dynamic/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_config_file/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_complex_array/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_threadless/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_61400_25/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_setting_groups/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_logging/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_files/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_substitution/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_service_tracking/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_deadband/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/server_example_access_control/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example1/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example2/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example_control/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example4/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example5/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example_reporting/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example_log/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example_array/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example_files/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example_async/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_file_async/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example_rcbAsync/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example_ClientGooseControl/cmake_install.cmake")
  include("F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/iec61850_client_example_ClientGooseControlAsync/cmake_install.cmake")

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "F:/RTSoft/Code/proxy_gate_90_2/libiec61850_full/build/examples/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
