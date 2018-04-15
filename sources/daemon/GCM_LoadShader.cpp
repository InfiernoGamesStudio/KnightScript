#include "../../headers/KnightScript.hpp"
#include "../../headers/Daemon/Daemon.hpp"
#include "../../headers/Daemon/GameContentManager.hpp"
#include "../../headers/Daemon/Graphics/GameShader.hpp"

void Daemon::LoadShader( struct Daemon::GameContentManager* content_manager, std::string path ) {
  if ( content_manager->shaders.Find( path ) == 0 ) {
    struct Daemon::GameShader* shader = content_manager->shaders.Push( path );
  } else
    printf( "[ ERROR ] Shader : %s already loaded !\n", path.c_str( ) );
}
