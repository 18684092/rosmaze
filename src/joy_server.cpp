/*

Author: Andy Perrett June 2019
Course: BSc Computer Science Level 1

*/

#include "ros/ros.h"

#include <iostream>
#include <wiringPi.h>
#include <unistd.h> // usleep

// My classes
#include "ROSCallback.h"

void east();
void west();
void north();
void south();
void stop();
void northEast();
void southEast();
void northWest();
void southWest();

//make global variables to store the wiring pi pin numbers for the motors
int m1a = 0;
int m1b = 1;
int m2a = 3;
int m2b = 4;


int main(int argc, char **argv)
{
	// Joystick sensitivity
	int SENSITIVITY = 5000;

	// Init motor controller
	wiringPiSetup();
	pinMode(m1a, OUTPUT);
	pinMode(m1b, OUTPUT);
	pinMode(m2a, OUTPUT);
	pinMode(m2b, OUTPUT);

	// Initialise ROS
	ros::init(argc, argv, "joy_server");
	ros::NodeHandle node;
	ros::ServiceServer server;

	// This is a wrapper class so we can access the received parameters
	// ROSCallback.vectorJoy is the direction variable received
	ROSCallback RC;

	// Run the ROSS service with callback
	server = node.advertiseService("andy_joystick", &ROSCallback::ROSJoyVector, &RC);

	ROS_INFO("Ready to serve.....");

	while (true)
	{
	        // listen for remote key presses
                ros::spinOnce();
		if (RC.vectorJoy.x != 0.0f || RC.vectorJoy.y != 0.0f)
		{
			if ((RC.vectorJoy.x > SENSITIVITY) && (RC.vectorJoy.y < SENSITIVITY && RC.vectorJoy.y > -SENSITIVITY)) east();
    			else if ((RC.vectorJoy.x < -SENSITIVITY) && (RC.vectorJoy.y < SENSITIVITY && RC.vectorJoy.y > -SENSITIVITY)) west();
    			else if ((RC.vectorJoy.x < SENSITIVITY) && (RC.vectorJoy.x > -SENSITIVITY) && (RC.vectorJoy.y > SENSITIVITY)) south();
    			else if ((RC.vectorJoy.x < SENSITIVITY) && (RC.vectorJoy.x > -SENSITIVITY) && (RC.vectorJoy.y < -SENSITIVITY)) north();
    			else if ((RC.vectorJoy.x > SENSITIVITY) && (RC.vectorJoy.y < -SENSITIVITY)) northEast();
    			else if ((RC.vectorJoy.x < -SENSITIVITY) && (RC.vectorJoy.y < -SENSITIVITY)) northWest();
			else if ((RC.vectorJoy.x < -SENSITIVITY) && (RC.vectorJoy.y > SENSITIVITY)) southWest();
    			else if ((RC.vectorJoy.x > SENSITIVITY) && (RC.vectorJoy.y > SENSITIVITY)) southEast();
			stop();
		}

		// reset direction
		RC.vectorJoy.x = 0.0f;
		RC.vectorJoy.y = 0.0f;
		RC.vectorJoy.z = 0.0f;
	}

	return 0;
}

void north()
{
	digitalWrite(m1a, HIGH);
	digitalWrite(m1b, LOW);
	digitalWrite(m2a, HIGH);
	digitalWrite(m2b, LOW);
	usleep(1000000);
}

//all motors off
void stop()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}

//Make both motors turn backwards
void south()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
	usleep(1000000);
}

//Make motors turn fwd, bak
void west()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
	usleep(500000);
}

//Make motors turn fwd, bak
void east()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
usleep(500000);
}

void northEast()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
	usleep(250000);
}

void southEast()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
	usleep(750000);
}

void northWest()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
	usleep(250000);
}

void southWest()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
	usleep(750000);
}

