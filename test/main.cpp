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

#include <gtest/gtest.h>

/**
 * @brief Main for testing
 * @param argc no of argumnets 
 * @param argv char pointer consisting arguments 
 * @return RUN_ALL_TESTS()
 */
int main(int argc, char** argv) {
::testing::InitGoogleTest(&argc, argv);

/**
*   @brief Initializing and naming a node
*/
ros::init(argc, argv, "tester");
return RUN_ALL_TESTS();
}
