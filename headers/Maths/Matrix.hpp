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

#ifndef _MATHS_MATRIX_HPP_
#define _MATHS_MATRIX_HPP_

  typedef float Matrix[ 16 ];

  namespace Matrixs {

    void ToIdentity( Matrix target );

    void Add( Matrix target, Matrix one, Matrix two );

    void Subtract( Matrix target, Matrix one, Matrix two );

    void Multiply( Matrix target, Matrix one, Matrix two );

    void Negate( Matrix target );

    void RotateX( Matrix target, float angle );

    void RotateY( Matrix target, float angle );

    void RotateZ( Matrix target, float angle );

    void Rotate( Matrix target, float rotation[ 3 ] );

    void Scale( Matrix target, Matrix source, float scale[ 3 ] );

    void Transform( Matrix target, float position[ 3 ] );

  };

#endif
