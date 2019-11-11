/***************************************************************************
 MIT License

 Copyright © 2019 Raj Shinde
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 Files (the “Software”), to deal in the Software without restriction,
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
 ***************************************************************************/

/**
 *  @copyright MIT License, © 2019 Raj Shinde
 *  @file    testTalker.cpp
 *  @author  Raj Shinde
 *  @date    11/10/2019
 *  @version 1.0
 *  @brief   Tests for talker.cpp
 *  @section DESCRIPTION
 *  Test are written for talker node 
 */

#include <gtest/gtest.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <ros/service_client.h>
#include <std_msgs/String.h>

#include "beginner_tutorials/serviceString.h"

/**
*   @brief A unit test to check that the talker
*   string service works correctly
*/
TEST(Talker, testService) {
// Creating a node handler n
ros::NodeHandle n;

// Created an object client to use test the service string
ros::ServiceClient client =
n.serviceClient<beginner_tutorials::serviceString>("service_string");
beginner_tutorials::serviceString srv;
srv.request.s = "Check!!";

// Call the service
client.call(srv);

// Compare the expected and actual string
EXPECT_STREQ(srv.response.sChanged.c_str(), "Check!!");
}

/**
*   @brief A unit test to check the Broadcasted
*   frames offset
*/
TEST(Talker, testTf) {
// Creating a node handler n
ros::NodeHandle n;

// Creating Objects
tf::TransformListener listener;
tf::StampedTransform transform;

// Listen for a tf broadcast
  while (ros::ok()) {
    try {
      listener.lookupTransform("/talk", "/world", ros::Time(0), transform);
      break;
    }
    catch (tf::TransformException &ex) {
        ROS_ERROR("%s", ex.what());
        ros::Duration(1.0).sleep();
        continue;
    }
  }

  // Compare the expected and actual transform value
  EXPECT_NEAR(0, transform.getOrigin().x(), 1);
  EXPECT_NEAR(7, transform.getOrigin().y(), 1);
  EXPECT_NEAR(-6, transform.getOrigin().z(), 1);
}


