#include <math.h>
#include "../../headers/Maths/Quaternion.hpp"

void Quaternions::Add( Quaternion target, Quaternion source, float scalar ) {
  target[ 0 ] = source[ 0 ] + scalar;
  target[ 1 ] = source[ 1 ] + scalar;
  target[ 2 ] = source[ 2 ] + scalar;
  target[ 3 ] = source[ 3 ] + scalar;
}

void Quaternions::Add( Quaternion target, Quaternion source, float* value, bool is_point ) {
  target[ 0 ] = source[ 0 ] + value[ 0 ];
  target[ 1 ] = source[ 1 ] + value[ 1 ];

  if ( !is_point )
    target[ 2 ] = source[ 2 ] + value[ 2 ];
}

void Quaternions::Add( Quaternion target, Quaternion one, Quaternion two ) {
  target[ 0 ] = one[ 0 ] + two[ 0 ];
  target[ 1 ] = one[ 1 ] + two[ 1 ];
  target[ 2 ] = one[ 2 ] + two[ 2 ];
  target[ 3 ] = one[ 3 ] + two[ 3 ];
}

void Quaternions::Subtract( Quaternion target, Quaternion source, float scalar ) {
  target[ 0 ] = source[ 0 ] - scalar;
  target[ 1 ] = source[ 1 ] - scalar;
  target[ 2 ] = source[ 2 ] - scalar;
  target[ 3 ] = source[ 3 ] - scalar;
}

void Quaternions::Subtract( Quaternion target, Quaternion source, float* value, bool is_point ) {
  target[ 0 ] = source[ 0 ] - value[ 0 ];
  target[ 1 ] = source[ 1 ] - value[ 1 ];

  if ( !is_point )
    target[ 2 ] = source[ 2 ] - value[ 2 ];
}

void Quaternions::Subtract( Quaternion target, Quaternion one, Quaternion two ) {
  target[ 0 ] = one[ 0 ] - two[ 0 ];
  target[ 1 ] = one[ 1 ] - two[ 1 ];
  target[ 2 ] = one[ 2 ] - two[ 2 ];
  target[ 3 ] = one[ 3 ] - two[ 3 ];
}

void Quaternions::Multiply( Quaternion target, Quaternion source, float scalar ) {
  target[ 0 ] = source[ 0 ] * scalar;
  target[ 1 ] = source[ 1 ] * scalar;
  target[ 2 ] = source[ 2 ] * scalar;
  target[ 3 ] = source[ 3 ] * scalar;
}

void Quaternions::Multiply( Quaternion target, Quaternion one, Quaternion two ) {
  target[ 0 ] = one[ 0 ] * two[ 0 ];
  target[ 1 ] = one[ 1 ] * two[ 1 ];
  target[ 2 ] = one[ 2 ] * two[ 2 ];
  target[ 3 ] = one[ 3 ] * two[ 3 ];
}

void Quaternions::Negate( Quaternion target ) {
  target[ 0 ] = -target[ 0 ];
  target[ 1 ] = -target[ 1 ];
  target[ 2 ] = -target[ 2 ];
  target[ 3 ] = -target[ 3 ];
}

float Quaternions::Length( Quaternion target ) {
  float val = target[ 0 ] * target[ 0 ];
  val = target[ 1 ] * target[ 1 ] + val;
  val = target[ 2 ] * target[ 2 ] + val;
  val = target[ 3 ] * target[ 3 ] + val;

  return sqrtf( val );
}

void Quaternions::Normalize( Quaternion target ) {
  float length = 1.0f / Quaternions::Length( target );

  if ( length ) {
    target[ 0 ] = target[ 0 ] * length;
    target[ 1 ] = target[ 1 ] * length;
    target[ 2 ] = target[ 2 ] * length;
    target[ 3 ] = target[ 3 ] * length;
  }
}

float Quaternions::Dot( Quaternion one, Quaternion two ) {
  float val = one[ 0 ] * two[ 0 ];
  val = one[ 1 ] * two[ 1 ] + val;
  val = one[ 2 ] * two[ 2 ] + val;
  val = one[ 3 ] * two[ 3 ] + val;

  return val;
}

void Quaternions::Lerp( Quaternion target, Quaternion one, Quaternion two, float alpha ) {
  float _alpha = 1.0f - alpha;

  target[ 0 ] = target[ 0 ] * _alpha + alpha * target[ 0 ];
  target[ 1 ] = target[ 1 ] * _alpha + alpha * target[ 1 ];
  target[ 2 ] = target[ 2 ] * _alpha + alpha * target[ 2 ];
  target[ 3 ] = target[ 3 ] * _alpha + alpha * target[ 3 ];
}
