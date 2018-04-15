#include "../../headers/KnightScript.hpp"
#include "../../headers/Daemon/Daemon.hpp"
#include "../../headers/Daemon/GameContentManager.hpp"
#include "../../headers/Daemon/GameEngine.hpp"
#include "../../headers/Daemon/Graphics/GameMesh.hpp"
#include "../../headers/Daemon/Graphics/GameModel.hpp"
#include "../../headers/Daemon/Graphics/GameShader.hpp"
#include "../../headers/Daemon/Graphics/GameTexture.hpp"

void Daemon::InitContentManager( struct Daemon::GameEngine* engine ) {
  if ( engine ) {
    engine->content_manager.textures = Daemon::GameManager< struct Daemon::GameTexture >( Daemon::DestroyTexture );
    engine->content_manager.shaders = Daemon::GameManager< struct Daemon::GameShader >( Daemon::DestroyShader );
    engine->content_manager.meshes = Daemon::GameManager< struct Daemon::GameMesh >( Daemon::DestroyMesh );
    engine->content_manager.models = std::vector< struct Daemon::GameModel >( );
  }
}

void Daemon::LoadTexture( struct Daemon::GameContentManager* content_manager, std::string path ) {
  if ( content_manager->textures.find( path ) == 0 ) {
  } else
    printf( "[ ERROR ] Texture : %s already loaded !\n", path.c_str( ) );
}

void Daemon::LoadShader( struct Daemon::GameContentManager* content_manager, std::string path ) {
  if ( content_manager->shaders.find( path ) == 0 ) {
  } else
    printf( "[ ERROR ] Shader : %s already loaded !\n", path.c_str( ) );
}

void Daemon::LoadMesh( struct Daemon::GameContentManager* content_manager, std::string path ) {
  if ( content_manager->meshes.find( path ) == 0 ) {
  } else
    printf( "[ ERROR ] Mesh : %s already loaded !\n", path.c_str( ) );
}

bool Daemon::LoadContent( struct Daemon::GameEngine* engine, enum Daemon::EContentTypes type, std::string path ) {
  if ( engine ) {
    std::string _path = engine->content_path + path;

    switch ( type ) {
      case Daemon::TEXTURE : Daemon::LoadTexture( MAKE_PTR( engine->content_manager ), path ); return true;
      case Daemon::SHADER  : Daemon::LoadShader( MAKE_PTR( engine->content_manager ), _path ); return true;
      case Daemon::MESH    : Daemon::LoadMesh( MAKE_PTR( engine->content_manager ), _path ); return true;

      default :
        printf( "[ WARNNING ] Can't load : %s !\n", path.c_str( ) );
        break;
    }
  }

  return false;
}

void Daemon::GenerateModel( struct Daemon::GameEngine* engine ) {
  unsigned int index = 0;
  struct Daemon::GameContentManager* _cm = MAKE_PTR( engine->content_manager );

  while ( index < _cm->meshes.size ) {
    struct Daemon::GameMesh* mesh = _cm->meshes.GetValue( index );
    struct Daemon::GameModel temp = Daemon::MakeModel( mesh );
    _cm->models.push_back( temp );

    index++;
  }
}

struct Daemon::GameModel* Daemon::FindModel( struct Daemon::GameEngine* engine, unsigned int mesh ) {
  if ( mesh < engine->content_manager.model_size )
    return &engine->content_manager.models[ mesh ];

  return nullptr;
}

void Daemon::ClearContentManager( struct Daemon::GameEngine* engine ) {
  if ( engine ) {
    engine->content_manager.textures.~GameManager< struct Daemon::GameTexture >( );
    engine->content_manager.shaders.~GameManager< struct Daemon::GameShader >( );
    engine->content_manager.meshes.~GameManager< struct Daemon::GameMesh >( );

    unsigned int index = 0;
    while ( index < engine->content_manager.models.size( ) ) {
      Daemon::DestroyModel( MAKE_PTR( engine->content_manager.models[ index ] ) );
      index++;
    }

    engine->content_manager.models.~vector< struct Daemon::GameModel >( );
  }
}
