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
*   @brief A unit test to check the talker
*   
*/
TEST(Talker, testService) {
ros::NodeHandle n;
ros::ServiceClient client = n.serviceClient<beginner_tutorials::serviceString>("service_string");
beginner_tutorials::serviceString srv;
srv.request.s = "Check!!";
client.call(srv);
EXPECT_STREQ(srv.response.sChanged.c_str(), "Check!!");
}

TEST(Talker, testTf) {
ros::NodeHandle n;
tf::TransformListener listener;
tf::StampedTransform transform;
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
  EXPECT_NEAR(0, transform.getOrigin().x(), 1);
  EXPECT_NEAR(7, transform.getOrigin().y(), 1);
  EXPECT_NEAR(-6, transform.getOrigin().z(), 1);
}


