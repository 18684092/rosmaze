#include "ros/ros.h"
#include "GamePad.h"
#include "rosmaze/JoyMsg.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "joy_client");
    

	joystick e;
	GamePad JoyStick;
	while(true)
	{
		e = JoyStick.ReadDevice(1);
		std::cout << "X1 : " << e.x1Value << std::endl;
		std::cout << "Y1 : " << e.y1Value << std::endl;
		std::cout << "X2 : " << e.x2Value << std::endl;
		std::cout << "Y2 : " << e.y2Value << std::endl;
		// how many buttons
		for (int b = 0; b < 12; b++)
		{
	    		std::cout << "Button : " << b << " - " << e.button[b] << std::endl;
		}
		std::cout << "Compass : " << e.Compass << std::endl;

		ros::NodeHandle n;
		ros::ServiceClient client = n.serviceClient<rosmaze::JoyMsg>("andy_joystick");
		rosmaze::JoyMsg JoySrv;
		
		// Set x, y, z axis info
		JoySrv.request.x = e.x1Value;
		JoySrv.request.y = e.y1Value;
		JoySrv.request.z = 1;

		// joy_receiver needs to be running

		if (client.call(JoySrv))
		{
			ROS_INFO("andy_joystick feedback: %d\r", JoySrv.response.feedback);
		}
		else
		{
			ROS_ERROR("Failed to call service");
			return 1;
		}

	}
return 0;
}
