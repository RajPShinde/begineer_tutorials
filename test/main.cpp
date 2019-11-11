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
 *  @file    main.cpp
 *  @author  Raj Shinde
 *  @date    11/10/2019
 *  @version 1.0
 *  @brief   Main for testing
 *  @section DESCRIPTION
 *  All the test are run
 */
#include <ros/ros.h>
#include <gtest/gtest.h>

/**
 * @brief Main for testing
 * @param argc no of argumnets 
 * @param argv char pointer consisting arguments 
 * @return RUN_ALL_TESTS()
 */
int main(int argc, char** argv) {
::testing::InitGoogleTest(&argc, argv);

// Initializing and naming a node
ros::init(argc, argv, "tester");
return RUN_ALL_TESTS();
}
