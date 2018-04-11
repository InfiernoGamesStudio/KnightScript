/**
 * MIT License
 *
 * Copyright (c) 2018 InfiernoGamesStudio
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

#ifndef _KNIGHT_SCRIPT_HPP_
#define _KNIGHT_SCRIPT_HPP_

  // Basic C headers
  extern "C" {
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>
  };

  // Basic C++ headers
  #include <bitset>
  #include <fstream>
  #include <map>
  #include <memory>
  #include <sstream>
  #include <string>
  #include <vector>

  // Pointers helpers
  #define CREATE_PTR( type, name ) type* name = nullptr;
  #define DELETE_PTR( ptr ) if ( ptr ) { free( ptr ); ptr= nullptr; }
  #define ALLOC( type, name ) type * name = ( type * )malloc( sizeof( type ) )
  #define MALLOC( type, name, offset ) name = ( type * )malloc( sizeof( type ) + offset )
  #define REALLOC( type, name, offset ) name = ( type * )realloc( name, sizeof( name ) + offset * sizeof( type ) );
  #define MAKE_PTR( ref ) &ref
  #define MAKE_REF( ptr ) *ptr
  #define VALID_PTR( ptr ) ( ptr ) ? true : false
  #define IS( ptr, type ) dynamic_cast< type* >( ptr )
  #define CAST( ptr, type ) static_cast< type* >( ptr )

#endif
