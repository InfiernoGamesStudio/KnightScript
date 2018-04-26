#include "../../headers/KnightScript.hpp"
#include "../../headers/Daemon/Daemon.hpp"
#include "../../headers/Daemon/Utils/OpenGL.hpp"

void OpenGL::GenerateIndexBuffer( unsigned int vbo, unsigned int* data, unsigned int size ) {
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, vbo );
  glBufferData( GL_ELEMENT_ARRAY_BUFFER, size * sizeof( GLuint ), data, GL_STATIC_DRAW );
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

void OpenGL::GenerateDataBuffer( unsigned int vbo, int id, float* data, int stride, int size ) {
  glBindBuffer( GL_ARRAY_BUFFER, vbo );
  glBufferData( GL_ARRAY_BUFFER, size * sizeof( GLfloat ), data, GL_STATIC_DRAW );
  glVertexAttribPointer( id, stride, GL_INT, GL_FALSE, stride * sizeof( GLfloat ), (GLvoid*) 0 );
  glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

void OpenGL::GenerateDataBuffer( unsigned int vbo, int id, int* data, int stride, int size ) {
  glBindBuffer( GL_ARRAY_BUFFER, vbo );
  glBufferData( GL_ARRAY_BUFFER, size * sizeof( GLint ), data, GL_STATIC_DRAW );
  glVertexAttribPointer( id, stride, GL_FLOAT, GL_FALSE, stride * sizeof( GLint ), (GLvoid*) 0 );
  glBindBuffer( GL_ARRAY_BUFFER, 0 );
}
