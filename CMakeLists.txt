#[[
MIT License
Copyright © 2019 Raj Shinde
Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the “Software”), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:
The above copyright notice and this permission notice shall be included 
in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
 ]]
 
cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  tf
  roscpp
  rospy
  std_msgs
  message_generation
)

## Generate services in the 'srv' folder
add_service_files(
   FILES
   serviceString.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
)

## Your package locations should be listed before other locations
include_directories(
#  include
  ${catkin_INCLUDE_DIRS}
)


add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})


add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
