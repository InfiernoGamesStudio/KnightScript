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

#ifndef _MATHS_VECTOR_HPP_
#define _MATHS_VECTOR_HPP_

  typedef float Vector[ 3 ];

  namespace Vectors {

    void Add( Vector target, Vector source, float scalar );

    void Add( Vector target, Vector source, float* value, bool is_point );

    void Subtract( Vector target, Vector source, float scalar );

    void Subtract( Vector target, Vector source, float* value, bool is_point );

    void Multiply( Vector target, Vector source, float scalar );

    void Multiply( Vector target, Vector one, Vector two );

    void Negate( Vector target );

    float Length( Vector target );

    void Normalize( Vector target );

    float Dot( Vector one, Vector two );

    void Cross( Vector target, Vector one, Vector two );

    void Lerp( Vector target, Vector one, Vector two, float alpha );

  };

#endif
