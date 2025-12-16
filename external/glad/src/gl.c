#define GLAD_IMPLEMENTATION
#include "glad/gl.h"
#include <string.h>

int GLAD_GL_VERSION_4_6 = 0;

static void *get_proc(GLADloadproc load, const char *name) {
    void *proc = load(name);
    return proc;
}

int gladLoadGLLoader(GLADloadproc load) {
    if (!load) {
        return 0;
    }

    glad_glGetString = (PFNGLGETSTRINGPROC)get_proc(load, "glGetString");
    glad_glGetIntegerv = (PFNGLGETINTEGERVPROC)get_proc(load, "glGetIntegerv");
    glad_glClearColor = (PFNGLCLEARCOLORPROC)get_proc(load, "glClearColor");
    glad_glClear = (PFNGLCLEARPROC)get_proc(load, "glClear");
    glad_glViewport = (PFNGLVIEWPORTPROC)get_proc(load, "glViewport");
    glad_glCreateShader = (PFNGLCREATESHADERPROC)get_proc(load, "glCreateShader");
    glad_glShaderSource = (PFNGLSHADERSOURCEPROC)get_proc(load, "glShaderSource");
    glad_glCompileShader = (PFNGLCOMPILESHADERPROC)get_proc(load, "glCompileShader");
    glad_glGetShaderiv = (PFNGLGETSHADERIVPROC)get_proc(load, "glGetShaderiv");
    glad_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)get_proc(load, "glGetShaderInfoLog");
    glad_glCreateProgram = (PFNGLCREATEPROGRAMPROC)get_proc(load, "glCreateProgram");
    glad_glAttachShader = (PFNGLATTACHSHADERPROC)get_proc(load, "glAttachShader");
    glad_glLinkProgram = (PFNGLLINKPROGRAMPROC)get_proc(load, "glLinkProgram");
    glad_glGetProgramiv = (PFNGLGETPROGRAMIVPROC)get_proc(load, "glGetProgramiv");
    glad_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)get_proc(load, "glGetProgramInfoLog");
    glad_glDeleteShader = (PFNGLDELETESHADERPROC)get_proc(load, "glDeleteShader");
    glad_glDeleteProgram = (PFNGLDELETEPROGRAMPROC)get_proc(load, "glDeleteProgram");
    glad_glUseProgram = (PFNGLUSEPROGRAMPROC)get_proc(load, "glUseProgram");
    glad_glGenBuffers = (PFNGLGENBUFFERSPROC)get_proc(load, "glGenBuffers");
    glad_glBindBuffer = (PFNGLBINDBUFFERPROC)get_proc(load, "glBindBuffer");
    glad_glBufferData = (PFNGLBUFFERDATAPROC)get_proc(load, "glBufferData");
    glad_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)get_proc(load, "glGenVertexArrays");
    glad_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)get_proc(load, "glBindVertexArray");
    glad_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)get_proc(load, "glEnableVertexAttribArray");
    glad_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)get_proc(load, "glVertexAttribPointer");
    glad_glDrawArrays = (PFNGLDRAWARRAYSPROC)get_proc(load, "glDrawArrays");
    glad_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)get_proc(load, "glDeleteBuffers");
    glad_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)get_proc(load, "glDeleteVertexArrays");
    glad_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)get_proc(load, "glGetUniformLocation");
    glad_glUniform1i = (PFNGLUNIFORM1IPROC)get_proc(load, "glUniform1i");
    glad_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)get_proc(load, "glUniformMatrix4fv");
    glad_glActiveTexture = (PFNGLACTIVETEXTUREPROC)get_proc(load, "glActiveTexture");
    glad_glGenTextures = (PFNGLGENTEXTURESPROC)get_proc(load, "glGenTextures");
    glad_glBindTexture = (PFNGLBINDTEXTUREPROC)get_proc(load, "glBindTexture");
    glad_glTexParameteri = (PFNGLTEXPARAMETERIPROC)get_proc(load, "glTexParameteri");
    glad_glTexImage2D = (PFNGLTEXIMAGE2DPROC)get_proc(load, "glTexImage2D");
    glad_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)get_proc(load, "glGenerateMipmap");
    glad_glDeleteTextures = (PFNGLDELETETEXTURESPROC)get_proc(load, "glDeleteTextures");
    glad_glGetError = (PFNGLGETERRORPROC)get_proc(load, "glGetError");
    glad_glEnable = (PFNGLENABLEPROC)get_proc(load, "glEnable");

    int major = 0, minor = 0;
    if (glad_glGetIntegerv) {
        glad_glGetIntegerv(GL_MAJOR_VERSION, &major);
        glad_glGetIntegerv(GL_MINOR_VERSION, &minor);
    }
    GLAD_GL_VERSION_4_6 = (major > 4) || (major == 4 && minor >= 6);

    return glad_glClearColor && glad_glClear && glad_glViewport && glad_glCreateShader && glad_glShaderSource &&
           glad_glCompileShader && glad_glGetShaderiv && glad_glGetShaderInfoLog && glad_glCreateProgram &&
           glad_glAttachShader && glad_glLinkProgram && glad_glGetProgramiv && glad_glGetProgramInfoLog &&
           glad_glDeleteShader && glad_glDeleteProgram && glad_glUseProgram && glad_glGenBuffers &&
           glad_glBindBuffer && glad_glBufferData && glad_glGenVertexArrays && glad_glBindVertexArray &&
           glad_glEnableVertexAttribArray && glad_glVertexAttribPointer && glad_glDrawArrays &&
           glad_glDeleteBuffers && glad_glDeleteVertexArrays && glad_glGenTextures && glad_glBindTexture &&
           glad_glTexParameteri && glad_glTexImage2D && glad_glGenerateMipmap && glad_glDeleteTextures && glad_glEnable;
}
