#include "Vector3.h"
#include "rosmaze/JoyMsg.h"
#include "rosmaze/MazeController.h"

class ROSCallback
{
public:
	int serviceDir = 0;
	Vector3 vectorJoy;

	// ROS Services
	bool ROSValidDir(rosmaze::MazeController::Request &, rosmaze::MazeController::Response &);
	bool ROSJoyVector(rosmaze::JoyMsg::Request &, rosmaze::JoyMsg::Response &);
};
