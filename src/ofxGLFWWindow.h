// ofxGLFWWindow
//
// Creates a secondary window with start() and end() functions to allow drawing
// from within the main draw function in openFrameworks.
//
// Requires openFrameworks to be using GLFW windows (ofAppGLFWWindow). This method
// is probably not thread safe.
//
// This class is written for the development version of openFrameworks 0.8.0, and 
// should be obsoleted by a more thoroughly designed multi-window interface some time.
//

#pragma once

#include "GLFW/glfw3.h"

class ofxGLFWWindow {
	public:
		ofxGLFWWindow();
		~ofxGLFWWindow();

		// void setFullscreen(bool b);
		// void toggleFullscreen();

		int getWidth();
		int getHeight();

		// Get first monitor which is not the primary monitor. Returns NULL 
		// if number of monitors available is less than two.
		static GLFWmonitor* glfwGetSecondaryMonitor();

		void start();
		void end();
	private:
		GLFWwindow* window;
		GLFWwindow* savecontext;

		int w,h;

		bool begin_is_next = true;
};