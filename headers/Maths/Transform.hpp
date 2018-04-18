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

#ifndef _MATHS_TRANSFORM_HPP_
#define _MATHS_TRANSFORM_HPP_

  namespace Maths {

    struct Transform {

      float position[ 3 ];
      float rotation[ 3 ];
      float scale[ 3 ];

    };

    void SetPosition( struct Transform* transform, float value[ 3 ] );

    void SetRotation( struct Transform* transform, float value[ 3 ] );

    void SetScale( struct Transform* transform, float value[ 3 ] );

    void SetTransform( struct Transform* transform, float position[ 3 ], float rotation[ 3 ], float scale[ 3 ] );

  };

#endif
