#include "../../headers/KnightScript.hpp"
#include "../../headers/Daemon/Daemon.hpp"
#include "../../headers/Daemon/GameContentManager.hpp"
#include "../../headers/Daemon/Graphics/GameMesh.hpp"
#include "../../headers/Daemon/Graphics/GameModel.hpp"
#include "../../headers/Daemon/Graphics/GameShader.hpp"
#include "../../headers/Daemon/Graphics/GameTexture.hpp"

struct Daemon::GameContentManager* Daemon::CreateContentManager( struct Daemon::GameContentManager* content_manager ) {
  content_manager = ( struct Daemon::GameContentManager* )malloc( sizeof( struct Daemon::GameContentManager ) );

  if ( content_manager ) {
  }

  return content_manager;
}

bool Daemon::LoadContent( struct Daemon::GameContentManager* content_manager, enum Daemon::EContentTypes type, std::string path ) {
  if ( content_manager ) {
    switch ( type ) {
      // Load a game texture.
      case Daemon::TEXTURE_BMP : break;
      case Daemon::TEXTURE_PNG : break;
      case Daemon::TEXTURE_JPG : break;
      case Daemon::TEXTURE_TGA : break;

      // Load a game shader.
      case Daemon::SHADER : break;

      // Load a game mesh.
      case Daemon::MESH : break;

      default :
        printf( "[ WARNING ] Can't load : %s !\n", path.c_str( ) );
        return false;
    }
  }

  return true;
}

void Daemon::DestroyContentManager( struct Daemon::GameContentManager* content_manager ) {
  if ( content_manager ) {
    DELETE_PTR( content_manager );
  }
}
