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

#include "../../headers/KnightScript.hpp"
#include "../../headers/Daemon/Daemon.hpp"
#include "../../headers/Daemon/GameContentManager.hpp"
#include "../../headers/Daemon/GameEngine.hpp"

int main( int argc, char** argv ) {
  struct Daemon::GameEngine* engine = Daemon::CreateEngine( argv[ 1 ] );
  Daemon::PrintInfo( engine );

  if ( engine ) {
    Daemon::InitEngine( engine );
    Daemon::AwakeEngine( engine );

    // Main game loop.
    float game_time = 0.0f;
    while ( !glfwWindowShouldClose( engine->window ) ) {
      game_time = (float)glfwGetTime( );

      Daemon::ProcessEngine( engine );

      glfwSwapBuffers( engine->window );
      glfwPollEvents( );
    }
    
    Daemon::DestroyEngine( engine );
  } else {
    printf( "[ ERROR ] Can't setup the game engine !\n" );
    printf( "[ INFO ] Check the kfc file of the game !\n" );
    printf( "[ INFO ] Path of the current kgc file : %s\n", argv[ 1 ] );
    return -1;
  }

  return 0;
}
