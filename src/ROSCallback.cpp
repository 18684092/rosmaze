#include "ros/ros.h"
#include "rosmaze/MazeController.h"
#include "rosmaze/JoyMsg.h"
#include "ROSCallback.h"

bool ROSCallback::ROSValidDir(rosmaze::MazeController::Request &req, rosmaze::MazeController::Response &res)
{
    // request is a int64 (direction)
    // responce is a int64 (result)
    res.result = 0;
    ROS_INFO("request: %d", (int)req.direction);
    ROS_INFO("sending back response: %d", (int)res.result);
    serviceDir = req.direction;
    
    return true;
}

bool ROSCallback::ROSJoyVector(rosmaze::JoyMsg::Request &req, rosmaze::JoyMsg::Response &res)
{
	res.feedback = 0;
	ROS_INFO("request: %f", req.x);
	ROS_INFO("request: %f", req.y);
	ROS_INFO("request: %f", req.z);
	ROS_INFO("sending back response: %d", (int)res.feedback);
	vectorJoy.x = req.x;
	vectorJoy.y = req.y;
	vectorJoy.z = req.z;

	return true;
}

