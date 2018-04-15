#include "../../headers/KnightScript.hpp"
#include "../../headers/Daemon/Daemon.hpp"
#include "../../headers/Daemon/Graphics/GameMesh.hpp"
#include "../../headers/Daemon/Graphics/GameModel.hpp"
#include "../../headers/Daemon/Graphics/GameShader.hpp"
#include "../../headers/Daemon/Graphics/GameTexture.hpp"
#include "../../headers/Daemon/Utils/OpenGL.hpp"

void Daemon::DestroyTexture( struct Daemon::GameTexture* texture ) {
}

void Daemon::DestroyShader( struct Daemon::GameShader* shader ) {
}

void Daemon::DestroyMesh( struct Daemon::GameMesh* mesh ) {
  free( mesh->indexes );
  free( mesh->vertices );
}

struct Daemon::GameModel Daemon::MakeModel( struct Daemon::GameMesh* mesh ) {
  struct Daemon::GameModel model;

  if ( mesh ) {
    glGenVertexArrays( 1, MAKE_PTR( model.vao ) );
    glGenBuffers( 4, model.vbo );

    OpenGL::GenerateIndexBuffer( model.vbo[ 0 ], mesh->indexes );
    OpenGL::GenerateDataBuffer( model.vbo[ 1 ], 0, mesh->vertices, 0, 3 );
    OpenGL::GenerateDataBuffer( model.vbo[ 2 ], 1, mesh->vertices, 3, 3 );
    OpenGL::GenerateDataBuffer( model.vbo[ 3 ], 2, mesh->vertices, 6, 2 );
  }

  return model;
}

void Daemon::DestroyModel( struct Daemon::GameModel* model ) {
  glDeleteVertexArrays( 1, &model->vao );
  glDeleteBuffers( 4, model->vbo );
}
