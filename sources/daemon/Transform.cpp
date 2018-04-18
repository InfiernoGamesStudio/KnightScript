#include "../../headers/Maths/Transform.hpp"

void Maths::SetPosition( struct Maths::Transform* transform, float value[ 3 ] ) {
  char i = 0;
  while ( i < 3 ) {
    transform->position[ i ] = value[ i ];
    i++;
  }
}

void Maths::SetRotation( struct Maths::Transform* transform, float value[ 3 ] ) {
  char i = 0;
  while ( i < 3 ) {
    transform->rotation[ i ] = value[ i ];
    i++;
  }
}

void Maths::SetScale( struct Maths::Transform* transform, float value[ 3 ] ) {
  char i = 0;
  while ( i < 3 ) {
    transform->scale[ i ] = value[ i ];
    i++;
  }
}

void Maths::SetTransform( struct Maths::Transform* transform, float position[ 3 ], float rotation[ 3 ], float scale[ 3 ] ) {
  char i = 0;
  while ( i < 3 ) {
    transform->position[ i ] = position[ i ];
    transform->rotation[ i ] = rotation[ i ];
    transform->scale[ i ] = scale[ i ];

    i++;
  }
}
