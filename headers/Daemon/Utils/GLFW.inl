/**
 * MIT License
 *
 * Copyright (c) 2018 InfiernoGamesStudio
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

#ifndef _DAEMON_GLFW_HPP_
#define _DAEMON_GLFW_HPP_

  namespace GLFW {

    /**
     * CreateGameWindow function
     * @note : Setup and create the GLFW game window.
     * @param width[ in ] : Width of the game window.
     * @param height[ in ] :Height of the game window.
     * @param title[ in ] : Title of the game window.
     * @param window : Pointer use to hold the new GLFW window instance.
     * @return : GLFWwindow*
     **/
    inline GLFWwindow* CreateGameWindow( int width, int height, const char* title, GLFWwindow* window = nullptr ) {
      // Setup GLFW window
      glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
      glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
      glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
      glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
      glfwWindowHint( GLFW_DOUBLEBUFFER, GL_TRUE );
      glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );

      // Create the GLFW window
      window = glfwCreateWindow( width, height, title, nullptr, nullptr );
      if ( !window ) {
        glfwTerminate( );
        printf( "[ ERROR ] Can't create GLFW game window !\n" );
        exit( -1 );
      }

      return window;
    };

    /**
     * Cleanup method
     * @note : Cleanup GLFW.
     * @param window[ in ] : Current GLFW window.
     **/
    inline void Cleanup( GLFWwindow* window ) {
      glfwDestroyWindow( window );
      glfwTerminate( );
    };

  };

#endif
