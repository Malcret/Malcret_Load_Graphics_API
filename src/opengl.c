#include "MGLL/opengl.h"

#include <stdio.h>

#ifdef _WIN32
#define mgll_glGetProcAddress(name) wglGetProcAddress(name)

void *mgll_getGLFuncAddress(const char *name) {
	void *p = (void *)mgll_glGetProcAddress(name);

	if (p == 0 || (p == (void *)0x1) || (p == (void *)0x2) || (p == (void *)0x3) || (p == (void *)-1)) {
		HMODULE module = LoadLibraryA("opengl32.dll");
		p = (void *)GetProcAddress(module, name);
	}

	if (!p) {
		fprintf(stderr, "Failed to load OpenGL function %s\n", name);
	}

	return p;
}
#endif /* _WIN32 */

#ifdef __linux__
#define mgll_glGetProcAddress(name) glXGetProcAddress((const GLubyte *)name)

#include <dlfcn.h>

void *mgll_getGLFuncAddress(const char *name) {
	void *p = (void *)mgll_glGetProcAddress(name);

	if (p == 0 || (p == (void *)0x1) || (p == (void *)0x2) || (p == (void *)0x3) || (p == (void *)-1)) {
		void *handle = dlopen("libGL.so.1", RTLD_LAZY);
		p = (void *)dlsym(handle, name);
	}

	if (!p) {
		fprintf(stderr, "Failed to load OpenGL function %s\n", name);
	}

	return p;
}
#endif /* MGLL_PLATFORM_LINUX */

#define mgll_loadGLFunc(type, name) type name = (type)mgll_getGLFuncAddress(#name);

#ifdef MGLL_GL_CORE_PROFILE
#ifdef GL_VERSION_1_0
#define MGLL_LOAD_GL_CORE_1_0_FUNC mgll_loadGLFunc(PFNGLCULLFACEPROC, glCullFace);\
mgll_loadGLFunc(PFNGLFRONTFACEPROC, glFrontFace);\
mgll_loadGLFunc(PFNGLHINTPROC, glHint);\
mgll_loadGLFunc(PFNGLLINEWIDTHPROC, glLineWidth);\
mgll_loadGLFunc(PFNGLPOINTSIZEPROC, glPointSize);\
mgll_loadGLFunc(PFNGLPOLYGONMODEPROC, glPolygonMode);\
mgll_loadGLFunc(PFNGLSCISSORPROC, glScissor);\
mgll_loadGLFunc(PFNGLTEXPARAMETERFPROC, glTexParameterf);\
mgll_loadGLFunc(PFNGLTEXPARAMETERFVPROC, glTexParameterfv);\
mgll_loadGLFunc(PFNGLTEXPARAMETERIPROC, glTexParameteri);\
mgll_loadGLFunc(PFNGLTEXPARAMETERIVPROC, glTexParameteriv);\
mgll_loadGLFunc(PFNGLTEXIMAGE1DPROC, glTexImage1D);\
mgll_loadGLFunc(PFNGLTEXIMAGE2DPROC, glTexImage2D);\
mgll_loadGLFunc(PFNGLDRAWBUFFERPROC, glDrawBuffer);\
mgll_loadGLFunc(PFNGLCLEARPROC, glClear);\
mgll_loadGLFunc(PFNGLCLEARCOLORPROC, glClearColor);\
mgll_loadGLFunc(PFNGLCLEARSTENCILPROC, glClearStencil);\
mgll_loadGLFunc(PFNGLCLEARDEPTHPROC, glClearDepth);\
mgll_loadGLFunc(PFNGLSTENCILMASKPROC, glStencilMask);\
mgll_loadGLFunc(PFNGLCOLORMASKPROC, glColorMask);\
mgll_loadGLFunc(PFNGLDEPTHMASKPROC, glDepthMask);\
mgll_loadGLFunc(PFNGLDISABLEPROC, glDisable);\
mgll_loadGLFunc(PFNGLENABLEPROC, glEnable);\
mgll_loadGLFunc(PFNGLFINISHPROC, glFinish);\
mgll_loadGLFunc(PFNGLFLUSHPROC, glFlush);\
mgll_loadGLFunc(PFNGLBLENDFUNCPROC, glBlendFunc);\
mgll_loadGLFunc(PFNGLLOGICOPPROC, glLogicOp);\
mgll_loadGLFunc(PFNGLSTENCILFUNCPROC, glStencilFunc);\
mgll_loadGLFunc(PFNGLSTENCILOPPROC, glStencilOp);\
mgll_loadGLFunc(PFNGLDEPTHFUNCPROC, glDepthFunc);\
mgll_loadGLFunc(PFNGLPIXELSTOREFPROC, glPixelStoref);\
mgll_loadGLFunc(PFNGLPIXELSTOREIPROC, glPixelStorei);\
mgll_loadGLFunc(PFNGLREADBUFFERPROC, glReadBuffer);\
mgll_loadGLFunc(PFNGLREADPIXELSPROC, glReadPixels);\
mgll_loadGLFunc(PFNGLGETBOOLEANVPROC, glGetBooleanv);\
mgll_loadGLFunc(PFNGLGETDOUBLEVPROC, glGetDoublev);\
mgll_loadGLFunc(PFNGLGETERRORPROC, glGetError);\
mgll_loadGLFunc(PFNGLGETFLOATVPROC, glGetFloatv);\
mgll_loadGLFunc(PFNGLGETINTEGERVPROC, glGetIntegerv);\
mgll_loadGLFunc(PFNGLGETSTRINGPROC, glGetString);\
mgll_loadGLFunc(PFNGLGETTEXIMAGEPROC, glGetTexImage);\
mgll_loadGLFunc(PFNGLGETTEXPARAMETERFVPROC, glGetTexParameterfv);\
mgll_loadGLFunc(PFNGLGETTEXPARAMETERIVPROC, glGetTexParameteriv);\
mgll_loadGLFunc(PFNGLGETTEXLEVELPARAMETERFVPROC, glGetTexLevelParameterfv);\
mgll_loadGLFunc(PFNGLGETTEXLEVELPARAMETERIVPROC, glGetTexLevelParameteriv);\
mgll_loadGLFunc(PFNGLISENABLEDPROC, glIsEnabled);\
mgll_loadGLFunc(PFNGLDEPTHRANGEPROC, glDepthRange);\
mgll_loadGLFunc(PFNGLVIEWPORTPROC, glViewport);
#endif /* GL_VERSION_1_0 */
#ifdef GL_VERSION_1_1
#define MGLL_LOAD_GL_CORE_1_1_FUNC 	mgll_loadGLFunc(PFNGLDRAWARRAYSPROC, glDrawArrays);\
mgll_loadGLFunc(PFNGLDRAWELEMENTSPROC, glDrawElements);\
mgll_loadGLFunc(PFNGLGETPOINTERVPROC, glGetPointerv);\
mgll_loadGLFunc(PFNGLPOLYGONOFFSETPROC, glPolygonOffset);\
mgll_loadGLFunc(PFNGLCOPYTEXIMAGE1DPROC, glCopyTexImage1D);\
mgll_loadGLFunc(PFNGLCOPYTEXIMAGE2DPROC, glCopyTexImage2D);\
mgll_loadGLFunc(PFNGLCOPYTEXSUBIMAGE1DPROC, glCopyTexSubImage1D);\
mgll_loadGLFunc(PFNGLCOPYTEXSUBIMAGE2DPROC, glCopyTexSubImage2D);\
mgll_loadGLFunc(PFNGLTEXSUBIMAGE1DPROC, glTexSubImage1D);\
mgll_loadGLFunc(PFNGLTEXSUBIMAGE2DPROC, glTexSubImage2D);\
mgll_loadGLFunc(PFNGLBINDTEXTUREPROC, glBindTexture);\
mgll_loadGLFunc(PFNGLDELETETEXTURESPROC, glDeleteTextures);\
mgll_loadGLFunc(PFNGLGENTEXTURESPROC, glGenTextures);\
mgll_loadGLFunc(PFNGLISTEXTUREPROC, glIsTexture);
#endif /* GL_VERSION_1_1 */
#ifdef GL_VERSION_1_2
#define MGLL_LOAD_GL_CORE_1_2_FUNC mgll_loadGLFunc(PFNGLDRAWRANGEELEMENTSPROC, glDrawRangeElements);\
mgll_loadGLFunc(PFNGLTEXIMAGE3DPROC, glTexImage3D);\
mgll_loadGLFunc(PFNGLTEXSUBIMAGE3DPROC, glTexSubImage3D);\
mgll_loadGLFunc(PFNGLCOPYTEXSUBIMAGE3DPROC, glCopyTexSubImage3D);
#endif /* GL_VERSION_1_2 */
#ifdef GL_VERSION_1_3
#define MGLL_LOAD_GL_CORE_1_3_FUNC 	mgll_loadGLFunc(PFNGLACTIVETEXTUREPROC, glActiveTexture);\
mgll_loadGLFunc(PFNGLSAMPLECOVERAGEPROC, glSampleCoverage);\
mgll_loadGLFunc(PFNGLCOMPRESSEDTEXIMAGE3DPROC, glCompressedTexImage3D);\
mgll_loadGLFunc(PFNGLCOMPRESSEDTEXIMAGE2DPROC, glCompressedTexImage2D);\
mgll_loadGLFunc(PFNGLCOMPRESSEDTEXIMAGE1DPROC, glCompressedTexImage1D);\
mgll_loadGLFunc(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, glCompressedTexSubImage3D);\
mgll_loadGLFunc(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, glCompressedTexSubImage2D);\
mgll_loadGLFunc(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, glCompressedTexSubImage1D);\
mgll_loadGLFunc(PFNGLGETCOMPRESSEDTEXIMAGEPROC, glGetCompressedTexImage);
#endif /* GL_VERSION_1_3 */
#ifdef GL_VERSION_1_4
#define MGLL_LOAD_GL_CORE_1_4_FUNC 	mgll_loadGLFunc(PFNGLBLENDFUNCSEPARATEPROC, glBlendFuncSeparate);\
mgll_loadGLFunc(PFNGLMULTIDRAWARRAYSPROC, glMultiDrawArrays);\
mgll_loadGLFunc(PFNGLMULTIDRAWELEMENTSPROC, glMultiDrawElements);\
mgll_loadGLFunc(PFNGLPOINTPARAMETERFPROC, glPointParameterf);\
mgll_loadGLFunc(PFNGLPOINTPARAMETERFVPROC, glPointParameterfv);\
mgll_loadGLFunc(PFNGLPOINTPARAMETERIPROC, glPointParameteri);\
mgll_loadGLFunc(PFNGLPOINTPARAMETERIVPROC, glPointParameteriv);\
mgll_loadGLFunc(PFNGLBLENDCOLORPROC, glBlendColor);\
mgll_loadGLFunc(PFNGLBLENDEQUATIONPROC, glBlendEquation);
#endif /* GL_VERSION_1_4 */
#ifdef GL_VERSION_1_4
#define MGLL_LOAD_GL_CORE_1_5_FUNC 	mgll_loadGLFunc(PFNGLGENQUERIESPROC, glGenQueries);\
mgll_loadGLFunc(PFNGLDELETEQUERIESPROC, glDeleteQueries);\
mgll_loadGLFunc(PFNGLISQUERYPROC, glIsQuery);\
mgll_loadGLFunc(PFNGLBEGINQUERYPROC, glBeginQuery);\
mgll_loadGLFunc(PFNGLENDQUERYPROC, glEndQuery);\
mgll_loadGLFunc(PFNGLGETQUERYIVPROC, glGetQueryiv);\
mgll_loadGLFunc(PFNGLGETQUERYOBJECTIVPROC, glGetQueryObjectiv);\
mgll_loadGLFunc(PFNGLGETQUERYOBJECTUIVPROC, glGetQueryObjectuiv);\
mgll_loadGLFunc(PFNGLBINDBUFFERPROC, glBindBuffer);\
mgll_loadGLFunc(PFNGLDELETEBUFFERSPROC, glDeleteBuffers);\
mgll_loadGLFunc(PFNGLGENBUFFERSPROC, glGenBuffers);\
mgll_loadGLFunc(PFNGLISBUFFERPROC, glIsBuffer);\
mgll_loadGLFunc(PFNGLBUFFERDATAPROC, glBufferData);\
mgll_loadGLFunc(PFNGLBUFFERSUBDATAPROC, glBufferSubData);\
mgll_loadGLFunc(PFNGLGETBUFFERSUBDATAPROC, glGetBufferSubData);\
mgll_loadGLFunc(PFNGLMAPBUFFERPROC, glMapBuffer);\
mgll_loadGLFunc(PFNGLUNMAPBUFFERPROC, glUnmapBuffer);\
mgll_loadGLFunc(PFNGLGETBUFFERPARAMETERIVPROC, glGetBufferParameteriv);\
mgll_loadGLFunc(PFNGLGETBUFFERPOINTERVPROC, glGetBufferPointerv);
#endif /* GL_VERSION_1_5 */
#ifdef GL_VERSION_2_0
#define MGLL_LOAD_GL_CORE_2_0_FUNC mgll_loadGLFunc(PFNGLBLENDEQUATIONSEPARATEPROC, glBlendEquationSeparate);\
mgll_loadGLFunc(PFNGLDRAWBUFFERSPROC, glDrawBuffers);\
mgll_loadGLFunc(PFNGLSTENCILOPSEPARATEPROC, glStencilOpSeparate);\
mgll_loadGLFunc(PFNGLSTENCILFUNCSEPARATEPROC, glStencilFuncSeparate);\
mgll_loadGLFunc(PFNGLSTENCILMASKSEPARATEPROC, glStencilMaskSeparate);\
mgll_loadGLFunc(PFNGLATTACHSHADERPROC, glAttachShader);\
mgll_loadGLFunc(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation);\
mgll_loadGLFunc(PFNGLCOMPILESHADERPROC, glCompileShader);\
mgll_loadGLFunc(PFNGLCREATEPROGRAMPROC, glCreateProgram);\
mgll_loadGLFunc(PFNGLCREATESHADERPROC, glCreateShader);\
mgll_loadGLFunc(PFNGLDELETEPROGRAMPROC, glDeleteProgram);\
mgll_loadGLFunc(PFNGLDELETESHADERPROC, glDeleteShader);\
mgll_loadGLFunc(PFNGLDETACHSHADERPROC, glDetachShader);\
mgll_loadGLFunc(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray);\
mgll_loadGLFunc(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray);\
mgll_loadGLFunc(PFNGLGETACTIVEATTRIBPROC, glGetActiveAttrib);\
mgll_loadGLFunc(PFNGLGETACTIVEUNIFORMPROC, glGetActiveUniform);\
mgll_loadGLFunc(PFNGLGETATTACHEDSHADERSPROC, glGetAttachedShaders);\
mgll_loadGLFunc(PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation);\
mgll_loadGLFunc(PFNGLGETPROGRAMIVPROC, glGetProgramiv);\
mgll_loadGLFunc(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog);\
mgll_loadGLFunc(PFNGLGETSHADERIVPROC, glGetShaderiv);\
mgll_loadGLFunc(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog);\
mgll_loadGLFunc(PFNGLGETSHADERSOURCEPROC, glGetShaderSource);\
mgll_loadGLFunc(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation);\
mgll_loadGLFunc(PFNGLGETUNIFORMFVPROC, glGetUniformfv);\
mgll_loadGLFunc(PFNGLGETUNIFORMIVPROC, glGetUniformiv);\
mgll_loadGLFunc(PFNGLGETVERTEXATTRIBDVPROC, glGetVertexAttribdv);\
mgll_loadGLFunc(PFNGLGETVERTEXATTRIBFVPROC, glGetVertexAttribfv);\
mgll_loadGLFunc(PFNGLGETVERTEXATTRIBIVPROC, glGetVertexAttribiv);\
mgll_loadGLFunc(PFNGLGETVERTEXATTRIBPOINTERVPROC, glGetVertexAttribPointerv);\
mgll_loadGLFunc(PFNGLISPROGRAMPROC, glIsProgram);\
mgll_loadGLFunc(PFNGLISSHADERPROC, glIsShader);\
mgll_loadGLFunc(PFNGLLINKPROGRAMPROC, glLinkProgram);\
mgll_loadGLFunc(PFNGLSHADERSOURCEPROC, glShaderSource);\
mgll_loadGLFunc(PFNGLUSEPROGRAMPROC, glUseProgram);\
mgll_loadGLFunc(PFNGLUNIFORM1FPROC, glUniform1f);\
mgll_loadGLFunc(PFNGLUNIFORM2FPROC, glUniform2f);\
mgll_loadGLFunc(PFNGLUNIFORM3FPROC, glUniform3f);\
mgll_loadGLFunc(PFNGLUNIFORM4FPROC, glUniform4f);\
mgll_loadGLFunc(PFNGLUNIFORM1IPROC, glUniform1i);\
mgll_loadGLFunc(PFNGLUNIFORM2IPROC, glUniform2i);\
mgll_loadGLFunc(PFNGLUNIFORM3IPROC, glUniform3i);\
mgll_loadGLFunc(PFNGLUNIFORM4IPROC, glUniform4i);\
mgll_loadGLFunc(PFNGLUNIFORM1FVPROC, glUniform1fv);\
mgll_loadGLFunc(PFNGLUNIFORM2FVPROC, glUniform2fv);\
mgll_loadGLFunc(PFNGLUNIFORM3FVPROC, glUniform3fv);\
mgll_loadGLFunc(PFNGLUNIFORM4FVPROC, glUniform4fv);\
mgll_loadGLFunc(PFNGLUNIFORM1IVPROC, glUniform1iv);\
mgll_loadGLFunc(PFNGLUNIFORM2IVPROC, glUniform2iv);\
mgll_loadGLFunc(PFNGLUNIFORM3IVPROC, glUniform3iv);\
mgll_loadGLFunc(PFNGLUNIFORM4IVPROC, glUniform4iv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX2FVPROC, glUniformMatrix2fv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX3FVPROC, glUniformMatrix3fv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX4FVPROC, glUniformMatrix4fv);\
mgll_loadGLFunc(PFNGLVALIDATEPROGRAMPROC, glValidateProgram);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB1DPROC, glVertexAttrib1d);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB1DVPROC, glVertexAttrib1dv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB1FPROC, glVertexAttrib1f);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB1FVPROC, glVertexAttrib1fv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB1SPROC, glVertexAttrib1s);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB1SVPROC, glVertexAttrib1sv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB2DPROC, glVertexAttrib2d);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB2DVPROC, glVertexAttrib2dv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB2FPROC, glVertexAttrib2f);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB2FVPROC, glVertexAttrib2fv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB2SPROC, glVertexAttrib2s);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB2SVPROC, glVertexAttrib2sv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB3DPROC, glVertexAttrib3d);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB3DVPROC, glVertexAttrib3dv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB3FPROC, glVertexAttrib3f);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB3FVPROC, glVertexAttrib3fv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB3SPROC, glVertexAttrib3s);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB3SVPROC, glVertexAttrib3sv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4NBVPROC, glVertexAttrib4Nbv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4NIVPROC, glVertexAttrib4Niv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4NSVPROC, glVertexAttrib4Nsv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4NUBPROC, glVertexAttrib4Nub);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4NUBVPROC, glVertexAttrib4Nubv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4NUIVPROC, glVertexAttrib4Nuiv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4NUSVPROC, glVertexAttrib4Nusv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4BVPROC, glVertexAttrib4bv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4DPROC, glVertexAttrib4d);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4DVPROC, glVertexAttrib4dv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4FPROC, glVertexAttrib4f);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4FVPROC, glVertexAttrib4fv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4IVPROC, glVertexAttrib4iv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4SPROC, glVertexAttrib4s);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4SVPROC, glVertexAttrib4sv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4UBVPROC, glVertexAttrib4ubv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4UIVPROC, glVertexAttrib4uiv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIB4USVPROC, glVertexAttrib4usv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer);
#endif /* GL_VERSION_2_0 */
#ifdef GL_VERSION_2_1
#define MGLL_LOAD_GL_CORE_2_1_FUNC 	mgll_loadGLFunc(PFNGLUNIFORMMATRIX2X3FVPROC, glUniformMatrix2x3fv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX3X2FVPROC, glUniformMatrix3x2fv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX2X4FVPROC, glUniformMatrix2x4fv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX4X2FVPROC, glUniformMatrix4x2fv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX3X4FVPROC, glUniformMatrix3x4fv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX4X3FVPROC, glUniformMatrix4x3fv);
#endif /* GL_VERSION_2_1 */
#ifdef GL_VERSION_3_0
#define MGLL_LOAD_GL_CORE_3_0_FUNC mgll_loadGLFunc(PFNGLCOLORMASKIPROC, glColorMaski);\
mgll_loadGLFunc(PFNGLGETBOOLEANI_VPROC, glGetBooleani_v);\
mgll_loadGLFunc(PFNGLGETINTEGERI_VPROC, glGetIntegeri_v);\
mgll_loadGLFunc(PFNGLENABLEIPROC, glEnablei);\
mgll_loadGLFunc(PFNGLDISABLEIPROC, glDisablei);\
mgll_loadGLFunc(PFNGLISENABLEDIPROC, glIsEnabledi);\
mgll_loadGLFunc(PFNGLBEGINTRANSFORMFEEDBACKPROC, glBeginTransformFeedback);\
mgll_loadGLFunc(PFNGLENDTRANSFORMFEEDBACKPROC, glEndTransformFeedback);\
mgll_loadGLFunc(PFNGLBINDBUFFERRANGEPROC, glBindBufferRange);\
mgll_loadGLFunc(PFNGLBINDBUFFERBASEPROC, glBindBufferBase);\
mgll_loadGLFunc(PFNGLTRANSFORMFEEDBACKVARYINGSPROC, glTransformFeedbackVaryings);\
mgll_loadGLFunc(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, glGetTransformFeedbackVarying);\
mgll_loadGLFunc(PFNGLCLAMPCOLORPROC, glClampColor);\
mgll_loadGLFunc(PFNGLBEGINCONDITIONALRENDERPROC, glBeginConditionalRender);\
mgll_loadGLFunc(PFNGLENDCONDITIONALRENDERPROC, glEndConditionalRender);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBIPOINTERPROC, glVertexAttribIPointer);\
mgll_loadGLFunc(PFNGLGETVERTEXATTRIBIIVPROC, glGetVertexAttribIiv);\
mgll_loadGLFunc(PFNGLGETVERTEXATTRIBIUIVPROC, glGetVertexAttribIuiv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI1IPROC, glVertexAttribI1i);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI2IPROC, glVertexAttribI2i);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI3IPROC, glVertexAttribI3i);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI4IPROC, glVertexAttribI4i);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI1UIPROC, glVertexAttribI1ui);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI2UIPROC, glVertexAttribI2ui);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI3UIPROC, glVertexAttribI3ui);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI4UIPROC, glVertexAttribI4ui);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI1IVPROC, glVertexAttribI1iv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI2IVPROC, glVertexAttribI2iv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI3IVPROC, glVertexAttribI3iv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI4IVPROC, glVertexAttribI4iv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI1UIVPROC, glVertexAttribI1uiv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI2UIVPROC, glVertexAttribI2uiv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI3UIVPROC, glVertexAttribI3uiv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI4UIVPROC, glVertexAttribI4uiv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI4BVPROC, glVertexAttribI4bv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI4SVPROC, glVertexAttribI4sv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI4UBVPROC, glVertexAttribI4ubv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBI4USVPROC, glVertexAttribI4usv);\
mgll_loadGLFunc(PFNGLGETUNIFORMUIVPROC, glGetUniformuiv);\
mgll_loadGLFunc(PFNGLBINDFRAGDATALOCATIONPROC, glBindFragDataLocation);\
mgll_loadGLFunc(PFNGLGETFRAGDATALOCATIONPROC, glGetFragDataLocation);\
mgll_loadGLFunc(PFNGLUNIFORM1UIPROC, glUniform1ui);\
mgll_loadGLFunc(PFNGLUNIFORM2UIPROC, glUniform2ui);\
mgll_loadGLFunc(PFNGLUNIFORM3UIPROC, glUniform3ui);\
mgll_loadGLFunc(PFNGLUNIFORM4UIPROC, glUniform4ui);\
mgll_loadGLFunc(PFNGLUNIFORM1UIVPROC, glUniform1uiv);\
mgll_loadGLFunc(PFNGLUNIFORM2UIVPROC, glUniform2uiv);\
mgll_loadGLFunc(PFNGLUNIFORM3UIVPROC, glUniform3uiv);\
mgll_loadGLFunc(PFNGLUNIFORM4UIVPROC, glUniform4uiv);\
mgll_loadGLFunc(PFNGLTEXPARAMETERIIVPROC, glTexParameterIiv);\
mgll_loadGLFunc(PFNGLTEXPARAMETERIUIVPROC, glTexParameterIuiv);\
mgll_loadGLFunc(PFNGLGETTEXPARAMETERIIVPROC, glGetTexParameterIiv);\
mgll_loadGLFunc(PFNGLGETTEXPARAMETERIUIVPROC, glGetTexParameterIuiv);\
mgll_loadGLFunc(PFNGLCLEARBUFFERIVPROC, glClearBufferiv);\
mgll_loadGLFunc(PFNGLCLEARBUFFERUIVPROC, glClearBufferuiv);\
mgll_loadGLFunc(PFNGLCLEARBUFFERFVPROC, glClearBufferfv);\
mgll_loadGLFunc(PFNGLCLEARBUFFERFIPROC, glClearBufferfi);\
mgll_loadGLFunc(PFNGLGETSTRINGIPROC, glGetStringi);\
mgll_loadGLFunc(PFNGLISRENDERBUFFERPROC, glIsRenderbuffer);\
mgll_loadGLFunc(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer);\
mgll_loadGLFunc(PFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers);\
mgll_loadGLFunc(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers);\
mgll_loadGLFunc(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage);\
mgll_loadGLFunc(PFNGLGETRENDERBUFFERPARAMETERIVPROC, glGetRenderbufferParameteriv);\
mgll_loadGLFunc(PFNGLISFRAMEBUFFERPROC, glIsFramebuffer);\
mgll_loadGLFunc(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer);\
mgll_loadGLFunc(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers);\
mgll_loadGLFunc(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers);\
mgll_loadGLFunc(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus);\
mgll_loadGLFunc(PFNGLFRAMEBUFFERTEXTURE1DPROC, glFramebufferTexture1D);\
mgll_loadGLFunc(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D);\
mgll_loadGLFunc(PFNGLFRAMEBUFFERTEXTURE3DPROC, glFramebufferTexture3D);\
mgll_loadGLFunc(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer);\
mgll_loadGLFunc(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetFramebufferAttachmentParameteriv);\
mgll_loadGLFunc(PFNGLGENERATEMIPMAPPROC, glGenerateMipmap);\
mgll_loadGLFunc(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebuffer);\
mgll_loadGLFunc(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, glRenderbufferStorageMultisample);\
mgll_loadGLFunc(PFNGLFRAMEBUFFERTEXTURELAYERPROC, glFramebufferTextureLayer);\
mgll_loadGLFunc(PFNGLMAPBUFFERRANGEPROC, glMapBufferRange);\
mgll_loadGLFunc(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, glFlushMappedBufferRange);\
mgll_loadGLFunc(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray);\
mgll_loadGLFunc(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays);\
mgll_loadGLFunc(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays);\
mgll_loadGLFunc(PFNGLISVERTEXARRAYPROC, glIsVertexArray);
#endif /* GL_VERSION_3_0 */
#ifdef GL_VERSION_3_1
#define MGLL_LOAD_GL_CORE_3_1_FUNC 	mgll_loadGLFunc(PFNGLDRAWARRAYSINSTANCEDPROC, glDrawArraysInstanced);\
mgll_loadGLFunc(PFNGLDRAWELEMENTSINSTANCEDPROC, glDrawElementsInstanced);\
mgll_loadGLFunc(PFNGLTEXBUFFERPROC, glTexBuffer);\
mgll_loadGLFunc(PFNGLPRIMITIVERESTARTINDEXPROC, glPrimitiveRestartIndex);\
mgll_loadGLFunc(PFNGLCOPYBUFFERSUBDATAPROC, glCopyBufferSubData);\
mgll_loadGLFunc(PFNGLGETUNIFORMINDICESPROC, glGetUniformIndices);\
mgll_loadGLFunc(PFNGLGETACTIVEUNIFORMSIVPROC, glGetActiveUniformsiv);\
mgll_loadGLFunc(PFNGLGETACTIVEUNIFORMNAMEPROC, glGetActiveUniformName);\
mgll_loadGLFunc(PFNGLGETUNIFORMBLOCKINDEXPROC, glGetUniformBlockIndex);\
mgll_loadGLFunc(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, glGetActiveUniformBlockiv);\
mgll_loadGLFunc(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, glGetActiveUniformBlockName);\
mgll_loadGLFunc(PFNGLUNIFORMBLOCKBINDINGPROC, glUniformBlockBinding);
#endif /* GL_VERSION_3_1 */
#ifdef GL_VERSION_3_2
#define MGLL_LOAD_GL_CORE_3_2_FUNC 	mgll_loadGLFunc(PFNGLDRAWELEMENTSBASEVERTEXPROC, glDrawElementsBaseVertex);\
mgll_loadGLFunc(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, glDrawRangeElementsBaseVertex);\
mgll_loadGLFunc(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, glDrawElementsInstancedBaseVertex);\
mgll_loadGLFunc(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, glMultiDrawElementsBaseVertex);\
mgll_loadGLFunc(PFNGLPROVOKINGVERTEXPROC, glProvokingVertex);\
mgll_loadGLFunc(PFNGLFENCESYNCPROC, glFenceSync);\
mgll_loadGLFunc(PFNGLISSYNCPROC, glIsSync);\
mgll_loadGLFunc(PFNGLDELETESYNCPROC, glDeleteSync);\
mgll_loadGLFunc(PFNGLCLIENTWAITSYNCPROC, glClientWaitSync);\
mgll_loadGLFunc(PFNGLWAITSYNCPROC, glWaitSync);\
mgll_loadGLFunc(PFNGLGETINTEGER64VPROC, glGetInteger64v);\
mgll_loadGLFunc(PFNGLGETSYNCIVPROC, glGetSynciv);\
mgll_loadGLFunc(PFNGLGETINTEGER64I_VPROC, glGetInteger64i_v);\
mgll_loadGLFunc(PFNGLGETBUFFERPARAMETERI64VPROC, glGetBufferParameteri64v);\
mgll_loadGLFunc(PFNGLFRAMEBUFFERTEXTUREPROC, glFramebufferTexture);\
mgll_loadGLFunc(PFNGLTEXIMAGE2DMULTISAMPLEPROC, glTexImage2DMultisample);\
mgll_loadGLFunc(PFNGLTEXIMAGE3DMULTISAMPLEPROC, glTexImage3DMultisample);\
mgll_loadGLFunc(PFNGLGETMULTISAMPLEFVPROC, glGetMultisamplefv);\
mgll_loadGLFunc(PFNGLSAMPLEMASKIPROC, glSampleMaski);
#endif /* GL_VERSION_3_2 */
#ifdef GL_VERSION_3_3
#define MGLL_LOAD_GL_CORE_3_3_FUNC 	mgll_loadGLFunc(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, glBindFragDataLocationIndexed);\
mgll_loadGLFunc(PFNGLGETFRAGDATAINDEXPROC, glGetFragDataIndex);\
mgll_loadGLFunc(PFNGLGENSAMPLERSPROC, glGenSamplers);\
mgll_loadGLFunc(PFNGLDELETESAMPLERSPROC, glDeleteSamplers);\
mgll_loadGLFunc(PFNGLISSAMPLERPROC, glIsSampler);\
mgll_loadGLFunc(PFNGLBINDSAMPLERPROC, glBindSampler);\
mgll_loadGLFunc(PFNGLSAMPLERPARAMETERIPROC, glSamplerParameteri);\
mgll_loadGLFunc(PFNGLSAMPLERPARAMETERIVPROC, glSamplerParameteriv);\
mgll_loadGLFunc(PFNGLSAMPLERPARAMETERFPROC, glSamplerParameterf);\
mgll_loadGLFunc(PFNGLSAMPLERPARAMETERFVPROC, glSamplerParameterfv);\
mgll_loadGLFunc(PFNGLSAMPLERPARAMETERIIVPROC, glSamplerParameterIiv);\
mgll_loadGLFunc(PFNGLSAMPLERPARAMETERIUIVPROC, glSamplerParameterIuiv);\
mgll_loadGLFunc(PFNGLGETSAMPLERPARAMETERIVPROC, glGetSamplerParameteriv);\
mgll_loadGLFunc(PFNGLGETSAMPLERPARAMETERIIVPROC, glGetSamplerParameterIiv);\
mgll_loadGLFunc(PFNGLGETSAMPLERPARAMETERFVPROC, glGetSamplerParameterfv);\
mgll_loadGLFunc(PFNGLGETSAMPLERPARAMETERIUIVPROC, glGetSamplerParameterIuiv);\
mgll_loadGLFunc(PFNGLQUERYCOUNTERPROC, glQueryCounter);\
mgll_loadGLFunc(PFNGLGETQUERYOBJECTI64VPROC, glGetQueryObjecti64v);\
mgll_loadGLFunc(PFNGLGETQUERYOBJECTUI64VPROC, glGetQueryObjectui64v);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBDIVISORPROC, glVertexAttribDivisor);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBP1UIPROC, glVertexAttribP1ui);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBP1UIVPROC, glVertexAttribP1uiv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBP2UIPROC, glVertexAttribP2ui);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBP2UIVPROC, glVertexAttribP2uiv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBP3UIPROC, glVertexAttribP3ui);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBP3UIVPROC, glVertexAttribP3uiv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBP4UIPROC, glVertexAttribP4ui);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBP4UIVPROC, glVertexAttribP4uiv);
#endif /* GL_VERSION_3_3 */
#ifdef GL_VERSION_4_0
#define MGLL_LOAD_GL_CORE_4_0_FUNC mgll_loadGLFunc(PFNGLMINSAMPLESHADINGPROC, glMinSampleShading);\
mgll_loadGLFunc(PFNGLBLENDEQUATIONIPROC, glBlendEquationi);\
mgll_loadGLFunc(PFNGLBLENDEQUATIONSEPARATEIPROC, glBlendEquationSeparatei);\
mgll_loadGLFunc(PFNGLBLENDFUNCIPROC, glBlendFunci);\
mgll_loadGLFunc(PFNGLBLENDFUNCSEPARATEIPROC, glBlendFuncSeparatei);\
mgll_loadGLFunc(PFNGLDRAWARRAYSINDIRECTPROC, glDrawArraysIndirect);\
mgll_loadGLFunc(PFNGLDRAWELEMENTSINDIRECTPROC, glDrawElementsIndirect);\
mgll_loadGLFunc(PFNGLUNIFORM1DPROC, glUniform1d);\
mgll_loadGLFunc(PFNGLUNIFORM2DPROC, glUniform2d);\
mgll_loadGLFunc(PFNGLUNIFORM3DPROC, glUniform3d);\
mgll_loadGLFunc(PFNGLUNIFORM4DPROC, glUniform4d);\
mgll_loadGLFunc(PFNGLUNIFORM1DVPROC, glUniform1dv);\
mgll_loadGLFunc(PFNGLUNIFORM2DVPROC, glUniform2dv);\
mgll_loadGLFunc(PFNGLUNIFORM3DVPROC, glUniform3dv);\
mgll_loadGLFunc(PFNGLUNIFORM4DVPROC, glUniform4dv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX2DVPROC, glUniformMatrix2dv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX3DVPROC, glUniformMatrix3dv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX4DVPROC, glUniformMatrix4dv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX2X3DVPROC, glUniformMatrix2x3dv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX2X4DVPROC, glUniformMatrix2x4dv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX3X2DVPROC, glUniformMatrix3x2dv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX3X4DVPROC, glUniformMatrix3x4dv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX4X2DVPROC, glUniformMatrix4x2dv);\
mgll_loadGLFunc(PFNGLUNIFORMMATRIX4X3DVPROC, glUniformMatrix4x3dv);\
mgll_loadGLFunc(PFNGLGETUNIFORMDVPROC, glGetUniformdv);\
mgll_loadGLFunc(PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC, glGetSubroutineUniformLocation);\
mgll_loadGLFunc(PFNGLGETSUBROUTINEINDEXPROC, glGetSubroutineIndex);\
mgll_loadGLFunc(PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC, glGetActiveSubroutineUniformiv);\
mgll_loadGLFunc(PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC, glGetActiveSubroutineUniformName);\
mgll_loadGLFunc(PFNGLGETACTIVESUBROUTINENAMEPROC, glGetActiveSubroutineName);\
mgll_loadGLFunc(PFNGLUNIFORMSUBROUTINESUIVPROC, glUniformSubroutinesuiv);\
mgll_loadGLFunc(PFNGLGETUNIFORMSUBROUTINEUIVPROC, glGetUniformSubroutineuiv);\
mgll_loadGLFunc(PFNGLGETPROGRAMSTAGEIVPROC, glGetProgramStageiv);\
mgll_loadGLFunc(PFNGLPATCHPARAMETERIPROC, glPatchParameteri);\
mgll_loadGLFunc(PFNGLPATCHPARAMETERFVPROC, glPatchParameterfv);\
mgll_loadGLFunc(PFNGLBINDTRANSFORMFEEDBACKPROC, glBindTransformFeedback);\
mgll_loadGLFunc(PFNGLDELETETRANSFORMFEEDBACKSPROC, glDeleteTransformFeedbacks);\
mgll_loadGLFunc(PFNGLGENTRANSFORMFEEDBACKSPROC, glGenTransformFeedbacks);\
mgll_loadGLFunc(PFNGLISTRANSFORMFEEDBACKPROC, glIsTransformFeedback);\
mgll_loadGLFunc(PFNGLPAUSETRANSFORMFEEDBACKPROC, glPauseTransformFeedback);\
mgll_loadGLFunc(PFNGLRESUMETRANSFORMFEEDBACKPROC, glResumeTransformFeedback);\
mgll_loadGLFunc(PFNGLDRAWTRANSFORMFEEDBACKPROC, glDrawTransformFeedback);\
mgll_loadGLFunc(PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC, glDrawTransformFeedbackStream);\
mgll_loadGLFunc(PFNGLBEGINQUERYINDEXEDPROC, glBeginQueryIndexed);\
mgll_loadGLFunc(PFNGLENDQUERYINDEXEDPROC, glEndQueryIndexed);\
mgll_loadGLFunc(PFNGLGETQUERYINDEXEDIVPROC, glGetQueryIndexediv);
#endif /* GL_VERSION_4_0 */
#ifdef GL_VERSION_4_1
#define MGLL_LOAD_GL_CORE_4_1_FUNC mgll_loadGLFunc(PFNGLRELEASESHADERCOMPILERPROC, glReleaseShaderCompiler);\
mgll_loadGLFunc(PFNGLSHADERBINARYPROC, glShaderBinary);\
mgll_loadGLFunc(PFNGLGETSHADERPRECISIONFORMATPROC, glGetShaderPrecisionFormat);\
mgll_loadGLFunc(PFNGLDEPTHRANGEFPROC, glDepthRangef);\
mgll_loadGLFunc(PFNGLCLEARDEPTHFPROC, glClearDepthf);\
mgll_loadGLFunc(PFNGLGETPROGRAMBINARYPROC, glGetProgramBinary);\
mgll_loadGLFunc(PFNGLPROGRAMBINARYPROC, glProgramBinary);\
mgll_loadGLFunc(PFNGLPROGRAMPARAMETERIPROC, glProgramParameteri);\
mgll_loadGLFunc(PFNGLUSEPROGRAMSTAGESPROC, glUseProgramStages);\
mgll_loadGLFunc(PFNGLACTIVESHADERPROGRAMPROC, glActiveShaderProgram);\
mgll_loadGLFunc(PFNGLCREATESHADERPROGRAMVPROC, glCreateShaderProgramv);\
mgll_loadGLFunc(PFNGLBINDPROGRAMPIPELINEPROC, glBindProgramPipeline);\
mgll_loadGLFunc(PFNGLDELETEPROGRAMPIPELINESPROC, glDeleteProgramPipelines);\
mgll_loadGLFunc(PFNGLGENPROGRAMPIPELINESPROC, glGenProgramPipelines);\
mgll_loadGLFunc(PFNGLISPROGRAMPIPELINEPROC, glIsProgramPipeline);\
mgll_loadGLFunc(PFNGLGETPROGRAMPIPELINEIVPROC, glGetProgramPipelineiv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM1IPROC, glProgramUniform1i);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM1IVPROC, glProgramUniform1iv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM1FPROC, glProgramUniform1f);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM1FVPROC, glProgramUniform1fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM1DPROC, glProgramUniform1d);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM1DVPROC, glProgramUniform1dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM1UIPROC, glProgramUniform1ui);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM1UIVPROC, glProgramUniform1uiv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM2IPROC, glProgramUniform2i);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM2IVPROC, glProgramUniform2iv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM2FPROC, glProgramUniform2f);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM2FVPROC, glProgramUniform2fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM2DPROC, glProgramUniform2d);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM2DVPROC, glProgramUniform2dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM2UIPROC, glProgramUniform2ui);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM2UIVPROC, glProgramUniform2uiv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM3IPROC, glProgramUniform3i);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM3IVPROC, glProgramUniform3iv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM3FPROC, glProgramUniform3f);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM3FVPROC, glProgramUniform3fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM3DPROC, glProgramUniform3d);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM3DVPROC, glProgramUniform3dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM3UIPROC, glProgramUniform3ui);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM3UIVPROC, glProgramUniform3uiv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM4IPROC, glProgramUniform4i);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM4IVPROC, glProgramUniform4iv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM4FPROC, glProgramUniform4f);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM4FVPROC, glProgramUniform4fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM4DPROC, glProgramUniform4d);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM4DVPROC, glProgramUniform4dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM4UIPROC, glProgramUniform4ui);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORM4UIVPROC, glProgramUniform4uiv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2FVPROC, glProgramUniformMatrix2fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3FVPROC, glProgramUniformMatrix3fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4FVPROC, glProgramUniformMatrix4fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2DVPROC, glProgramUniformMatrix2dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3DVPROC, glProgramUniformMatrix3dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4DVPROC, glProgramUniformMatrix4dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC, glProgramUniformMatrix2x3fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC, glProgramUniformMatrix3x2fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC, glProgramUniformMatrix2x4fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC, glProgramUniformMatrix4x2fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC, glProgramUniformMatrix3x4fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC, glProgramUniformMatrix4x3fv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC, glProgramUniformMatrix2x3dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC, glProgramUniformMatrix3x2dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC, glProgramUniformMatrix2x4dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC, glProgramUniformMatrix4x2dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC, glProgramUniformMatrix3x4dv);\
mgll_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC, glProgramUniformMatrix4x3dv);\
mgll_loadGLFunc(PFNGLVALIDATEPROGRAMPIPELINEPROC, glValidateProgramPipeline);\
mgll_loadGLFunc(PFNGLGETPROGRAMPIPELINEINFOLOGPROC, glGetProgramPipelineInfoLog);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBL1DPROC, glVertexAttribL1d);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBL2DPROC, glVertexAttribL2d);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBL3DPROC, glVertexAttribL3d);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBL4DPROC, glVertexAttribL4d);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBL1DVPROC, glVertexAttribL1dv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBL2DVPROC, glVertexAttribL2dv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBL3DVPROC, glVertexAttribL3dv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBL4DVPROC, glVertexAttribL4dv);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBLPOINTERPROC, glVertexAttribLPointer);\
mgll_loadGLFunc(PFNGLGETVERTEXATTRIBLDVPROC, glGetVertexAttribLdv);\
mgll_loadGLFunc(PFNGLVIEWPORTARRAYVPROC, glViewportArrayv);\
mgll_loadGLFunc(PFNGLVIEWPORTINDEXEDFPROC, glViewportIndexedf);\
mgll_loadGLFunc(PFNGLVIEWPORTINDEXEDFVPROC, glViewportIndexedfv);\
mgll_loadGLFunc(PFNGLSCISSORARRAYVPROC, glScissorArrayv);\
mgll_loadGLFunc(PFNGLSCISSORINDEXEDPROC, glScissorIndexed);\
mgll_loadGLFunc(PFNGLSCISSORINDEXEDVPROC, glScissorIndexedv);\
mgll_loadGLFunc(PFNGLDEPTHRANGEARRAYVPROC, glDepthRangeArrayv);\
mgll_loadGLFunc(PFNGLDEPTHRANGEINDEXEDPROC, glDepthRangeIndexed);\
mgll_loadGLFunc(PFNGLGETFLOATI_VPROC, glGetFloati_v);\
mgll_loadGLFunc(PFNGLGETDOUBLEI_VPROC, glGetDoublei_v);
#endif /* GL_VERSION_4_1 */
#ifdef GL_VERSION_4_2
#define MGLL_LOAD_GL_CORE_4_2_FUNC mgll_loadGLFunc(PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC, glDrawArraysInstancedBaseInstance);\
mgll_loadGLFunc(PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC, glDrawElementsInstancedBaseInstance);\
mgll_loadGLFunc(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC, glDrawElementsInstancedBaseVertexBaseInstance);\
mgll_loadGLFunc(PFNGLGETINTERNALFORMATIVPROC, glGetInternalformativ);\
mgll_loadGLFunc(PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC, glGetActiveAtomicCounterBufferiv);\
mgll_loadGLFunc(PFNGLBINDIMAGETEXTUREPROC, glBindImageTexture);\
mgll_loadGLFunc(PFNGLMEMORYBARRIERPROC, glMemoryBarrier);\
mgll_loadGLFunc(PFNGLTEXSTORAGE1DPROC, glTexStorage1D);\
mgll_loadGLFunc(PFNGLTEXSTORAGE2DPROC, glTexStorage2D);\
mgll_loadGLFunc(PFNGLTEXSTORAGE3DPROC, glTexStorage3D);\
mgll_loadGLFunc(PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC, glDrawTransformFeedbackInstanced);\
mgll_loadGLFunc(PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC, glDrawTransformFeedbackStreamInstanced);
#endif /* GL_VERSION_4_2 */
#ifdef GL_VERSION_4_3
#define MGLL_LOAD_GL_CORE_4_3_FUNC mgll_loadGLFunc(PFNGLCLEARBUFFERDATAPROC, glClearBufferData);\
mgll_loadGLFunc(PFNGLCLEARBUFFERSUBDATAPROC, glClearBufferSubData);\
mgll_loadGLFunc(PFNGLDISPATCHCOMPUTEPROC, glDispatchCompute);\
mgll_loadGLFunc(PFNGLDISPATCHCOMPUTEINDIRECTPROC, glDispatchComputeIndirect);\
mgll_loadGLFunc(PFNGLCOPYIMAGESUBDATAPROC, glCopyImageSubData);\
mgll_loadGLFunc(PFNGLFRAMEBUFFERPARAMETERIPROC, glFramebufferParameteri);\
mgll_loadGLFunc(PFNGLGETFRAMEBUFFERPARAMETERIVPROC, glGetFramebufferParameteriv);\
mgll_loadGLFunc(PFNGLGETINTERNALFORMATI64VPROC, glGetInternalformati64v);\
mgll_loadGLFunc(PFNGLINVALIDATETEXSUBIMAGEPROC, glInvalidateTexSubImage);\
mgll_loadGLFunc(PFNGLINVALIDATETEXIMAGEPROC, glInvalidateTexImage);\
mgll_loadGLFunc(PFNGLINVALIDATEBUFFERSUBDATAPROC, glInvalidateBufferSubData);\
mgll_loadGLFunc(PFNGLINVALIDATEBUFFERDATAPROC, glInvalidateBufferData);\
mgll_loadGLFunc(PFNGLINVALIDATEFRAMEBUFFERPROC, glInvalidateFramebuffer);\
mgll_loadGLFunc(PFNGLINVALIDATESUBFRAMEBUFFERPROC, glInvalidateSubFramebuffer);\
mgll_loadGLFunc(PFNGLMULTIDRAWARRAYSINDIRECTPROC, glMultiDrawArraysIndirect);\
mgll_loadGLFunc(PFNGLMULTIDRAWELEMENTSINDIRECTPROC, glMultiDrawElementsIndirect);\
mgll_loadGLFunc(PFNGLGETPROGRAMINTERFACEIVPROC, glGetProgramInterfaceiv);\
mgll_loadGLFunc(PFNGLGETPROGRAMRESOURCEINDEXPROC, glGetProgramResourceIndex);\
mgll_loadGLFunc(PFNGLGETPROGRAMRESOURCENAMEPROC, glGetProgramResourceName);\
mgll_loadGLFunc(PFNGLGETPROGRAMRESOURCEIVPROC, glGetProgramResourceiv);\
mgll_loadGLFunc(PFNGLGETPROGRAMRESOURCELOCATIONPROC, glGetProgramResourceLocation);\
mgll_loadGLFunc(PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC, glGetProgramResourceLocationIndex);\
mgll_loadGLFunc(PFNGLSHADERSTORAGEBLOCKBINDINGPROC, glShaderStorageBlockBinding);\
mgll_loadGLFunc(PFNGLTEXBUFFERRANGEPROC, glTexBufferRange);\
mgll_loadGLFunc(PFNGLTEXSTORAGE2DMULTISAMPLEPROC, glTexStorage2DMultisample);\
mgll_loadGLFunc(PFNGLTEXSTORAGE3DMULTISAMPLEPROC, glTexStorage3DMultisample);\
mgll_loadGLFunc(PFNGLTEXTUREVIEWPROC, glTextureView);\
mgll_loadGLFunc(PFNGLBINDVERTEXBUFFERPROC, glBindVertexBuffer);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBFORMATPROC, glVertexAttribFormat);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBIFORMATPROC, glVertexAttribIFormat);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBLFORMATPROC, glVertexAttribLFormat);\
mgll_loadGLFunc(PFNGLVERTEXATTRIBBINDINGPROC, glVertexAttribBinding);\
mgll_loadGLFunc(PFNGLVERTEXBINDINGDIVISORPROC, glVertexBindingDivisor);\
mgll_loadGLFunc(PFNGLDEBUGMESSAGECONTROLPROC, glDebugMessageControl);\
mgll_loadGLFunc(PFNGLDEBUGMESSAGEINSERTPROC, glDebugMessageInsert);\
mgll_loadGLFunc(PFNGLDEBUGMESSAGECALLBACKPROC, glDebugMessageCallback);\
mgll_loadGLFunc(PFNGLGETDEBUGMESSAGELOGPROC, glGetDebugMessageLog);\
mgll_loadGLFunc(PFNGLPUSHDEBUGGROUPPROC, glPushDebugGroup);\
mgll_loadGLFunc(PFNGLPOPDEBUGGROUPPROC, glPopDebugGroup);\
mgll_loadGLFunc(PFNGLOBJECTLABELPROC, glObjectLabel);\
mgll_loadGLFunc(PFNGLGETOBJECTLABELPROC, glGetObjectLabel);\
mgll_loadGLFunc(PFNGLOBJECTPTRLABELPROC, glObjectPtrLabel);\
mgll_loadGLFunc(PFNGLGETOBJECTPTRLABELPROC, glGetObjectPtrLabel);
#endif /* GL_VERSION_4_3 */
#ifdef GL_VERSION_4_4
#define MGLL_LOAD_GL_CORE_4_4_FUNC mgll_loadGLFunc(PFNGLBUFFERSTORAGEPROC, glBufferStorage);\
mgll_loadGLFunc(PFNGLCLEARTEXIMAGEPROC, glClearTexImage);\
mgll_loadGLFunc(PFNGLCLEARTEXSUBIMAGEPROC, glClearTexSubImage);\
mgll_loadGLFunc(PFNGLBINDBUFFERSBASEPROC, glBindBuffersBase);\
mgll_loadGLFunc(PFNGLBINDBUFFERSRANGEPROC, glBindBuffersRange);\
mgll_loadGLFunc(PFNGLBINDTEXTURESPROC, glBindTextures);\
mgll_loadGLFunc(PFNGLBINDSAMPLERSPROC, glBindSamplers);\
mgll_loadGLFunc(PFNGLBINDIMAGETEXTURESPROC, glBindImageTextures);\
mgll_loadGLFunc(PFNGLBINDVERTEXBUFFERSPROC, glBindVertexBuffers);
#endif /* GL_VERSION_4_4 */
#ifdef GL_VERSION_4_5
#define MGLL_LOAD_GL_CORE_4_5_FUNC mgll_loadGLFunc(PFNGLCLIPCONTROLPROC, glClipControl);\
mgll_loadGLFunc(PFNGLCREATETRANSFORMFEEDBACKSPROC, glCreateTransformFeedbacks);\
mgll_loadGLFunc(PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC, glTransformFeedbackBufferBase);\
mgll_loadGLFunc(PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC, glTransformFeedbackBufferRange);\
mgll_loadGLFunc(PFNGLGETTRANSFORMFEEDBACKIVPROC, glGetTransformFeedbackiv);\
mgll_loadGLFunc(PFNGLGETTRANSFORMFEEDBACKI_VPROC, glGetTransformFeedbacki_v);\
mgll_loadGLFunc(PFNGLGETTRANSFORMFEEDBACKI64_VPROC, glGetTransformFeedbacki64_v);\
mgll_loadGLFunc(PFNGLCREATEBUFFERSPROC, glCreateBuffers);\
mgll_loadGLFunc(PFNGLNAMEDBUFFERSTORAGEPROC, glNamedBufferStorage);\
mgll_loadGLFunc(PFNGLNAMEDBUFFERDATAPROC, glNamedBufferData);\
mgll_loadGLFunc(PFNGLNAMEDBUFFERSUBDATAPROC, glNamedBufferSubData);\
mgll_loadGLFunc(PFNGLCOPYNAMEDBUFFERSUBDATAPROC, glCopyNamedBufferSubData);\
mgll_loadGLFunc(PFNGLCLEARNAMEDBUFFERDATAPROC, glClearNamedBufferData);\
mgll_loadGLFunc(PFNGLCLEARNAMEDBUFFERSUBDATAPROC, glClearNamedBufferSubData);\
mgll_loadGLFunc(PFNGLMAPNAMEDBUFFERPROC, glMapNamedBuffer);\
mgll_loadGLFunc(PFNGLMAPNAMEDBUFFERRANGEPROC, glMapNamedBufferRange);\
mgll_loadGLFunc(PFNGLUNMAPNAMEDBUFFERPROC, glUnmapNamedBuffer);\
mgll_loadGLFunc(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC, glFlushMappedNamedBufferRange);\
mgll_loadGLFunc(PFNGLGETNAMEDBUFFERPARAMETERIVPROC, glGetNamedBufferParameteriv);\
mgll_loadGLFunc(PFNGLGETNAMEDBUFFERPARAMETERI64VPROC, glGetNamedBufferParameteri64v);\
mgll_loadGLFunc(PFNGLGETNAMEDBUFFERPOINTERVPROC, glGetNamedBufferPointerv);\
mgll_loadGLFunc(PFNGLGETNAMEDBUFFERSUBDATAPROC, glGetNamedBufferSubData);\
mgll_loadGLFunc(PFNGLCREATEFRAMEBUFFERSPROC, glCreateFramebuffers);\
mgll_loadGLFunc(PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC, glNamedFramebufferRenderbuffer);\
mgll_loadGLFunc(PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC, glNamedFramebufferParameteri);\
mgll_loadGLFunc(PFNGLNAMEDFRAMEBUFFERTEXTUREPROC, glNamedFramebufferTexture);\
mgll_loadGLFunc(PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC, glNamedFramebufferTextureLayer);\
mgll_loadGLFunc(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC, glNamedFramebufferDrawBuffer);\
mgll_loadGLFunc(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC, glNamedFramebufferDrawBuffers);\
mgll_loadGLFunc(PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC, glNamedFramebufferReadBuffer);\
mgll_loadGLFunc(PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC, glInvalidateNamedFramebufferData);\
mgll_loadGLFunc(PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC, glInvalidateNamedFramebufferSubData);\
mgll_loadGLFunc(PFNGLCLEARNAMEDFRAMEBUFFERIVPROC, glClearNamedFramebufferiv);\
mgll_loadGLFunc(PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC, glClearNamedFramebufferuiv);\
mgll_loadGLFunc(PFNGLCLEARNAMEDFRAMEBUFFERFVPROC, glClearNamedFramebufferfv);\
mgll_loadGLFunc(PFNGLCLEARNAMEDFRAMEBUFFERFIPROC, glClearNamedFramebufferfi);\
mgll_loadGLFunc(PFNGLBLITNAMEDFRAMEBUFFERPROC, glBlitNamedFramebuffer);\
mgll_loadGLFunc(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC, glCheckNamedFramebufferStatus);\
mgll_loadGLFunc(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC, glGetNamedFramebufferParameteriv);\
mgll_loadGLFunc(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetNamedFramebufferAttachmentParameteriv);\
mgll_loadGLFunc(PFNGLCREATERENDERBUFFERSPROC, glCreateRenderbuffers);\
mgll_loadGLFunc(PFNGLNAMEDRENDERBUFFERSTORAGEPROC, glNamedRenderbufferStorage);\
mgll_loadGLFunc(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC, glNamedRenderbufferStorageMultisample);\
mgll_loadGLFunc(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC, glGetNamedRenderbufferParameteriv);\
mgll_loadGLFunc(PFNGLCREATETEXTURESPROC, glCreateTextures);\
mgll_loadGLFunc(PFNGLTEXTUREBUFFERPROC, glTextureBuffer);\
mgll_loadGLFunc(PFNGLTEXTUREBUFFERRANGEPROC, glTextureBufferRange);\
mgll_loadGLFunc(PFNGLTEXTURESTORAGE1DPROC, glTextureStorage1D);\
mgll_loadGLFunc(PFNGLTEXTURESTORAGE2DPROC, glTextureStorage2D);\
mgll_loadGLFunc(PFNGLTEXTURESTORAGE3DPROC, glTextureStorage3D);\
mgll_loadGLFunc(PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC, glTextureStorage2DMultisample);\
mgll_loadGLFunc(PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC, glTextureStorage3DMultisample);\
mgll_loadGLFunc(PFNGLTEXTURESUBIMAGE1DPROC, glTextureSubImage1D);\
mgll_loadGLFunc(PFNGLTEXTURESUBIMAGE2DPROC, glTextureSubImage2D);\
mgll_loadGLFunc(PFNGLTEXTURESUBIMAGE3DPROC, glTextureSubImage3D);\
mgll_loadGLFunc(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC, glCompressedTextureSubImage1D);\
mgll_loadGLFunc(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC, glCompressedTextureSubImage2D);\
mgll_loadGLFunc(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC, glCompressedTextureSubImage3D);\
mgll_loadGLFunc(PFNGLCOPYTEXTURESUBIMAGE1DPROC, glCopyTextureSubImage1D);\
mgll_loadGLFunc(PFNGLCOPYTEXTURESUBIMAGE2DPROC, glCopyTextureSubImage2D);\
mgll_loadGLFunc(PFNGLCOPYTEXTURESUBIMAGE3DPROC, glCopyTextureSubImage3D);\
mgll_loadGLFunc(PFNGLTEXTUREPARAMETERFPROC, glTextureParameterf);\
mgll_loadGLFunc(PFNGLTEXTUREPARAMETERFVPROC, glTextureParameterfv);\
mgll_loadGLFunc(PFNGLTEXTUREPARAMETERIPROC, glTextureParameteri);\
mgll_loadGLFunc(PFNGLTEXTUREPARAMETERIIVPROC, glTextureParameterIiv);\
mgll_loadGLFunc(PFNGLTEXTUREPARAMETERIUIVPROC, glTextureParameterIuiv);\
mgll_loadGLFunc(PFNGLTEXTUREPARAMETERIVPROC, glTextureParameteriv);\
mgll_loadGLFunc(PFNGLGENERATETEXTUREMIPMAPPROC, glGenerateTextureMipmap);\
mgll_loadGLFunc(PFNGLBINDTEXTUREUNITPROC, glBindTextureUnit);\
mgll_loadGLFunc(PFNGLGETTEXTUREIMAGEPROC, glGetTextureImage);\
mgll_loadGLFunc(PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC, glGetCompressedTextureImage);\
mgll_loadGLFunc(PFNGLGETTEXTURELEVELPARAMETERFVPROC, glGetTextureLevelParameterfv);\
mgll_loadGLFunc(PFNGLGETTEXTURELEVELPARAMETERIVPROC, glGetTextureLevelParameteriv);\
mgll_loadGLFunc(PFNGLGETTEXTUREPARAMETERFVPROC, glGetTextureParameterfv);\
mgll_loadGLFunc(PFNGLGETTEXTUREPARAMETERIIVPROC, glGetTextureParameterIiv);\
mgll_loadGLFunc(PFNGLGETTEXTUREPARAMETERIUIVPROC, glGetTextureParameterIuiv);\
mgll_loadGLFunc(PFNGLGETTEXTUREPARAMETERIVPROC, glGetTextureParameteriv);\
mgll_loadGLFunc(PFNGLCREATEVERTEXARRAYSPROC, glCreateVertexArrays);\
mgll_loadGLFunc(PFNGLDISABLEVERTEXARRAYATTRIBPROC, glDisableVertexArrayAttrib);\
mgll_loadGLFunc(PFNGLENABLEVERTEXARRAYATTRIBPROC, glEnableVertexArrayAttrib);\
mgll_loadGLFunc(PFNGLVERTEXARRAYELEMENTBUFFERPROC, glVertexArrayElementBuffer);\
mgll_loadGLFunc(PFNGLVERTEXARRAYVERTEXBUFFERPROC, glVertexArrayVertexBuffer);\
mgll_loadGLFunc(PFNGLVERTEXARRAYVERTEXBUFFERSPROC, glVertexArrayVertexBuffers);\
mgll_loadGLFunc(PFNGLVERTEXARRAYATTRIBBINDINGPROC, glVertexArrayAttribBinding);\
mgll_loadGLFunc(PFNGLVERTEXARRAYATTRIBFORMATPROC, glVertexArrayAttribFormat);\
mgll_loadGLFunc(PFNGLVERTEXARRAYATTRIBIFORMATPROC, glVertexArrayAttribIFormat);\
mgll_loadGLFunc(PFNGLVERTEXARRAYATTRIBLFORMATPROC, glVertexArrayAttribLFormat);\
mgll_loadGLFunc(PFNGLVERTEXARRAYBINDINGDIVISORPROC, glVertexArrayBindingDivisor);\
mgll_loadGLFunc(PFNGLGETVERTEXARRAYIVPROC, glGetVertexArrayiv);\
mgll_loadGLFunc(PFNGLGETVERTEXARRAYINDEXEDIVPROC, glGetVertexArrayIndexediv);\
mgll_loadGLFunc(PFNGLGETVERTEXARRAYINDEXED64IVPROC, glGetVertexArrayIndexed64iv);\
mgll_loadGLFunc(PFNGLCREATESAMPLERSPROC, glCreateSamplers);\
mgll_loadGLFunc(PFNGLCREATEPROGRAMPIPELINESPROC, glCreateProgramPipelines);\
mgll_loadGLFunc(PFNGLCREATEQUERIESPROC, glCreateQueries);\
mgll_loadGLFunc(PFNGLGETQUERYBUFFEROBJECTI64VPROC, glGetQueryBufferObjecti64v);\
mgll_loadGLFunc(PFNGLGETQUERYBUFFEROBJECTIVPROC, glGetQueryBufferObjectiv);\
mgll_loadGLFunc(PFNGLGETQUERYBUFFEROBJECTUI64VPROC, glGetQueryBufferObjectui64v);\
mgll_loadGLFunc(PFNGLGETQUERYBUFFEROBJECTUIVPROC, glGetQueryBufferObjectuiv);\
mgll_loadGLFunc(PFNGLMEMORYBARRIERBYREGIONPROC, glMemoryBarrierByRegion);\
mgll_loadGLFunc(PFNGLGETTEXTURESUBIMAGEPROC, glGetTextureSubImage);\
mgll_loadGLFunc(PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC, glGetCompressedTextureSubImage);\
mgll_loadGLFunc(PFNGLGETGRAPHICSRESETSTATUSPROC, glGetGraphicsResetStatus);\
mgll_loadGLFunc(PFNGLGETNCOMPRESSEDTEXIMAGEPROC, glGetnCompressedTexImage);\
mgll_loadGLFunc(PFNGLGETNTEXIMAGEPROC, glGetnTexImage);\
mgll_loadGLFunc(PFNGLGETNUNIFORMDVPROC, glGetnUniformdv);\
mgll_loadGLFunc(PFNGLGETNUNIFORMFVPROC, glGetnUniformfv);\
mgll_loadGLFunc(PFNGLGETNUNIFORMIVPROC, glGetnUniformiv);\
mgll_loadGLFunc(PFNGLGETNUNIFORMUIVPROC, glGetnUniformuiv);\
mgll_loadGLFunc(PFNGLREADNPIXELSPROC, glReadnPixels);\
mgll_loadGLFunc(PFNGLTEXTUREBARRIERPROC, glTextureBarrier);
#endif /* GL_VERSION_4_5 */
#ifdef GL_VERSION_4_6
#define MGLL_LOAD_GL_CORE_4_6_FUNC mgll_loadGLFunc(PFNGLSPECIALIZESHADERPROC, glSpecializeShader);\
mgll_loadGLFunc(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC, glMultiDrawArraysIndirectCount);\
mgll_loadGLFunc(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC, glMultiDrawElementsIndirectCount);\
mgll_loadGLFunc(PFNGLPOLYGONOFFSETCLAMPPROC, glPolygonOffsetClamp);
#endif /* GL_VERSION_4_6 */
#endif /* MGLL_GL_CORE_PROFILE */

#ifndef MGLL_LOAD_GL_CORE_1_0_FUNC
#define MGLL_LOAD_GL_CORE_1_0_FUNC
#endif /* MGLL_LOAD_GL_CORE_1_0_FUNC */
#ifndef MGLL_LOAD_GL_CORE_1_1_FUNC
#define MGLL_LOAD_GL_CORE_1_1_FUNC
#endif /* MGLL_LOAD_GL_CORE__1_FUNC */
#ifndef MGLL_LOAD_GL_CORE_1_2_FUNC
#define MGLL_LOAD_GL_CORE_1_2_FUNC
#endif /* MGLL_LOAD_GL_CORE_1_2_FUNC */
#ifndef MGLL_LOAD_GL_CORE_1_3_FUNC
#define MGLL_LOAD_GL_CORE_1_3_FUNC
#endif /* MGLL_LOAD_GL_CORE_1_3_FUNC */
#ifndef MGLL_LOAD_GL_CORE_1_4_FUNC
#define MGLL_LOAD_GL_CORE_1_4_FUNC
#endif /* MGLL_LOAD_GL_CORE_1_4_FUNC */
#ifndef MGLL_LOAD_GL_CORE_1_5_FUNC
#define MGLL_LOAD_GL_CORE_1_5_FUNC
#endif /* MGLL_LOAD_GL_CORE_1_5_FUNC */
#ifndef MGLL_LOAD_GL_CORE_2_0_FUNC
#define MGLL_LOAD_GL_CORE_2_0_FUNC
#endif /* MGLL_LOAD_GL_CORE_2_0_FUNC */
#ifndef MGLL_LOAD_GL_CORE_2_1_FUNC
#define MGLL_LOAD_GL_CORE_2_1_FUNC
#endif /* MGLL_LOAD_GL_CORE_2_1_FUNC */
#ifndef MGLL_LOAD_GL_CORE_3_0_FUNC
#define MGLL_LOAD_GL_CORE_3_0_FUNC
#endif /* MGLL_LOAD_GL_CORE_3_0_FUNC */
#ifndef MGLL_LOAD_GL_CORE_3_1_FUNC
#define MGLL_LOAD_GL_CORE_3_1_FUNC
#endif /* MGLL_LOAD_GL_CORE_3_1_FUNC */
#ifndef MGLL_LOAD_GL_CORE_3_2_FUNC
#define MGLL_LOAD_GL_CORE_3_2_FUNC
#endif /* MGLL_LOAD_GL_CORE_3_2_FUNC */
#ifndef MGLL_LOAD_GL_CORE_3_3_FUNC
#define MGLL_LOAD_GL_CORE_3_3_FUNC
#endif /* MGLL_LOAD_GL_CORE_3_3_FUNC */
#ifndef MGLL_LOAD_GL_CORE_4_0_FUNC
#define MGLL_LOAD_GL_CORE_4_0_FUNC
#endif /* MGLL_LOAD_GL_CORE_4_0_FUNC */
#ifndef MGLL_LOAD_GL_CORE_4_1_FUNC
#define MGLL_LOAD_GL_CORE_4_1_FUNC
#endif /* MGLL_LOAD_GL_CORE_4_1_FUNC */
#ifndef MGLL_LOAD_GL_CORE_4_2_FUNC
#define MGLL_LOAD_GL_CORE_4_2_FUNC
#endif /* MGLL_LOAD_GL_CORE_4_2_FUNC */
#ifndef MGLL_LOAD_GL_CORE_4_3_FUNC
#define MGLL_LOAD_GL_CORE_4_3_FUNC
#endif /* MGLL_LOAD_GL_CORE_4_3_FUNC */
#ifndef MGLL_LOAD_GL_CORE_4_4_FUNC
#define MGLL_LOAD_GL_CORE_4_4_FUNC
#endif /* MGLL_LOAD_GL_CORE_4_4_FUNC */
#ifndef MGLL_LOAD_GL_CORE_4_5_FUNC
#define MGLL_LOAD_GL_CORE_4_5_FUNC
#endif /* MGLL_LOAD_GL_CORE_4_5_FUNC */
#ifndef MGLL_LOAD_GL_CORE_4_6_FUNC
#define MGLL_LOAD_GL_CORE_4_6_FUNC
#endif /* MGLL_LOAD_GL_CORE_4_6_FUNC */

int mgll_init(void) {
	MGLL_LOAD_GL_CORE_1_0_FUNC
	MGLL_LOAD_GL_CORE_1_1_FUNC
	MGLL_LOAD_GL_CORE_1_2_FUNC
	MGLL_LOAD_GL_CORE_1_3_FUNC
	MGLL_LOAD_GL_CORE_1_4_FUNC
	MGLL_LOAD_GL_CORE_1_5_FUNC
	MGLL_LOAD_GL_CORE_2_0_FUNC
	MGLL_LOAD_GL_CORE_2_1_FUNC
	MGLL_LOAD_GL_CORE_3_0_FUNC
	MGLL_LOAD_GL_CORE_3_1_FUNC
	MGLL_LOAD_GL_CORE_3_2_FUNC
	MGLL_LOAD_GL_CORE_3_3_FUNC
	MGLL_LOAD_GL_CORE_4_0_FUNC
	MGLL_LOAD_GL_CORE_4_1_FUNC
	MGLL_LOAD_GL_CORE_4_2_FUNC
	MGLL_LOAD_GL_CORE_4_3_FUNC
	MGLL_LOAD_GL_CORE_4_4_FUNC
	MGLL_LOAD_GL_CORE_4_5_FUNC
	MGLL_LOAD_GL_CORE_4_6_FUNC

	return 1;
}