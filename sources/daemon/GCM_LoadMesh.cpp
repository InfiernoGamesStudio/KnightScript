#include "../../headers/KnightScript.hpp"
#include "../../headers/Daemon/Daemon.hpp"
#include "../../headers/Daemon/GameContentManager.hpp"
#include "../../headers/Daemon/Graphics/GameMesh.hpp"

void Daemon::LoadMesh( struct Daemon::GameContentManager* content_manager, std::string path ) {
  if ( content_manager->meshes.Find( path ) == 0 ) {
    struct Daemon::GameMesh* mesh = content_manager->meshes.Push( path );
    char index;
    union {
      int toi;
      float tof;
    } temp;

    std::ifstream loader = std::ifstream( path );

    int index_count, vertex_count;
    loader >> index_count; // Index count
    loader >> vertex_count; // Vertex count

    index_count = index_count * 3;
    vertex_count = vertex_count * 8;

    MAKE_REF( mesh ).vertex_count = ( unsigned int )index_count;
    MAKE_REF( mesh ).indexes = ( unsigned int* )malloc( sizeof( int ) * index_count );
    MAKE_REF( mesh ).vertices = ( float* )malloc( sizeof( float ) * vertex_count );

    // Load index and vertex data
    index_count = 0;
    vertex_count = 0;
    while ( true ) {
      loader >> path;

      if ( !loader.eof( ) ) {
        if ( path == "#index" ) {
          for ( index = 0; index < 3; index++ ) {
            loader >> temp.toi;
            MAKE_REF( mesh ).indexes[ index_count ] = ( unsigned int )temp.toi;
            index_count++;
          }
        } else if ( path == "#vertex" ) {
          for ( index = 0; index < 8; index++ ) {
            loader >> temp.tof;
            MAKE_REF( mesh ).vertices[ vertex_count ] = temp.tof;
            vertex_count++;
          }
        }
      } else
        break;
    }

    loader.close( );
  } else
    printf( "[ ERROR ] Mesh : %s already loaded !\n", path.c_str( ) );
}
