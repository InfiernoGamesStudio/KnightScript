#include <math.h>
#include "../../headers/Maths/Vector.hpp"

void Vectors::Add( Vector target, Vector source, float scalar ) {
  target[ 0 ] = source[ 0 ] + scalar;
  target[ 1 ] = source[ 1 ] + scalar;
  target[ 2 ] = source[ 2 ] + scalar;
}

void Vectors::Add( Vector target, Vector source, float* two, bool is_point ) {
  target[ 0 ] = source[ 0 ] + two[ 0 ];
  target[ 1 ] = source[ 1 ] + two[ 1 ];

  if ( !is_point )
    target[ 2 ] = source[ 2 ] + two[ 2 ];
}

void Vectors::Subtract( Vector target, Vector source, float scalar ) {
  target[ 0 ] = source[ 0 ] - scalar;
  target[ 1 ] = source[ 1 ] - scalar;
  target[ 2 ] = source[ 2 ] - scalar;
}

void Vectors::Subtract( Vector target, Vector source, float* value, bool is_point ) {
  target[ 0 ] = source[ 0 ] - value[ 0 ];
  target[ 1 ] = source[ 1 ] - value[ 1 ];

  if ( !is_point )
    target[ 2 ] = source[ 2 ] - value[ 2 ];
}

void Vectors::Multiply( Vector target, Vector source, float scalar ) {
  target[ 0 ] = source[ 0 ] * scalar;
  target[ 1 ] = source[ 1 ] * scalar;
  target[ 2 ] = source[ 2 ] * scalar;
}

void Vectors::Multiply( Vector target, Vector one, Vector two ) {
  target[ 0 ] = one[ 0 ] * two[ 0 ];
  target[ 1 ] = one[ 1 ] * two[ 1 ];
  target[ 2 ] = one[ 2 ] * two[ 2 ];
}

void Vectors::Negate( Vector target ) {
  target[ 0 ] = -target[ 0 ];
  target[ 1 ] = -target[ 1 ];
  target[ 2 ] = -target[ 2 ];
}

float Vectors::Length( Vector target ) {
  float val = target[ 0 ] * target[ 0 ];
  val = target[ 1 ] * target[ 1 ] + val;
  val = target[ 2 ] * target[ 2 ] + val;

  return sqrtf( val );
}

void Vectors::Normalize( Vector target ) {
  float length = 1.0f / Vectors::Length( target );

  if ( length ) {
    target[ 0 ] = target[ 0 ] * length;
    target[ 1 ] = target[ 1 ] * length;
    target[ 2 ] = target[ 2 ] * length;
  }
}

float Vectors::Dot( Vector one, Vector two ) {
  float val = one[ 0 ] * two[ 0 ];
  val = one[ 1 ] * two[ 1 ] + val;
  val = one[ 2 ] * two[ 2 ] + val;

  return val;
}

void Vectors::Cross( Vector target, Vector one, Vector two ) {
  Vector temp;

  temp[ 0 ] = one[ 1 ] * two[ 2 ] - one[ 2 ] * two[ 1 ];
  temp[ 1 ] = one[ 0 ] * two[ 2 ] - one[ 2 ] * two[ 0 ];
  temp[ 2 ] = one[ 0 ] * two[ 1 ] - one[ 1 ] * two[ 0 ];

  target[ 0 ] = temp[ 0 ];
  target[ 1 ] = temp[ 1 ];
  target[ 2 ] = temp[ 2 ];
}

void Vectors::Lerp( Vector target, Vector one, Vector two, float alpha ) {
  float _alpha = 1.0f - alpha;

  target[ 0 ] = one[ 0 ] * _alpha + alpha * two[ 0 ];
  target[ 1 ] = one[ 1 ] * _alpha + alpha * two[ 1 ];
  target[ 2 ] = one[ 2 ] * _alpha + alpha * two[ 2 ];
}
