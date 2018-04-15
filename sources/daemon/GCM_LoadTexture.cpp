#include "../../headers/KnightScript.hpp"
#include "../../headers/Daemon/Daemon.hpp"
#include "../../headers/Daemon/GameContentManager.hpp"
#include "../../headers/Daemon/Graphics/GameTexture.hpp"

void Daemon::LoadTexture( struct Daemon::GameContentManager* content_manager, std::string path ) {
  if ( content_manager->textures.Find( path ) == 0 ) {
    struct Daemon::GameTexture* texture = content_manager->textures.Push( path );
  } else
    printf( "[ ERROR ] Texture : %s already loaded !\n", path.c_str( ) );
}
