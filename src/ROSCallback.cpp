#include "ros/ros.h"
#include "rosmaze/MazeController.h"
#include "ROSCallback.h"

bool ROSCallback::ROSValidDir(rosmaze::MazeController::Request &req, rosmaze::MazeController::Response &res)
{
    // request is a string (direction)
    // responce is a string (result)
    res.result = 0;
    ROS_INFO("request: %d", (int)req.direction);
    ROS_INFO("sending back response: %d", (int)res.result);
    serviceDir = req.direction;
    
    return true;
}

