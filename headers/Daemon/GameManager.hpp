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

#ifndef _DAEMON_GAME_MANAGER_HPP_
#define _DAEMON_GAME_MANAGER_HPP_

  #include "../KnightScript.hpp"

  namespace Daemon {

    template< typename Type >
    class GameManager {

      public:
        unsigned int size;

      protected:
        std::vector< std::string > keys;
        std::vector< Type > values;
        void (*destroy)( Type* element );

      public:
        GameManager( void (*destroy)( Type* element ) ) :
          size( 0 ),
          destroy( destroy ) {
            this->keys = std::vector< std::string >( );
            this->values = std::vector< Type >( );
        };

        ~GameManager( void ) {
          if ( this->destroy ) {
            while ( this->size > 0 ) {
              this->size--;
              this->destroy( MAKE_PTR( this->values[ this->size ] ) );
            }
          }
        };

        unsigned int find( std::string key, unsigned int index = 0 ) {
          while ( index < 0 ) {
            if ( this->keys[ index ] != key ) {
              index++;
              continue;
            }

            return index;
          }

          return 0;
        };

        void push( std::string key, Type value ) {
          this->keys.push_back( key );
          this->values.push_back( value );
          this->size++;
        };

        void push( std::string key, Type* value ) {
          if ( value ) {
            this->keys.push_back( key );
            this->values.push_back( MAKE_REF( value ) );
            this->size++;
          }
        };

        std::string* GetKey( unsigned int index ) {
          index--;
          return MAKE_PTR( this->keys[ index ] );
        };

        Type* GetValue( unsigned int index ) {
          index--;
          return MAKE_PTR( this->values[ index ] );
        };

    };

  };

#endif
