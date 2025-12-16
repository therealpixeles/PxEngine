#ifndef GLAD_GL_H_
#define GLAD_GL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#ifndef APIENTRY
#ifdef _WIN32
#define APIENTRY __stdcall
#else
#define APIENTRY
#endif
#endif

#ifndef GLAPI
#define GLAPI extern
#endif

#ifndef GLAPIENTRY
#define GLAPIENTRY APIENTRY
#endif

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef unsigned char GLubyte;
typedef short GLshort;
typedef unsigned short GLushort;
typedef int GLint;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef double GLdouble;
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;
typedef char GLchar;
typedef int64_t GLint64;
typedef uint64_t GLuint64;
typedef void (*GLADapiproc)(void);
typedef void* (*GLADloadproc)(const char* name);

#define GL_FALSE 0
#define GL_TRUE 1

#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_STATIC_DRAW 0x88E4
#define GL_FLOAT 0x1406
#define GL_TRIANGLES 0x0004
#define GL_VERTEX_SHADER 0x8B31
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_REPEAT 0x2901
#define GL_LINEAR 0x2601
#define GL_RGBA 0x1908
#define GL_UNSIGNED_BYTE 0x1401
#define GL_TEXTURE0 0x84C0
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_DEPTH_TEST 0x0B71

#define GL_VERSION 0x1F02
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_EXTENSIONS 0x1F03

#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400

#define GL_SRGB8_ALPHA8 0x8C43
#define GL_TEXTURE_MAX_LEVEL 0x813D

#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C

#ifndef GLAD_IMPLEMENTATION
GLAPI int GLAD_GL_VERSION_4_6;
#endif

typedef const GLubyte* (GLAPIENTRY *PFNGLGETSTRINGPROC)(GLenum name);
typedef void (GLAPIENTRY *PFNGLGETINTEGERVPROC)(GLenum pname, GLint* data);
typedef void (GLAPIENTRY *PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (GLAPIENTRY *PFNGLCLEARPROC)(GLbitfield mask);
typedef void (GLAPIENTRY *PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef GLuint (GLAPIENTRY *PFNGLCREATESHADERPROC)(GLenum type);
typedef void (GLAPIENTRY *PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
typedef void (GLAPIENTRY *PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef void (GLAPIENTRY *PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint* params);
typedef void (GLAPIENTRY *PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef GLuint (GLAPIENTRY *PFNGLCREATEPROGRAMPROC)(void);
typedef void (GLAPIENTRY *PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (GLAPIENTRY *PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void (GLAPIENTRY *PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint* params);
typedef void (GLAPIENTRY *PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (GLAPIENTRY *PFNGLDELETESHADERPROC)(GLuint shader);
typedef void (GLAPIENTRY *PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef void (GLAPIENTRY *PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void (GLAPIENTRY *PFNGLGENBUFFERSPROC)(GLsizei n, GLuint* buffers);
typedef void (GLAPIENTRY *PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef void (GLAPIENTRY *PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
typedef void (GLAPIENTRY *PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
typedef void (GLAPIENTRY *PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef void (GLAPIENTRY *PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (GLAPIENTRY *PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
typedef void (GLAPIENTRY *PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (GLAPIENTRY *PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint* buffers);
typedef void (GLAPIENTRY *PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint* arrays);
typedef GLint (GLAPIENTRY *PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar* name);
typedef void (GLAPIENTRY *PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
typedef void (GLAPIENTRY *PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY *PFNGLACTIVETEXTUREPROC)(GLenum texture);
typedef void (GLAPIENTRY *PFNGLGENTEXTURESPROC)(GLsizei n, GLuint* textures);
typedef void (GLAPIENTRY *PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
typedef void (GLAPIENTRY *PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (GLAPIENTRY *PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (GLAPIENTRY *PFNGLGENERATEMIPMAPPROC)(GLenum target);
typedef void (GLAPIENTRY *PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint* textures);
typedef GLenum (GLAPIENTRY *PFNGLGETERRORPROC)(void);
typedef void (GLAPIENTRY *PFNGLENABLEPROC)(GLenum cap);

GLAPI PFNGLGETSTRINGPROC glad_glGetString;
GLAPI PFNGLGETINTEGERVPROC glad_glGetIntegerv;
GLAPI PFNGLCLEARCOLORPROC glad_glClearColor;
GLAPI PFNGLCLEARPROC glad_glClear;
GLAPI PFNGLVIEWPORTPROC glad_glViewport;
GLAPI PFNGLCREATESHADERPROC glad_glCreateShader;
GLAPI PFNGLSHADERSOURCEPROC glad_glShaderSource;
GLAPI PFNGLCOMPILESHADERPROC glad_glCompileShader;
GLAPI PFNGLGETSHADERIVPROC glad_glGetShaderiv;
GLAPI PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog;
GLAPI PFNGLCREATEPROGRAMPROC glad_glCreateProgram;
GLAPI PFNGLATTACHSHADERPROC glad_glAttachShader;
GLAPI PFNGLLINKPROGRAMPROC glad_glLinkProgram;
GLAPI PFNGLGETPROGRAMIVPROC glad_glGetProgramiv;
GLAPI PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog;
GLAPI PFNGLDELETESHADERPROC glad_glDeleteShader;
GLAPI PFNGLDELETEPROGRAMPROC glad_glDeleteProgram;
GLAPI PFNGLUSEPROGRAMPROC glad_glUseProgram;
GLAPI PFNGLGENBUFFERSPROC glad_glGenBuffers;
GLAPI PFNGLBINDBUFFERPROC glad_glBindBuffer;
GLAPI PFNGLBUFFERDATAPROC glad_glBufferData;
GLAPI PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays;
GLAPI PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray;
GLAPI PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray;
GLAPI PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer;
GLAPI PFNGLDRAWARRAYSPROC glad_glDrawArrays;
GLAPI PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers;
GLAPI PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays;
GLAPI PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation;
GLAPI PFNGLUNIFORM1IPROC glad_glUniform1i;
GLAPI PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv;
GLAPI PFNGLACTIVETEXTUREPROC glad_glActiveTexture;
GLAPI PFNGLGENTEXTURESPROC glad_glGenTextures;
GLAPI PFNGLBINDTEXTUREPROC glad_glBindTexture;
GLAPI PFNGLTEXPARAMETERIPROC glad_glTexParameteri;
GLAPI PFNGLTEXIMAGE2DPROC glad_glTexImage2D;
GLAPI PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap;
GLAPI PFNGLDELETETEXTURESPROC glad_glDeleteTextures;
GLAPI PFNGLGETERRORPROC glad_glGetError;
GLAPI PFNGLENABLEPROC glad_glEnable;

#define glGetString glad_glGetString
#define glGetIntegerv glad_glGetIntegerv
#define glClearColor glad_glClearColor
#define glClear glad_glClear
#define glViewport glad_glViewport
#define glCreateShader glad_glCreateShader
#define glShaderSource glad_glShaderSource
#define glCompileShader glad_glCompileShader
#define glGetShaderiv glad_glGetShaderiv
#define glGetShaderInfoLog glad_glGetShaderInfoLog
#define glCreateProgram glad_glCreateProgram
#define glAttachShader glad_glAttachShader
#define glLinkProgram glad_glLinkProgram
#define glGetProgramiv glad_glGetProgramiv
#define glGetProgramInfoLog glad_glGetProgramInfoLog
#define glDeleteShader glad_glDeleteShader
#define glDeleteProgram glad_glDeleteProgram
#define glUseProgram glad_glUseProgram
#define glGenBuffers glad_glGenBuffers
#define glBindBuffer glad_glBindBuffer
#define glBufferData glad_glBufferData
#define glGenVertexArrays glad_glGenVertexArrays
#define glBindVertexArray glad_glBindVertexArray
#define glEnableVertexAttribArray glad_glEnableVertexAttribArray
#define glVertexAttribPointer glad_glVertexAttribPointer
#define glDrawArrays glad_glDrawArrays
#define glDeleteBuffers glad_glDeleteBuffers
#define glDeleteVertexArrays glad_glDeleteVertexArrays
#define glGetUniformLocation glad_glGetUniformLocation
#define glUniform1i glad_glUniform1i
#define glUniformMatrix4fv glad_glUniformMatrix4fv
#define glActiveTexture glad_glActiveTexture
#define glGenTextures glad_glGenTextures
#define glBindTexture glad_glBindTexture
#define glTexParameteri glad_glTexParameteri
#define glTexImage2D glad_glTexImage2D
#define glGenerateMipmap glad_glGenerateMipmap
#define glDeleteTextures glad_glDeleteTextures
#define glGetError glad_glGetError
#define glEnable glad_glEnable

int gladLoadGLLoader(GLADloadproc loader);

#ifdef __cplusplus
}
#endif

#endif
