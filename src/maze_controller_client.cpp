#include "ros/ros.h"
#include "ros_maze/MazeController.h"
#include "std_msgs/String.h"
#include <ncurses.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
ros::init(argc, argv, "maze_controller_client");
 initscr();
cbreak();
 noecho();
 int c = 0;
string s;
string d;
printw("Waiting for key press (num lock should be on)\r" );
 while( true)
 {
    c = getch();
    switch(c)
        {
            case 56:
                s = "North";
                d = "n";
                break;
            case 57:
                s = "North East";
                d = "ne";
                break;
            case 54:
                s = "East";
                d = "e";
                break;
            case 51:
                s = "South East";
                d = "se";
                break;
            case 50:
                s = "South";
                d = "s";
                break;
            case 49:
                s = "South West";
                d = "sw";
                break;
            case 52:
                s = "West";
                d = "w";
                break;
            case 55:
                s = "North West";
                d = "nw";
                break;
            default:
                s = "*not valid*";
                d = "nothing";
        }
    std::cout << "The direction selected is " << s << " :: \"" << d << "\" will be sent to the service\r" << std::endl;
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<ros_maze::MazeController>("maze_controller");
    ros_maze::MazeController srv;
    srv.request.direction = s;
    if (client.call(srv))
    {
        ROS_INFO("Result: %s", srv.response.result);
    }
    else
    {
        ROS_ERROR("Failed to call service ");
    }

    s = "";
    d = "";

 }
 endwin();

 return 0;
}
