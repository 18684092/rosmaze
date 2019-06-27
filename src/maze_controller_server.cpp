/*

Author: Andy Perrett June 2019
Course: BSc Computer Science Level 1

*/

// My classes
#include "RecursiveBackTracker.h"
#include "ROSCallback.h"

// ROS 
#include "ros/ros.h"
#include "rosmaze/MazeController.h"

bool R(rosmaze::MazeController::Request &req, rosmaze::MazeController::Response &res)
{
    // request is a int (direction)
    // responce is a int (result)
    res.result = 1;
    ROS_INFO("request: %d", (int)req.direction);
    ROS_INFO("sending back response: %d", (int)res.result);
    return true;
}

int main(int argc, char **argv)
{
    
    ros::init(argc, argv, "maze_controller_server");
    // Set up size of maze y, x - needs to fit into screen 13 x 17 good for 640 by 480
    RecursiveBackTracker BT(13,17);

    // Display it using SDL2 library
    BT.DisplayMaze();

    return 0;
}


