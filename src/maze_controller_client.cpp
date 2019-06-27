#include "ros/ros.h"
#include "rosmaze/MazeController.h"
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
    int d;
    printw("Waiting for key press (num lock should be on)\r" );
    while( true)
    {
        c = getch();
        switch(c)
            {
            case 56:
                s = "North";
                d = 8;
                break;
            case 57:
                s = "North East";
                d = 9;
                break;
            case 54:
                s = "East";
                d = 6;
                break;
            case 51:
                s = "South East";
                d = 3;
                break;
            case 50:
                s = "South";
                d = 2;
                break;
            case 49:
                s = "South West";
                d = 1;
                break;
            case 52:
                s = "West";
                d = 4;
                break;
            case 55:
                s = "North West";
                d = 7;
                break;
            default:
                s = "*not valid*";
                d = 0;
        }
    
        if (d > 0)
        {
            std::cout << "The direction selected is " << s << " :: \"" << d << "\" will be sent to the service\r" << std::endl;
            ros::NodeHandle n;
            ros::ServiceClient client = n.serviceClient<rosmaze::MazeController>("controller");
            rosmaze::MazeController srv;
            srv.request.direction = d;
            
            if (client.call(srv))
            {
                ROS_INFO("Result: %d\r", srv.response.result);
            }
            else
            {
                ROS_ERROR("Failed to call service ");
                return 1;
            }
            
        std::cout << "The result returned from server was " << srv.response.result << "\r" << std::endl;
        }
        else
        {
            std::cout << "The direction selected is " << s << " nothing will be sent to the service\r" << std::endl;
        }
        s = "";
        d = 0;

    }
endwin();
return 0;
}
