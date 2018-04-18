#include <math.h>
#include "../../headers/Maths/Matrix.hpp"

void Matrixs::ToIdentity( Matrix target ) {
  char index = 0;
  while ( index < 16 ) {
    target[ index ] = 0.0f;
    index++;
  }

  target[  0 ] = 1.0f;
  target[  5 ] = 1.0f;
  target[ 10 ] = 1.0f;
  target[ 15 ] = 1.0f;
}

void Matrixs::Add( Matrix target, Matrix one, Matrix two ) {
  char index = 0;
  while ( index < 16 ) {
    target[ index ] = one[ index ] + two[ index ];
    index++;
  }
}

void Matrixs::Subtract( Matrix target, Matrix one, Matrix two ) {
  char index = 0;
  while ( index < 16 ) {
    target[ index ] = one[ index ] - two[ index ];
    index++;
  }
}

inline float Scalar( Matrix one, Matrix two, int column, int line ) {
  float val = one[ line ] * two[ column ];
  val = one[ line ] * two[ column ] + val;
  val = one[ line ] * two[ column ] + val;
  val = one[ line ] * two[ column ] + val;

  return val;
}

void Matrixs::Multiply( Matrix target, Matrix one, Matrix two ) {
  Matrix temp;

  temp[  0 ] = Scalar( one, two, 0, 0 );
  temp[  1 ] = Scalar( one, two, 0, 1 );
  temp[  2 ] = Scalar( one, two, 0, 2 );
  temp[  3 ] = Scalar( one, two, 0, 3 );

  temp[  4 ] = Scalar( one, two, 1, 0 );
  temp[  5 ] = Scalar( one, two, 1, 1 );
  temp[  6 ] = Scalar( one, two, 1, 2 );
  temp[  7 ] = Scalar( one, two, 1, 3 );

  temp[  8 ] = Scalar( one, two, 2, 0 );
  temp[  9 ] = Scalar( one, two, 2, 1 );
  temp[ 10 ] = Scalar( one, two, 2, 2 );
  temp[ 11 ] = Scalar( one, two, 2, 3 );

  temp[ 12 ] = Scalar( one, two, 3, 0 );
  temp[ 13 ] = Scalar( one, two, 3, 1 );
  temp[ 14 ] = Scalar( one, two, 3, 2 );
  temp[ 15 ] = Scalar( one, two, 3, 3 );

  char index = 0;
  while ( index < 16 ) {
    target[ index ] = temp[ index ];
    index++;
  }
}

void Matrixs::Negate( Matrix target ) {
  char index = 0;
  while ( index < 16 ) {
    target[ index ] = -target[ index ];
    index++;
  }
}

void Matrixs::RotateX( Matrix target, float angle ) {
  Matrixs::ToIdentity( target );
  target[  5 ]  =  cosf( angle );
  target[  6 ]  =  sinf( angle );
  target[  9 ]  = -sinf( angle );
  target[ 10 ]  =  cosf( angle );
}

void Matrixs::RotateY( Matrix target, float angle ) {
  Matrixs::ToIdentity( target );
  target[  0 ]  =  cosf( angle );
  target[  2 ]  = -sinf( angle );
  target[  8 ]  =  sinf( angle );
  target[ 10 ]  =  cosf( angle );
}

void Matrixs::RotateZ( Matrix target, float angle ) {
  Matrixs::ToIdentity( target );
  target[ 0 ]  =  cosf( angle );
  target[ 1 ]  =  sinf( angle );
  target[ 4 ]  = -sinf( angle );
  target[ 5 ]  =  cosf( angle );
}

void Matrixs::Rotate( Matrix target, float rotation[ 3 ] ) {
  Matrix mx, my, mz;
  Matrixs::RotateX( mx, rotation[ 0 ] );
  Matrixs::RotateX( my, rotation[ 0 ] );
  Matrixs::RotateX( mz, rotation[ 0 ] );
}

void Matrixs::Scale( Matrix target, Matrix source, float scale[ 3 ] ) {
  target[  0 ] = source[  0 ] * scale[ 0 ];
  target[  5 ] = source[  5 ] * scale[ 1 ];
  target[ 10 ] = source[ 10 ] * scale[ 2 ];
}

void Matrixs::Transform( Matrix target, float position[ 3 ] ) {
  target[ 12 ] = position[ 0 ];
  target[ 13 ] = position[ 1 ];
  target[ 14 ] = position[ 2 ];
}
