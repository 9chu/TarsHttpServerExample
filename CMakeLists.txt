cmake_minimum_required(VERSION 3.0)
project(TarsHttpServerExample)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(3rd/TarsServant)

# MySQL
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/3rd/TarsServant/cmake/")
#find_package(MySQL REQUIRED)
#link_directories(${MYSQL_LIB_DIR})

add_executable(TarsHttpServerExample src/Main.cpp src/App.cpp src/HttpServant.cpp)
target_link_libraries(TarsHttpServerExample tarsutil tarsservant)
#target_link_libraries(TarsHttpServerExample ${MYSQL_LIBRARIES})

tars_generate_tar(TarsHttpServerExample)
tars_upload_tar("http://192.168.255.2:8080" test TarsHttpServerExample)
tars_auto_deploy_tar("http://192.168.255.2:8080" test TarsHttpServerExample)
