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
    engine->content_manager.model_count = ( unsigned int )0;
    engine->content_manager.textures = Daemon::GameManager< struct Daemon::GameTexture >( Daemon::DestroyTexture );
    engine->content_manager.shaders = Daemon::GameManager< struct Daemon::GameShader >( Daemon::DestroyShader );
    engine->content_manager.meshes = Daemon::GameManager< struct Daemon::GameMesh >( Daemon::DestroyMesh );
    engine->content_manager.models = std::vector< struct Daemon::GameModel >( );
  }
}

bool Daemon::LoadAsset( struct Daemon::GameEngine* engine, enum Daemon::EAssetTypes type, std::string path ) {
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

    if ( mesh ) {
      struct Daemon::GameModel temp = Daemon::MakeModel( mesh );
      _cm->models.push_back( temp );
      _cm->model_count++;
    }

    index++;
  }
}

struct Daemon::GameModel* Daemon::FindModel( struct Daemon::GameEngine* engine, unsigned int mesh ) {
  if ( mesh < engine->content_manager.model_count )
    return &engine->content_manager.models[ mesh ];

  return nullptr;
}

void* Daemon::GetAsset( struct Daemon::GameEngine* engine, enum Daemon::EAssetTypes type, unsigned int index ) {
  struct Daemon::GameContentManager* _cm = MAKE_PTR( engine->content_manager );

  switch ( type ) {
    case TEXTURE : return _cm->textures.Get( index );
    case SHADER  : return _cm->shaders.Get( index );
    case MESH    : return _cm->meshes.Get( index );
  }

  return nullptr;
}

void Daemon::ClearContentManager( struct Daemon::GameEngine* engine ) {
  if ( engine ) {
    engine->content_manager.textures.~GameManager< struct Daemon::GameTexture >( );
    engine->content_manager.shaders.~GameManager< struct Daemon::GameShader >( );
    engine->content_manager.meshes.~GameManager< struct Daemon::GameMesh >( );

    while ( engine->content_manager.model_count > 0 ) {
      engine->content_manager.model_count--;
      Daemon::DestroyModel( MAKE_PTR( engine->content_manager.models[ engine->content_manager.model_count ] ) );
    }

    engine->content_manager.models.~vector< struct Daemon::GameModel >( );
  }
}
