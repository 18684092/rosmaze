/*

Author: Andy Perrett June 2019
Course: BSc Computer Science Level 1

*/

#ifndef RECURSIVEBACKTRACKER_H
#define RECURSIVEBACKTRACKER_H

// ROS 
#include "ros/ros.h"
#include "rosmaze/MazeController.h"

// Standard objects
#include <string>
#include <map>

// My Classes
#include "Location.h"
#include "Place.h"
#include "Stack.h"

// Installed (sudo dnf install sdl2-devel on Fedora 30)
#include "SDL2/SDL.h"


using namespace std;

class RecursiveBackTracker
{
    public:
	ros::NodeHandle node;
	ros::ServiceServer server;
	

        RecursiveBackTracker(int, int);
        uint8_t GetDoors(Place);
        void SetDoors(Place, uint8_t);
        void SetDoor(Place, string);
        bool IsDoor(Place, string);
        uint8_t GetUnvisitedNeighbours(Place);
        string GetRandomNeighbour(uint8_t neighbours);
        void DisplayMaze();
	//static bool ROSValidDir(rosmaze::MazeController::Request &, rosmaze::MazeController::Response &);
        Place _GetNewPlace(Place, string);


    protected:

    private:
        // Array of World with maximum size
        Location _World[100][100];
        int _MaxX;
        int _MaxY;
        // Create a blank world
        void _CreateBlankWorld(int, int);
        void _CreateMaze(Stack, int);
        void DrawOctagon(SDL_Renderer *, int, int, int, int);
        void DrawLineN(SDL_Renderer *, int, int);
        void DrawLineNE(SDL_Renderer *, int, int);
        void DrawLineE(SDL_Renderer *, int, int);
        void DrawLineSE(SDL_Renderer *, int, int);
        void DrawLineS(SDL_Renderer *, int, int);
        void DrawLineSW(SDL_Renderer *, int, int);
        void DrawLineW(SDL_Renderer *, int, int);
        void DrawLineNW(SDL_Renderer *, int, int);
        void DrawMarker(SDL_Renderer *, int, int);
        void DrawArrows(SDL_Renderer *, int, int);
        void DrawSmallDot(SDL_Renderer *, int, int);
	void ProcessKeyBD(int &, int &, int, int);
	
        // Direction bitmap
        map<string, uint8_t> _Dir = {{"n",128}, {"ne",64}, {"e",32}, {"se",16}, {"s",8}, {"sw",4}, {"w",2}, {"nw",1}};
        // Mirror the directions (opposites) ie, n == s, se == nw etc
        map<string, uint8_t> _OpDir = {{"s",128}, {"sw",64}, {"w",32}, {"nw",16}, {"n",8}, {"ne",4}, {"e",2}, {"se",1}};

        // Compass strings
        string _Compass[8] = {"nw", "w", "sw", "s", "se", "e", "ne", "n"};

	// Key map         0  sw  s   se  w   0  e   nw  n   ne
	int _keyMap[10] = {0, SDLK_KP_1, SDLK_KP_2, SDLK_KP_3, SDLK_KP_4, 0, SDLK_KP_6, SDLK_KP_7, SDLK_KP_8, SDLK_KP_9};

        //Screen dimension constants
        const int SCREEN_WIDTH = 620;
        const int SCREEN_HEIGHT = 480;
};

#endif // RECURSIVEBACKTRACKER_H
