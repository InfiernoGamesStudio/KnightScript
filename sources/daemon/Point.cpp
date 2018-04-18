#include <math.h>
#include "../../headers/Maths/Point.hpp"

void Points::Add( Point target, Point source, float scalar ) {
  target[ 0 ] = source[ 0 ] + scalar;
  target[ 1 ] = source[ 1 ] + scalar;
}

void Points::Add( Point target, Point one, Point two ) {
  target[ 0 ] = one[ 0 ] + two[ 0 ];
  target[ 1 ] = one[ 1 ] + two[ 1 ];
}

void Points::Subtract( Point target, Point source, float scalar ) {
  target[ 0 ] = source[ 0 ] - scalar;
  target[ 1 ] = source[ 1 ] - scalar;
}

void Points::Subtract( Point target, Point one, Point two ) {
  target[ 0 ] = one[ 0 ] - two[ 0 ];
  target[ 1 ] = one[ 1 ] - two[ 1 ];
}

void Points::Multiply( Point target, Point source, float scalar ) {
  target[ 0 ] = source[ 0 ] * scalar;
  target[ 1 ] = source[ 1 ] * scalar;
}

void Points::Multiply( Point target, Point one, Point two ) {
  target[ 0 ] = one[ 0 ] * two[ 0 ];
  target[ 1 ] = one[ 1 ] * two[ 1 ];
}

void Points::Negate( Point target ) {
  target[ 0 ] = -target[ 0 ];
  target[ 1 ] = -target[ 1 ];
}

float Points::Length( Point target ) {
  return sqrtf(
    target[ 0 ] * target[ 0 ] +
    target[ 1 ] * target[ 1 ] +
    1.0f
  );
}

void Points::Normalize( Point target ) {
  float length = 1.0f / Points::Length( target );

  if ( length ) {
    target[ 0 ] = target[ 0 ] * length;
    target[ 1 ] = target[ 1 ] * length;
  }
}

void Points::Lerp( Point target, Point one, Point two, float alpha ) {
  float _alpha = 1.0f - alpha;

  target[ 0 ] = one[ 0 ] * _alpha + alpha * two[ 0 ];
  target[ 1 ] = one[ 1 ] * _alpha + alpha * two[ 1 ];
}
