/*

Author: Andy Perrett June 2019
Course: BSc Computer Science Level 1

*/

// My classes
#include "RecursiveBackTracker.h"

// ROS 
#include "ros/ros.h"
#include "rosmaze/MazeController.h"

bool R(rosmaze::MazeController::Request &req, rosmaze::MazeController::Response &res)
{
    // request is a string (direction)
    // responce is a string (result)
    res.result = "I heard you";
    ROS_INFO("request: %s", (std::string)req.direction);
    ROS_INFO("sending back response: %s", (std::string)res.result);
    return true;
}

int main(int argc, char **argv)
{
    
    ros::init(argc, argv, "maze_controller_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("controller", R);
    ROS_INFO("Ready to serve.");
    ros::spin();
    // Set up size of maze y, x - needs to fit into screen 13 x 17 good for 640 by 480
    //RecursiveBackTracker BT(13,17);

    // Display it using SDL2 library
    //BT.DisplayMaze();

    return 0;
}


