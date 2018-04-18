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

#ifndef _MATHS_POINT_HPP_
#define _MATHS_POINT_HPP_

  typedef float Point[ 2 ];

  namespace Points {

    void Add( Point target, Point source, float scalar );

    void Add( Point target, Point one, Point two );

    void Subtract( Point target, Point source, float scalar );

    void Subtract( Point target, Point one, Point two );

    void Multiply( Point target, Point source, float scalar );

    void Multiply( Point target, Point one, Point two );

    void Negate( Point target );

    float Length( Point target );

    void Normalize( Point target );

    void Lerp( Point target, Point one, Point two, float alpha );

  };

#endif
