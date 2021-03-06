#include "../../headers/KnightScript.hpp"
#include "../../headers/Daemon/Daemon.hpp"
#include "../../headers/Daemon/GameContentManager.hpp"
#include "../../headers/Daemon/GameEngine.hpp"
#include "../../headers/Daemon/Utils/GLFW.inl"

struct Daemon::GameEngine* Daemon::CreateEngine( std::string config_file, struct Daemon::GameEngine* engine ) {
  engine = ( struct Daemon::GameEngine* )malloc( sizeof( struct Daemon::GameEngine ) );

  if ( engine ) {
    std::ifstream loader = std::ifstream( config_file );

    while ( true ) {
      loader >> config_file;

      if ( !loader.eof( ) ) {
        if ( config_file == "#name" ) {
          getline( loader, config_file, '\n' );
          engine->name = config_file + " - Daemon Engine";
        } else if ( config_file == "#author" ) {
          getline( loader, config_file, '\n' );
          engine->author = config_file;
        } else if ( config_file == "#version" ) {
          getline( loader, config_file, '\n' );
          engine->version = config_file;
        } else if ( config_file == "#screen" ) {
          loader >> engine->screen.width;
          loader >> engine->screen.height;
          engine->screen.ratio = (float)engine->screen.width / (float)engine->screen.height;
        } else if ( config_file == "#content" ) {
          getline( loader, config_file, '\n' );
          engine->content_path = config_file.erase( 0, 1 );
        } else if ( config_file == "#script" ) {
          getline( loader, config_file, '\n' );
          engine->script_path = config_file.erase( 0, 1 );
        }
      } else
        break;
    }

    loader.close( );
  }

  return engine;
}

void Daemon::InitEngine( struct Daemon::GameEngine* engine ) {
  // Setup GLFW
  if ( !glfwInit( ) ) {
    printf( "[ ERROR ] Can't initialize GLFW !\n" );
    exit( -1 );
  }

  // Create game window
  engine->window = GLFW::CreateGameWindow( engine->screen.width, engine->screen.height, engine->name.c_str( ) );

  // Setup GLFW for GL
  glfwSwapInterval( GL_TRUE );
  glfwMakeContextCurrent( engine->window );

  // Setup GLEW for GL
  glewExperimental = GL_TRUE;
  if ( glewInit( ) != GLEW_OK ) {
    GLFW::Cleanup( engine->window );
    printf( "[ ERROR ] Can't initialize GLEW !\n" );
    exit( -1 );
  }

  Daemon::InitContentManager( engine );
}

void Daemon::AwakeEngine( struct Daemon::GameEngine* engine ) {
  Daemon::LoadAsset( engine, Daemon::TEXTURE, "Textures/tileset.ttr" );
  Daemon::LoadAsset( engine, Daemon::MESH, "Meshes/plane.mesh" );

  Daemon::GenerateModel( engine );
}

void Daemon::ProcessEngine( struct Daemon::GameEngine* engine ) {
}

void Daemon::DestroyEngine( struct Daemon::GameEngine* engine ) {
  if ( engine ) {
    Daemon::ClearContentManager( engine );
    GLFW::Cleanup( engine->window );
    DELETE_PTR( engine )
  }
}
