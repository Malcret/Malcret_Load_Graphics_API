#include "MLGA/OpenGL/opengl.h"

#include <stdio.h>

#ifdef _WIN32
#define mlga_glGetProcAddress(name) wglGetProcAddress(name)

void *mlga_getGLFuncAddress(const char *name) {
	void *p = (void *)mlga_glGetProcAddress(name);

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
#define mlga_glGetProcAddress(name) glXGetProcAddress((const GLubyte *)name)

#include <dlfcn.h>

void *mlga_getGLFuncAddress(const char *name) {
	void *p = (void *)mlga_glGetProcAddress(name);

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

#define mlga_loadGLFunc(type, name) type name = (type)mlga_getGLFuncAddress(#name);

#ifdef MLGA_GL_CORE_PROFILE
#ifdef GL_VERSION_1_0
#define MLGA_LOAD_GL_CORE_1_0_FUNC mlga_loadGLFunc(PFNGLCULLFACEPROC, glCullFace);\
mlga_loadGLFunc(PFNGLFRONTFACEPROC, glFrontFace);\
mlga_loadGLFunc(PFNGLHINTPROC, glHint);\
mlga_loadGLFunc(PFNGLLINEWIDTHPROC, glLineWidth);\
mlga_loadGLFunc(PFNGLPOINTSIZEPROC, glPointSize);\
mlga_loadGLFunc(PFNGLPOLYGONMODEPROC, glPolygonMode);\
mlga_loadGLFunc(PFNGLSCISSORPROC, glScissor);\
mlga_loadGLFunc(PFNGLTEXPARAMETERFPROC, glTexParameterf);\
mlga_loadGLFunc(PFNGLTEXPARAMETERFVPROC, glTexParameterfv);\
mlga_loadGLFunc(PFNGLTEXPARAMETERIPROC, glTexParameteri);\
mlga_loadGLFunc(PFNGLTEXPARAMETERIVPROC, glTexParameteriv);\
mlga_loadGLFunc(PFNGLTEXIMAGE1DPROC, glTexImage1D);\
mlga_loadGLFunc(PFNGLTEXIMAGE2DPROC, glTexImage2D);\
mlga_loadGLFunc(PFNGLDRAWBUFFERPROC, glDrawBuffer);\
mlga_loadGLFunc(PFNGLCLEARPROC, glClear);\
mlga_loadGLFunc(PFNGLCLEARCOLORPROC, glClearColor);\
mlga_loadGLFunc(PFNGLCLEARSTENCILPROC, glClearStencil);\
mlga_loadGLFunc(PFNGLCLEARDEPTHPROC, glClearDepth);\
mlga_loadGLFunc(PFNGLSTENCILMASKPROC, glStencilMask);\
mlga_loadGLFunc(PFNGLCOLORMASKPROC, glColorMask);\
mlga_loadGLFunc(PFNGLDEPTHMASKPROC, glDepthMask);\
mlga_loadGLFunc(PFNGLDISABLEPROC, glDisable);\
mlga_loadGLFunc(PFNGLENABLEPROC, glEnable);\
mlga_loadGLFunc(PFNGLFINISHPROC, glFinish);\
mlga_loadGLFunc(PFNGLFLUSHPROC, glFlush);\
mlga_loadGLFunc(PFNGLBLENDFUNCPROC, glBlendFunc);\
mlga_loadGLFunc(PFNGLLOGICOPPROC, glLogicOp);\
mlga_loadGLFunc(PFNGLSTENCILFUNCPROC, glStencilFunc);\
mlga_loadGLFunc(PFNGLSTENCILOPPROC, glStencilOp);\
mlga_loadGLFunc(PFNGLDEPTHFUNCPROC, glDepthFunc);\
mlga_loadGLFunc(PFNGLPIXELSTOREFPROC, glPixelStoref);\
mlga_loadGLFunc(PFNGLPIXELSTOREIPROC, glPixelStorei);\
mlga_loadGLFunc(PFNGLREADBUFFERPROC, glReadBuffer);\
mlga_loadGLFunc(PFNGLREADPIXELSPROC, glReadPixels);\
mlga_loadGLFunc(PFNGLGETBOOLEANVPROC, glGetBooleanv);\
mlga_loadGLFunc(PFNGLGETDOUBLEVPROC, glGetDoublev);\
mlga_loadGLFunc(PFNGLGETERRORPROC, glGetError);\
mlga_loadGLFunc(PFNGLGETFLOATVPROC, glGetFloatv);\
mlga_loadGLFunc(PFNGLGETINTEGERVPROC, glGetIntegerv);\
mlga_loadGLFunc(PFNGLGETSTRINGPROC, glGetString);\
mlga_loadGLFunc(PFNGLGETTEXIMAGEPROC, glGetTexImage);\
mlga_loadGLFunc(PFNGLGETTEXPARAMETERFVPROC, glGetTexParameterfv);\
mlga_loadGLFunc(PFNGLGETTEXPARAMETERIVPROC, glGetTexParameteriv);\
mlga_loadGLFunc(PFNGLGETTEXLEVELPARAMETERFVPROC, glGetTexLevelParameterfv);\
mlga_loadGLFunc(PFNGLGETTEXLEVELPARAMETERIVPROC, glGetTexLevelParameteriv);\
mlga_loadGLFunc(PFNGLISENABLEDPROC, glIsEnabled);\
mlga_loadGLFunc(PFNGLDEPTHRANGEPROC, glDepthRange);\
mlga_loadGLFunc(PFNGLVIEWPORTPROC, glViewport);
#endif /* GL_VERSION_1_0 */
#ifdef GL_VERSION_1_1
#define MLGA_LOAD_GL_CORE_1_1_FUNC 	mlga_loadGLFunc(PFNGLDRAWARRAYSPROC, glDrawArrays);\
mlga_loadGLFunc(PFNGLDRAWELEMENTSPROC, glDrawElements);\
mlga_loadGLFunc(PFNGLGETPOINTERVPROC, glGetPointerv);\
mlga_loadGLFunc(PFNGLPOLYGONOFFSETPROC, glPolygonOffset);\
mlga_loadGLFunc(PFNGLCOPYTEXIMAGE1DPROC, glCopyTexImage1D);\
mlga_loadGLFunc(PFNGLCOPYTEXIMAGE2DPROC, glCopyTexImage2D);\
mlga_loadGLFunc(PFNGLCOPYTEXSUBIMAGE1DPROC, glCopyTexSubImage1D);\
mlga_loadGLFunc(PFNGLCOPYTEXSUBIMAGE2DPROC, glCopyTexSubImage2D);\
mlga_loadGLFunc(PFNGLTEXSUBIMAGE1DPROC, glTexSubImage1D);\
mlga_loadGLFunc(PFNGLTEXSUBIMAGE2DPROC, glTexSubImage2D);\
mlga_loadGLFunc(PFNGLBINDTEXTUREPROC, glBindTexture);\
mlga_loadGLFunc(PFNGLDELETETEXTURESPROC, glDeleteTextures);\
mlga_loadGLFunc(PFNGLGENTEXTURESPROC, glGenTextures);\
mlga_loadGLFunc(PFNGLISTEXTUREPROC, glIsTexture);
#endif /* GL_VERSION_1_1 */
#ifdef GL_VERSION_1_2
#define MLGA_LOAD_GL_CORE_1_2_FUNC mlga_loadGLFunc(PFNGLDRAWRANGEELEMENTSPROC, glDrawRangeElements);\
mlga_loadGLFunc(PFNGLTEXIMAGE3DPROC, glTexImage3D);\
mlga_loadGLFunc(PFNGLTEXSUBIMAGE3DPROC, glTexSubImage3D);\
mlga_loadGLFunc(PFNGLCOPYTEXSUBIMAGE3DPROC, glCopyTexSubImage3D);
#endif /* GL_VERSION_1_2 */
#ifdef GL_VERSION_1_3
#define MLGA_LOAD_GL_CORE_1_3_FUNC 	mlga_loadGLFunc(PFNGLACTIVETEXTUREPROC, glActiveTexture);\
mlga_loadGLFunc(PFNGLSAMPLECOVERAGEPROC, glSampleCoverage);\
mlga_loadGLFunc(PFNGLCOMPRESSEDTEXIMAGE3DPROC, glCompressedTexImage3D);\
mlga_loadGLFunc(PFNGLCOMPRESSEDTEXIMAGE2DPROC, glCompressedTexImage2D);\
mlga_loadGLFunc(PFNGLCOMPRESSEDTEXIMAGE1DPROC, glCompressedTexImage1D);\
mlga_loadGLFunc(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, glCompressedTexSubImage3D);\
mlga_loadGLFunc(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, glCompressedTexSubImage2D);\
mlga_loadGLFunc(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, glCompressedTexSubImage1D);\
mlga_loadGLFunc(PFNGLGETCOMPRESSEDTEXIMAGEPROC, glGetCompressedTexImage);
#endif /* GL_VERSION_1_3 */
#ifdef GL_VERSION_1_4
#define MLGA_LOAD_GL_CORE_1_4_FUNC 	mlga_loadGLFunc(PFNGLBLENDFUNCSEPARATEPROC, glBlendFuncSeparate);\
mlga_loadGLFunc(PFNGLMULTIDRAWARRAYSPROC, glMultiDrawArrays);\
mlga_loadGLFunc(PFNGLMULTIDRAWELEMENTSPROC, glMultiDrawElements);\
mlga_loadGLFunc(PFNGLPOINTPARAMETERFPROC, glPointParameterf);\
mlga_loadGLFunc(PFNGLPOINTPARAMETERFVPROC, glPointParameterfv);\
mlga_loadGLFunc(PFNGLPOINTPARAMETERIPROC, glPointParameteri);\
mlga_loadGLFunc(PFNGLPOINTPARAMETERIVPROC, glPointParameteriv);\
mlga_loadGLFunc(PFNGLBLENDCOLORPROC, glBlendColor);\
mlga_loadGLFunc(PFNGLBLENDEQUATIONPROC, glBlendEquation);
#endif /* GL_VERSION_1_4 */
#ifdef GL_VERSION_1_4
#define MLGA_LOAD_GL_CORE_1_5_FUNC 	mlga_loadGLFunc(PFNGLGENQUERIESPROC, glGenQueries);\
mlga_loadGLFunc(PFNGLDELETEQUERIESPROC, glDeleteQueries);\
mlga_loadGLFunc(PFNGLISQUERYPROC, glIsQuery);\
mlga_loadGLFunc(PFNGLBEGINQUERYPROC, glBeginQuery);\
mlga_loadGLFunc(PFNGLENDQUERYPROC, glEndQuery);\
mlga_loadGLFunc(PFNGLGETQUERYIVPROC, glGetQueryiv);\
mlga_loadGLFunc(PFNGLGETQUERYOBJECTIVPROC, glGetQueryObjectiv);\
mlga_loadGLFunc(PFNGLGETQUERYOBJECTUIVPROC, glGetQueryObjectuiv);\
mlga_loadGLFunc(PFNGLBINDBUFFERPROC, glBindBuffer);\
mlga_loadGLFunc(PFNGLDELETEBUFFERSPROC, glDeleteBuffers);\
mlga_loadGLFunc(PFNGLGENBUFFERSPROC, glGenBuffers);\
mlga_loadGLFunc(PFNGLISBUFFERPROC, glIsBuffer);\
mlga_loadGLFunc(PFNGLBUFFERDATAPROC, glBufferData);\
mlga_loadGLFunc(PFNGLBUFFERSUBDATAPROC, glBufferSubData);\
mlga_loadGLFunc(PFNGLGETBUFFERSUBDATAPROC, glGetBufferSubData);\
mlga_loadGLFunc(PFNGLMAPBUFFERPROC, glMapBuffer);\
mlga_loadGLFunc(PFNGLUNMAPBUFFERPROC, glUnmapBuffer);\
mlga_loadGLFunc(PFNGLGETBUFFERPARAMETERIVPROC, glGetBufferParameteriv);\
mlga_loadGLFunc(PFNGLGETBUFFERPOINTERVPROC, glGetBufferPointerv);
#endif /* GL_VERSION_1_5 */
#ifdef GL_VERSION_2_0
#define MLGA_LOAD_GL_CORE_2_0_FUNC mlga_loadGLFunc(PFNGLBLENDEQUATIONSEPARATEPROC, glBlendEquationSeparate);\
mlga_loadGLFunc(PFNGLDRAWBUFFERSPROC, glDrawBuffers);\
mlga_loadGLFunc(PFNGLSTENCILOPSEPARATEPROC, glStencilOpSeparate);\
mlga_loadGLFunc(PFNGLSTENCILFUNCSEPARATEPROC, glStencilFuncSeparate);\
mlga_loadGLFunc(PFNGLSTENCILMASKSEPARATEPROC, glStencilMaskSeparate);\
mlga_loadGLFunc(PFNGLATTACHSHADERPROC, glAttachShader);\
mlga_loadGLFunc(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation);\
mlga_loadGLFunc(PFNGLCOMPILESHADERPROC, glCompileShader);\
mlga_loadGLFunc(PFNGLCREATEPROGRAMPROC, glCreateProgram);\
mlga_loadGLFunc(PFNGLCREATESHADERPROC, glCreateShader);\
mlga_loadGLFunc(PFNGLDELETEPROGRAMPROC, glDeleteProgram);\
mlga_loadGLFunc(PFNGLDELETESHADERPROC, glDeleteShader);\
mlga_loadGLFunc(PFNGLDETACHSHADERPROC, glDetachShader);\
mlga_loadGLFunc(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray);\
mlga_loadGLFunc(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray);\
mlga_loadGLFunc(PFNGLGETACTIVEATTRIBPROC, glGetActiveAttrib);\
mlga_loadGLFunc(PFNGLGETACTIVEUNIFORMPROC, glGetActiveUniform);\
mlga_loadGLFunc(PFNGLGETATTACHEDSHADERSPROC, glGetAttachedShaders);\
mlga_loadGLFunc(PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation);\
mlga_loadGLFunc(PFNGLGETPROGRAMIVPROC, glGetProgramiv);\
mlga_loadGLFunc(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog);\
mlga_loadGLFunc(PFNGLGETSHADERIVPROC, glGetShaderiv);\
mlga_loadGLFunc(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog);\
mlga_loadGLFunc(PFNGLGETSHADERSOURCEPROC, glGetShaderSource);\
mlga_loadGLFunc(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation);\
mlga_loadGLFunc(PFNGLGETUNIFORMFVPROC, glGetUniformfv);\
mlga_loadGLFunc(PFNGLGETUNIFORMIVPROC, glGetUniformiv);\
mlga_loadGLFunc(PFNGLGETVERTEXATTRIBDVPROC, glGetVertexAttribdv);\
mlga_loadGLFunc(PFNGLGETVERTEXATTRIBFVPROC, glGetVertexAttribfv);\
mlga_loadGLFunc(PFNGLGETVERTEXATTRIBIVPROC, glGetVertexAttribiv);\
mlga_loadGLFunc(PFNGLGETVERTEXATTRIBPOINTERVPROC, glGetVertexAttribPointerv);\
mlga_loadGLFunc(PFNGLISPROGRAMPROC, glIsProgram);\
mlga_loadGLFunc(PFNGLISSHADERPROC, glIsShader);\
mlga_loadGLFunc(PFNGLLINKPROGRAMPROC, glLinkProgram);\
mlga_loadGLFunc(PFNGLSHADERSOURCEPROC, glShaderSource);\
mlga_loadGLFunc(PFNGLUSEPROGRAMPROC, glUseProgram);\
mlga_loadGLFunc(PFNGLUNIFORM1FPROC, glUniform1f);\
mlga_loadGLFunc(PFNGLUNIFORM2FPROC, glUniform2f);\
mlga_loadGLFunc(PFNGLUNIFORM3FPROC, glUniform3f);\
mlga_loadGLFunc(PFNGLUNIFORM4FPROC, glUniform4f);\
mlga_loadGLFunc(PFNGLUNIFORM1IPROC, glUniform1i);\
mlga_loadGLFunc(PFNGLUNIFORM2IPROC, glUniform2i);\
mlga_loadGLFunc(PFNGLUNIFORM3IPROC, glUniform3i);\
mlga_loadGLFunc(PFNGLUNIFORM4IPROC, glUniform4i);\
mlga_loadGLFunc(PFNGLUNIFORM1FVPROC, glUniform1fv);\
mlga_loadGLFunc(PFNGLUNIFORM2FVPROC, glUniform2fv);\
mlga_loadGLFunc(PFNGLUNIFORM3FVPROC, glUniform3fv);\
mlga_loadGLFunc(PFNGLUNIFORM4FVPROC, glUniform4fv);\
mlga_loadGLFunc(PFNGLUNIFORM1IVPROC, glUniform1iv);\
mlga_loadGLFunc(PFNGLUNIFORM2IVPROC, glUniform2iv);\
mlga_loadGLFunc(PFNGLUNIFORM3IVPROC, glUniform3iv);\
mlga_loadGLFunc(PFNGLUNIFORM4IVPROC, glUniform4iv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX2FVPROC, glUniformMatrix2fv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX3FVPROC, glUniformMatrix3fv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX4FVPROC, glUniformMatrix4fv);\
mlga_loadGLFunc(PFNGLVALIDATEPROGRAMPROC, glValidateProgram);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB1DPROC, glVertexAttrib1d);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB1DVPROC, glVertexAttrib1dv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB1FPROC, glVertexAttrib1f);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB1FVPROC, glVertexAttrib1fv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB1SPROC, glVertexAttrib1s);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB1SVPROC, glVertexAttrib1sv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB2DPROC, glVertexAttrib2d);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB2DVPROC, glVertexAttrib2dv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB2FPROC, glVertexAttrib2f);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB2FVPROC, glVertexAttrib2fv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB2SPROC, glVertexAttrib2s);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB2SVPROC, glVertexAttrib2sv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB3DPROC, glVertexAttrib3d);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB3DVPROC, glVertexAttrib3dv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB3FPROC, glVertexAttrib3f);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB3FVPROC, glVertexAttrib3fv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB3SPROC, glVertexAttrib3s);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB3SVPROC, glVertexAttrib3sv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4NBVPROC, glVertexAttrib4Nbv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4NIVPROC, glVertexAttrib4Niv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4NSVPROC, glVertexAttrib4Nsv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4NUBPROC, glVertexAttrib4Nub);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4NUBVPROC, glVertexAttrib4Nubv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4NUIVPROC, glVertexAttrib4Nuiv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4NUSVPROC, glVertexAttrib4Nusv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4BVPROC, glVertexAttrib4bv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4DPROC, glVertexAttrib4d);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4DVPROC, glVertexAttrib4dv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4FPROC, glVertexAttrib4f);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4FVPROC, glVertexAttrib4fv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4IVPROC, glVertexAttrib4iv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4SPROC, glVertexAttrib4s);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4SVPROC, glVertexAttrib4sv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4UBVPROC, glVertexAttrib4ubv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4UIVPROC, glVertexAttrib4uiv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIB4USVPROC, glVertexAttrib4usv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer);
#endif /* GL_VERSION_2_0 */
#ifdef GL_VERSION_2_1
#define MLGA_LOAD_GL_CORE_2_1_FUNC 	mlga_loadGLFunc(PFNGLUNIFORMMATRIX2X3FVPROC, glUniformMatrix2x3fv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX3X2FVPROC, glUniformMatrix3x2fv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX2X4FVPROC, glUniformMatrix2x4fv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX4X2FVPROC, glUniformMatrix4x2fv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX3X4FVPROC, glUniformMatrix3x4fv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX4X3FVPROC, glUniformMatrix4x3fv);
#endif /* GL_VERSION_2_1 */
#ifdef GL_VERSION_3_0
#define MLGA_LOAD_GL_CORE_3_0_FUNC mlga_loadGLFunc(PFNGLCOLORMASKIPROC, glColorMaski);\
mlga_loadGLFunc(PFNGLGETBOOLEANI_VPROC, glGetBooleani_v);\
mlga_loadGLFunc(PFNGLGETINTEGERI_VPROC, glGetIntegeri_v);\
mlga_loadGLFunc(PFNGLENABLEIPROC, glEnablei);\
mlga_loadGLFunc(PFNGLDISABLEIPROC, glDisablei);\
mlga_loadGLFunc(PFNGLISENABLEDIPROC, glIsEnabledi);\
mlga_loadGLFunc(PFNGLBEGINTRANSFORMFEEDBACKPROC, glBeginTransformFeedback);\
mlga_loadGLFunc(PFNGLENDTRANSFORMFEEDBACKPROC, glEndTransformFeedback);\
mlga_loadGLFunc(PFNGLBINDBUFFERRANGEPROC, glBindBufferRange);\
mlga_loadGLFunc(PFNGLBINDBUFFERBASEPROC, glBindBufferBase);\
mlga_loadGLFunc(PFNGLTRANSFORMFEEDBACKVARYINGSPROC, glTransformFeedbackVaryings);\
mlga_loadGLFunc(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, glGetTransformFeedbackVarying);\
mlga_loadGLFunc(PFNGLCLAMPCOLORPROC, glClampColor);\
mlga_loadGLFunc(PFNGLBEGINCONDITIONALRENDERPROC, glBeginConditionalRender);\
mlga_loadGLFunc(PFNGLENDCONDITIONALRENDERPROC, glEndConditionalRender);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBIPOINTERPROC, glVertexAttribIPointer);\
mlga_loadGLFunc(PFNGLGETVERTEXATTRIBIIVPROC, glGetVertexAttribIiv);\
mlga_loadGLFunc(PFNGLGETVERTEXATTRIBIUIVPROC, glGetVertexAttribIuiv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI1IPROC, glVertexAttribI1i);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI2IPROC, glVertexAttribI2i);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI3IPROC, glVertexAttribI3i);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI4IPROC, glVertexAttribI4i);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI1UIPROC, glVertexAttribI1ui);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI2UIPROC, glVertexAttribI2ui);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI3UIPROC, glVertexAttribI3ui);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI4UIPROC, glVertexAttribI4ui);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI1IVPROC, glVertexAttribI1iv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI2IVPROC, glVertexAttribI2iv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI3IVPROC, glVertexAttribI3iv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI4IVPROC, glVertexAttribI4iv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI1UIVPROC, glVertexAttribI1uiv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI2UIVPROC, glVertexAttribI2uiv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI3UIVPROC, glVertexAttribI3uiv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI4UIVPROC, glVertexAttribI4uiv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI4BVPROC, glVertexAttribI4bv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI4SVPROC, glVertexAttribI4sv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI4UBVPROC, glVertexAttribI4ubv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBI4USVPROC, glVertexAttribI4usv);\
mlga_loadGLFunc(PFNGLGETUNIFORMUIVPROC, glGetUniformuiv);\
mlga_loadGLFunc(PFNGLBINDFRAGDATALOCATIONPROC, glBindFragDataLocation);\
mlga_loadGLFunc(PFNGLGETFRAGDATALOCATIONPROC, glGetFragDataLocation);\
mlga_loadGLFunc(PFNGLUNIFORM1UIPROC, glUniform1ui);\
mlga_loadGLFunc(PFNGLUNIFORM2UIPROC, glUniform2ui);\
mlga_loadGLFunc(PFNGLUNIFORM3UIPROC, glUniform3ui);\
mlga_loadGLFunc(PFNGLUNIFORM4UIPROC, glUniform4ui);\
mlga_loadGLFunc(PFNGLUNIFORM1UIVPROC, glUniform1uiv);\
mlga_loadGLFunc(PFNGLUNIFORM2UIVPROC, glUniform2uiv);\
mlga_loadGLFunc(PFNGLUNIFORM3UIVPROC, glUniform3uiv);\
mlga_loadGLFunc(PFNGLUNIFORM4UIVPROC, glUniform4uiv);\
mlga_loadGLFunc(PFNGLTEXPARAMETERIIVPROC, glTexParameterIiv);\
mlga_loadGLFunc(PFNGLTEXPARAMETERIUIVPROC, glTexParameterIuiv);\
mlga_loadGLFunc(PFNGLGETTEXPARAMETERIIVPROC, glGetTexParameterIiv);\
mlga_loadGLFunc(PFNGLGETTEXPARAMETERIUIVPROC, glGetTexParameterIuiv);\
mlga_loadGLFunc(PFNGLCLEARBUFFERIVPROC, glClearBufferiv);\
mlga_loadGLFunc(PFNGLCLEARBUFFERUIVPROC, glClearBufferuiv);\
mlga_loadGLFunc(PFNGLCLEARBUFFERFVPROC, glClearBufferfv);\
mlga_loadGLFunc(PFNGLCLEARBUFFERFIPROC, glClearBufferfi);\
mlga_loadGLFunc(PFNGLGETSTRINGIPROC, glGetStringi);\
mlga_loadGLFunc(PFNGLISRENDERBUFFERPROC, glIsRenderbuffer);\
mlga_loadGLFunc(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer);\
mlga_loadGLFunc(PFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers);\
mlga_loadGLFunc(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers);\
mlga_loadGLFunc(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage);\
mlga_loadGLFunc(PFNGLGETRENDERBUFFERPARAMETERIVPROC, glGetRenderbufferParameteriv);\
mlga_loadGLFunc(PFNGLISFRAMEBUFFERPROC, glIsFramebuffer);\
mlga_loadGLFunc(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer);\
mlga_loadGLFunc(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers);\
mlga_loadGLFunc(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers);\
mlga_loadGLFunc(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus);\
mlga_loadGLFunc(PFNGLFRAMEBUFFERTEXTURE1DPROC, glFramebufferTexture1D);\
mlga_loadGLFunc(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D);\
mlga_loadGLFunc(PFNGLFRAMEBUFFERTEXTURE3DPROC, glFramebufferTexture3D);\
mlga_loadGLFunc(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer);\
mlga_loadGLFunc(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetFramebufferAttachmentParameteriv);\
mlga_loadGLFunc(PFNGLGENERATEMIPMAPPROC, glGenerateMipmap);\
mlga_loadGLFunc(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebuffer);\
mlga_loadGLFunc(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, glRenderbufferStorageMultisample);\
mlga_loadGLFunc(PFNGLFRAMEBUFFERTEXTURELAYERPROC, glFramebufferTextureLayer);\
mlga_loadGLFunc(PFNGLMAPBUFFERRANGEPROC, glMapBufferRange);\
mlga_loadGLFunc(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, glFlushMappedBufferRange);\
mlga_loadGLFunc(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray);\
mlga_loadGLFunc(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays);\
mlga_loadGLFunc(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays);\
mlga_loadGLFunc(PFNGLISVERTEXARRAYPROC, glIsVertexArray);
#endif /* GL_VERSION_3_0 */
#ifdef GL_VERSION_3_1
#define MLGA_LOAD_GL_CORE_3_1_FUNC 	mlga_loadGLFunc(PFNGLDRAWARRAYSINSTANCEDPROC, glDrawArraysInstanced);\
mlga_loadGLFunc(PFNGLDRAWELEMENTSINSTANCEDPROC, glDrawElementsInstanced);\
mlga_loadGLFunc(PFNGLTEXBUFFERPROC, glTexBuffer);\
mlga_loadGLFunc(PFNGLPRIMITIVERESTARTINDEXPROC, glPrimitiveRestartIndex);\
mlga_loadGLFunc(PFNGLCOPYBUFFERSUBDATAPROC, glCopyBufferSubData);\
mlga_loadGLFunc(PFNGLGETUNIFORMINDICESPROC, glGetUniformIndices);\
mlga_loadGLFunc(PFNGLGETACTIVEUNIFORMSIVPROC, glGetActiveUniformsiv);\
mlga_loadGLFunc(PFNGLGETACTIVEUNIFORMNAMEPROC, glGetActiveUniformName);\
mlga_loadGLFunc(PFNGLGETUNIFORMBLOCKINDEXPROC, glGetUniformBlockIndex);\
mlga_loadGLFunc(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, glGetActiveUniformBlockiv);\
mlga_loadGLFunc(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, glGetActiveUniformBlockName);\
mlga_loadGLFunc(PFNGLUNIFORMBLOCKBINDINGPROC, glUniformBlockBinding);
#endif /* GL_VERSION_3_1 */
#ifdef GL_VERSION_3_2
#define MLGA_LOAD_GL_CORE_3_2_FUNC 	mlga_loadGLFunc(PFNGLDRAWELEMENTSBASEVERTEXPROC, glDrawElementsBaseVertex);\
mlga_loadGLFunc(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, glDrawRangeElementsBaseVertex);\
mlga_loadGLFunc(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, glDrawElementsInstancedBaseVertex);\
mlga_loadGLFunc(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, glMultiDrawElementsBaseVertex);\
mlga_loadGLFunc(PFNGLPROVOKINGVERTEXPROC, glProvokingVertex);\
mlga_loadGLFunc(PFNGLFENCESYNCPROC, glFenceSync);\
mlga_loadGLFunc(PFNGLISSYNCPROC, glIsSync);\
mlga_loadGLFunc(PFNGLDELETESYNCPROC, glDeleteSync);\
mlga_loadGLFunc(PFNGLCLIENTWAITSYNCPROC, glClientWaitSync);\
mlga_loadGLFunc(PFNGLWAITSYNCPROC, glWaitSync);\
mlga_loadGLFunc(PFNGLGETINTEGER64VPROC, glGetInteger64v);\
mlga_loadGLFunc(PFNGLGETSYNCIVPROC, glGetSynciv);\
mlga_loadGLFunc(PFNGLGETINTEGER64I_VPROC, glGetInteger64i_v);\
mlga_loadGLFunc(PFNGLGETBUFFERPARAMETERI64VPROC, glGetBufferParameteri64v);\
mlga_loadGLFunc(PFNGLFRAMEBUFFERTEXTUREPROC, glFramebufferTexture);\
mlga_loadGLFunc(PFNGLTEXIMAGE2DMULTISAMPLEPROC, glTexImage2DMultisample);\
mlga_loadGLFunc(PFNGLTEXIMAGE3DMULTISAMPLEPROC, glTexImage3DMultisample);\
mlga_loadGLFunc(PFNGLGETMULTISAMPLEFVPROC, glGetMultisamplefv);\
mlga_loadGLFunc(PFNGLSAMPLEMASKIPROC, glSampleMaski);
#endif /* GL_VERSION_3_2 */
#ifdef GL_VERSION_3_3
#define MLGA_LOAD_GL_CORE_3_3_FUNC 	mlga_loadGLFunc(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, glBindFragDataLocationIndexed);\
mlga_loadGLFunc(PFNGLGETFRAGDATAINDEXPROC, glGetFragDataIndex);\
mlga_loadGLFunc(PFNGLGENSAMPLERSPROC, glGenSamplers);\
mlga_loadGLFunc(PFNGLDELETESAMPLERSPROC, glDeleteSamplers);\
mlga_loadGLFunc(PFNGLISSAMPLERPROC, glIsSampler);\
mlga_loadGLFunc(PFNGLBINDSAMPLERPROC, glBindSampler);\
mlga_loadGLFunc(PFNGLSAMPLERPARAMETERIPROC, glSamplerParameteri);\
mlga_loadGLFunc(PFNGLSAMPLERPARAMETERIVPROC, glSamplerParameteriv);\
mlga_loadGLFunc(PFNGLSAMPLERPARAMETERFPROC, glSamplerParameterf);\
mlga_loadGLFunc(PFNGLSAMPLERPARAMETERFVPROC, glSamplerParameterfv);\
mlga_loadGLFunc(PFNGLSAMPLERPARAMETERIIVPROC, glSamplerParameterIiv);\
mlga_loadGLFunc(PFNGLSAMPLERPARAMETERIUIVPROC, glSamplerParameterIuiv);\
mlga_loadGLFunc(PFNGLGETSAMPLERPARAMETERIVPROC, glGetSamplerParameteriv);\
mlga_loadGLFunc(PFNGLGETSAMPLERPARAMETERIIVPROC, glGetSamplerParameterIiv);\
mlga_loadGLFunc(PFNGLGETSAMPLERPARAMETERFVPROC, glGetSamplerParameterfv);\
mlga_loadGLFunc(PFNGLGETSAMPLERPARAMETERIUIVPROC, glGetSamplerParameterIuiv);\
mlga_loadGLFunc(PFNGLQUERYCOUNTERPROC, glQueryCounter);\
mlga_loadGLFunc(PFNGLGETQUERYOBJECTI64VPROC, glGetQueryObjecti64v);\
mlga_loadGLFunc(PFNGLGETQUERYOBJECTUI64VPROC, glGetQueryObjectui64v);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBDIVISORPROC, glVertexAttribDivisor);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBP1UIPROC, glVertexAttribP1ui);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBP1UIVPROC, glVertexAttribP1uiv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBP2UIPROC, glVertexAttribP2ui);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBP2UIVPROC, glVertexAttribP2uiv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBP3UIPROC, glVertexAttribP3ui);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBP3UIVPROC, glVertexAttribP3uiv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBP4UIPROC, glVertexAttribP4ui);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBP4UIVPROC, glVertexAttribP4uiv);
#endif /* GL_VERSION_3_3 */
#ifdef GL_VERSION_4_0
#define MLGA_LOAD_GL_CORE_4_0_FUNC mlga_loadGLFunc(PFNGLMINSAMPLESHADINGPROC, glMinSampleShading);\
mlga_loadGLFunc(PFNGLBLENDEQUATIONIPROC, glBlendEquationi);\
mlga_loadGLFunc(PFNGLBLENDEQUATIONSEPARATEIPROC, glBlendEquationSeparatei);\
mlga_loadGLFunc(PFNGLBLENDFUNCIPROC, glBlendFunci);\
mlga_loadGLFunc(PFNGLBLENDFUNCSEPARATEIPROC, glBlendFuncSeparatei);\
mlga_loadGLFunc(PFNGLDRAWARRAYSINDIRECTPROC, glDrawArraysIndirect);\
mlga_loadGLFunc(PFNGLDRAWELEMENTSINDIRECTPROC, glDrawElementsIndirect);\
mlga_loadGLFunc(PFNGLUNIFORM1DPROC, glUniform1d);\
mlga_loadGLFunc(PFNGLUNIFORM2DPROC, glUniform2d);\
mlga_loadGLFunc(PFNGLUNIFORM3DPROC, glUniform3d);\
mlga_loadGLFunc(PFNGLUNIFORM4DPROC, glUniform4d);\
mlga_loadGLFunc(PFNGLUNIFORM1DVPROC, glUniform1dv);\
mlga_loadGLFunc(PFNGLUNIFORM2DVPROC, glUniform2dv);\
mlga_loadGLFunc(PFNGLUNIFORM3DVPROC, glUniform3dv);\
mlga_loadGLFunc(PFNGLUNIFORM4DVPROC, glUniform4dv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX2DVPROC, glUniformMatrix2dv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX3DVPROC, glUniformMatrix3dv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX4DVPROC, glUniformMatrix4dv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX2X3DVPROC, glUniformMatrix2x3dv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX2X4DVPROC, glUniformMatrix2x4dv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX3X2DVPROC, glUniformMatrix3x2dv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX3X4DVPROC, glUniformMatrix3x4dv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX4X2DVPROC, glUniformMatrix4x2dv);\
mlga_loadGLFunc(PFNGLUNIFORMMATRIX4X3DVPROC, glUniformMatrix4x3dv);\
mlga_loadGLFunc(PFNGLGETUNIFORMDVPROC, glGetUniformdv);\
mlga_loadGLFunc(PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC, glGetSubroutineUniformLocation);\
mlga_loadGLFunc(PFNGLGETSUBROUTINEINDEXPROC, glGetSubroutineIndex);\
mlga_loadGLFunc(PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC, glGetActiveSubroutineUniformiv);\
mlga_loadGLFunc(PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC, glGetActiveSubroutineUniformName);\
mlga_loadGLFunc(PFNGLGETACTIVESUBROUTINENAMEPROC, glGetActiveSubroutineName);\
mlga_loadGLFunc(PFNGLUNIFORMSUBROUTINESUIVPROC, glUniformSubroutinesuiv);\
mlga_loadGLFunc(PFNGLGETUNIFORMSUBROUTINEUIVPROC, glGetUniformSubroutineuiv);\
mlga_loadGLFunc(PFNGLGETPROGRAMSTAGEIVPROC, glGetProgramStageiv);\
mlga_loadGLFunc(PFNGLPATCHPARAMETERIPROC, glPatchParameteri);\
mlga_loadGLFunc(PFNGLPATCHPARAMETERFVPROC, glPatchParameterfv);\
mlga_loadGLFunc(PFNGLBINDTRANSFORMFEEDBACKPROC, glBindTransformFeedback);\
mlga_loadGLFunc(PFNGLDELETETRANSFORMFEEDBACKSPROC, glDeleteTransformFeedbacks);\
mlga_loadGLFunc(PFNGLGENTRANSFORMFEEDBACKSPROC, glGenTransformFeedbacks);\
mlga_loadGLFunc(PFNGLISTRANSFORMFEEDBACKPROC, glIsTransformFeedback);\
mlga_loadGLFunc(PFNGLPAUSETRANSFORMFEEDBACKPROC, glPauseTransformFeedback);\
mlga_loadGLFunc(PFNGLRESUMETRANSFORMFEEDBACKPROC, glResumeTransformFeedback);\
mlga_loadGLFunc(PFNGLDRAWTRANSFORMFEEDBACKPROC, glDrawTransformFeedback);\
mlga_loadGLFunc(PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC, glDrawTransformFeedbackStream);\
mlga_loadGLFunc(PFNGLBEGINQUERYINDEXEDPROC, glBeginQueryIndexed);\
mlga_loadGLFunc(PFNGLENDQUERYINDEXEDPROC, glEndQueryIndexed);\
mlga_loadGLFunc(PFNGLGETQUERYINDEXEDIVPROC, glGetQueryIndexediv);
#endif /* GL_VERSION_4_0 */
#ifdef GL_VERSION_4_1
#define MLGA_LOAD_GL_CORE_4_1_FUNC mlga_loadGLFunc(PFNGLRELEASESHADERCOMPILERPROC, glReleaseShaderCompiler);\
mlga_loadGLFunc(PFNGLSHADERBINARYPROC, glShaderBinary);\
mlga_loadGLFunc(PFNGLGETSHADERPRECISIONFORMATPROC, glGetShaderPrecisionFormat);\
mlga_loadGLFunc(PFNGLDEPTHRANGEFPROC, glDepthRangef);\
mlga_loadGLFunc(PFNGLCLEARDEPTHFPROC, glClearDepthf);\
mlga_loadGLFunc(PFNGLGETPROGRAMBINARYPROC, glGetProgramBinary);\
mlga_loadGLFunc(PFNGLPROGRAMBINARYPROC, glProgramBinary);\
mlga_loadGLFunc(PFNGLPROGRAMPARAMETERIPROC, glProgramParameteri);\
mlga_loadGLFunc(PFNGLUSEPROGRAMSTAGESPROC, glUseProgramStages);\
mlga_loadGLFunc(PFNGLACTIVESHADERPROGRAMPROC, glActiveShaderProgram);\
mlga_loadGLFunc(PFNGLCREATESHADERPROGRAMVPROC, glCreateShaderProgramv);\
mlga_loadGLFunc(PFNGLBINDPROGRAMPIPELINEPROC, glBindProgramPipeline);\
mlga_loadGLFunc(PFNGLDELETEPROGRAMPIPELINESPROC, glDeleteProgramPipelines);\
mlga_loadGLFunc(PFNGLGENPROGRAMPIPELINESPROC, glGenProgramPipelines);\
mlga_loadGLFunc(PFNGLISPROGRAMPIPELINEPROC, glIsProgramPipeline);\
mlga_loadGLFunc(PFNGLGETPROGRAMPIPELINEIVPROC, glGetProgramPipelineiv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM1IPROC, glProgramUniform1i);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM1IVPROC, glProgramUniform1iv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM1FPROC, glProgramUniform1f);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM1FVPROC, glProgramUniform1fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM1DPROC, glProgramUniform1d);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM1DVPROC, glProgramUniform1dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM1UIPROC, glProgramUniform1ui);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM1UIVPROC, glProgramUniform1uiv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM2IPROC, glProgramUniform2i);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM2IVPROC, glProgramUniform2iv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM2FPROC, glProgramUniform2f);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM2FVPROC, glProgramUniform2fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM2DPROC, glProgramUniform2d);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM2DVPROC, glProgramUniform2dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM2UIPROC, glProgramUniform2ui);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM2UIVPROC, glProgramUniform2uiv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM3IPROC, glProgramUniform3i);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM3IVPROC, glProgramUniform3iv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM3FPROC, glProgramUniform3f);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM3FVPROC, glProgramUniform3fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM3DPROC, glProgramUniform3d);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM3DVPROC, glProgramUniform3dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM3UIPROC, glProgramUniform3ui);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM3UIVPROC, glProgramUniform3uiv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM4IPROC, glProgramUniform4i);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM4IVPROC, glProgramUniform4iv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM4FPROC, glProgramUniform4f);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM4FVPROC, glProgramUniform4fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM4DPROC, glProgramUniform4d);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM4DVPROC, glProgramUniform4dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM4UIPROC, glProgramUniform4ui);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORM4UIVPROC, glProgramUniform4uiv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2FVPROC, glProgramUniformMatrix2fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3FVPROC, glProgramUniformMatrix3fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4FVPROC, glProgramUniformMatrix4fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2DVPROC, glProgramUniformMatrix2dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3DVPROC, glProgramUniformMatrix3dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4DVPROC, glProgramUniformMatrix4dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC, glProgramUniformMatrix2x3fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC, glProgramUniformMatrix3x2fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC, glProgramUniformMatrix2x4fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC, glProgramUniformMatrix4x2fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC, glProgramUniformMatrix3x4fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC, glProgramUniformMatrix4x3fv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC, glProgramUniformMatrix2x3dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC, glProgramUniformMatrix3x2dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC, glProgramUniformMatrix2x4dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC, glProgramUniformMatrix4x2dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC, glProgramUniformMatrix3x4dv);\
mlga_loadGLFunc(PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC, glProgramUniformMatrix4x3dv);\
mlga_loadGLFunc(PFNGLVALIDATEPROGRAMPIPELINEPROC, glValidateProgramPipeline);\
mlga_loadGLFunc(PFNGLGETPROGRAMPIPELINEINFOLOGPROC, glGetProgramPipelineInfoLog);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBL1DPROC, glVertexAttribL1d);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBL2DPROC, glVertexAttribL2d);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBL3DPROC, glVertexAttribL3d);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBL4DPROC, glVertexAttribL4d);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBL1DVPROC, glVertexAttribL1dv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBL2DVPROC, glVertexAttribL2dv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBL3DVPROC, glVertexAttribL3dv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBL4DVPROC, glVertexAttribL4dv);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBLPOINTERPROC, glVertexAttribLPointer);\
mlga_loadGLFunc(PFNGLGETVERTEXATTRIBLDVPROC, glGetVertexAttribLdv);\
mlga_loadGLFunc(PFNGLVIEWPORTARRAYVPROC, glViewportArrayv);\
mlga_loadGLFunc(PFNGLVIEWPORTINDEXEDFPROC, glViewportIndexedf);\
mlga_loadGLFunc(PFNGLVIEWPORTINDEXEDFVPROC, glViewportIndexedfv);\
mlga_loadGLFunc(PFNGLSCISSORARRAYVPROC, glScissorArrayv);\
mlga_loadGLFunc(PFNGLSCISSORINDEXEDPROC, glScissorIndexed);\
mlga_loadGLFunc(PFNGLSCISSORINDEXEDVPROC, glScissorIndexedv);\
mlga_loadGLFunc(PFNGLDEPTHRANGEARRAYVPROC, glDepthRangeArrayv);\
mlga_loadGLFunc(PFNGLDEPTHRANGEINDEXEDPROC, glDepthRangeIndexed);\
mlga_loadGLFunc(PFNGLGETFLOATI_VPROC, glGetFloati_v);\
mlga_loadGLFunc(PFNGLGETDOUBLEI_VPROC, glGetDoublei_v);
#endif /* GL_VERSION_4_1 */
#ifdef GL_VERSION_4_2
#define MLGA_LOAD_GL_CORE_4_2_FUNC mlga_loadGLFunc(PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC, glDrawArraysInstancedBaseInstance);\
mlga_loadGLFunc(PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC, glDrawElementsInstancedBaseInstance);\
mlga_loadGLFunc(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC, glDrawElementsInstancedBaseVertexBaseInstance);\
mlga_loadGLFunc(PFNGLGETINTERNALFORMATIVPROC, glGetInternalformativ);\
mlga_loadGLFunc(PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC, glGetActiveAtomicCounterBufferiv);\
mlga_loadGLFunc(PFNGLBINDIMAGETEXTUREPROC, glBindImageTexture);\
mlga_loadGLFunc(PFNGLMEMORYBARRIERPROC, glMemoryBarrier);\
mlga_loadGLFunc(PFNGLTEXSTORAGE1DPROC, glTexStorage1D);\
mlga_loadGLFunc(PFNGLTEXSTORAGE2DPROC, glTexStorage2D);\
mlga_loadGLFunc(PFNGLTEXSTORAGE3DPROC, glTexStorage3D);\
mlga_loadGLFunc(PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC, glDrawTransformFeedbackInstanced);\
mlga_loadGLFunc(PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC, glDrawTransformFeedbackStreamInstanced);
#endif /* GL_VERSION_4_2 */
#ifdef GL_VERSION_4_3
#define MLGA_LOAD_GL_CORE_4_3_FUNC mlga_loadGLFunc(PFNGLCLEARBUFFERDATAPROC, glClearBufferData);\
mlga_loadGLFunc(PFNGLCLEARBUFFERSUBDATAPROC, glClearBufferSubData);\
mlga_loadGLFunc(PFNGLDISPATCHCOMPUTEPROC, glDispatchCompute);\
mlga_loadGLFunc(PFNGLDISPATCHCOMPUTEINDIRECTPROC, glDispatchComputeIndirect);\
mlga_loadGLFunc(PFNGLCOPYIMAGESUBDATAPROC, glCopyImageSubData);\
mlga_loadGLFunc(PFNGLFRAMEBUFFERPARAMETERIPROC, glFramebufferParameteri);\
mlga_loadGLFunc(PFNGLGETFRAMEBUFFERPARAMETERIVPROC, glGetFramebufferParameteriv);\
mlga_loadGLFunc(PFNGLGETINTERNALFORMATI64VPROC, glGetInternalformati64v);\
mlga_loadGLFunc(PFNGLINVALIDATETEXSUBIMAGEPROC, glInvalidateTexSubImage);\
mlga_loadGLFunc(PFNGLINVALIDATETEXIMAGEPROC, glInvalidateTexImage);\
mlga_loadGLFunc(PFNGLINVALIDATEBUFFERSUBDATAPROC, glInvalidateBufferSubData);\
mlga_loadGLFunc(PFNGLINVALIDATEBUFFERDATAPROC, glInvalidateBufferData);\
mlga_loadGLFunc(PFNGLINVALIDATEFRAMEBUFFERPROC, glInvalidateFramebuffer);\
mlga_loadGLFunc(PFNGLINVALIDATESUBFRAMEBUFFERPROC, glInvalidateSubFramebuffer);\
mlga_loadGLFunc(PFNGLMULTIDRAWARRAYSINDIRECTPROC, glMultiDrawArraysIndirect);\
mlga_loadGLFunc(PFNGLMULTIDRAWELEMENTSINDIRECTPROC, glMultiDrawElementsIndirect);\
mlga_loadGLFunc(PFNGLGETPROGRAMINTERFACEIVPROC, glGetProgramInterfaceiv);\
mlga_loadGLFunc(PFNGLGETPROGRAMRESOURCEINDEXPROC, glGetProgramResourceIndex);\
mlga_loadGLFunc(PFNGLGETPROGRAMRESOURCENAMEPROC, glGetProgramResourceName);\
mlga_loadGLFunc(PFNGLGETPROGRAMRESOURCEIVPROC, glGetProgramResourceiv);\
mlga_loadGLFunc(PFNGLGETPROGRAMRESOURCELOCATIONPROC, glGetProgramResourceLocation);\
mlga_loadGLFunc(PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC, glGetProgramResourceLocationIndex);\
mlga_loadGLFunc(PFNGLSHADERSTORAGEBLOCKBINDINGPROC, glShaderStorageBlockBinding);\
mlga_loadGLFunc(PFNGLTEXBUFFERRANGEPROC, glTexBufferRange);\
mlga_loadGLFunc(PFNGLTEXSTORAGE2DMULTISAMPLEPROC, glTexStorage2DMultisample);\
mlga_loadGLFunc(PFNGLTEXSTORAGE3DMULTISAMPLEPROC, glTexStorage3DMultisample);\
mlga_loadGLFunc(PFNGLTEXTUREVIEWPROC, glTextureView);\
mlga_loadGLFunc(PFNGLBINDVERTEXBUFFERPROC, glBindVertexBuffer);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBFORMATPROC, glVertexAttribFormat);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBIFORMATPROC, glVertexAttribIFormat);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBLFORMATPROC, glVertexAttribLFormat);\
mlga_loadGLFunc(PFNGLVERTEXATTRIBBINDINGPROC, glVertexAttribBinding);\
mlga_loadGLFunc(PFNGLVERTEXBINDINGDIVISORPROC, glVertexBindingDivisor);\
mlga_loadGLFunc(PFNGLDEBUGMESSAGECONTROLPROC, glDebugMessageControl);\
mlga_loadGLFunc(PFNGLDEBUGMESSAGEINSERTPROC, glDebugMessageInsert);\
mlga_loadGLFunc(PFNGLDEBUGMESSAGECALLBACKPROC, glDebugMessageCallback);\
mlga_loadGLFunc(PFNGLGETDEBUGMESSAGELOGPROC, glGetDebugMessageLog);\
mlga_loadGLFunc(PFNGLPUSHDEBUGGROUPPROC, glPushDebugGroup);\
mlga_loadGLFunc(PFNGLPOPDEBUGGROUPPROC, glPopDebugGroup);\
mlga_loadGLFunc(PFNGLOBJECTLABELPROC, glObjectLabel);\
mlga_loadGLFunc(PFNGLGETOBJECTLABELPROC, glGetObjectLabel);\
mlga_loadGLFunc(PFNGLOBJECTPTRLABELPROC, glObjectPtrLabel);\
mlga_loadGLFunc(PFNGLGETOBJECTPTRLABELPROC, glGetObjectPtrLabel);
#endif /* GL_VERSION_4_3 */
#ifdef GL_VERSION_4_4
#define MLGA_LOAD_GL_CORE_4_4_FUNC mlga_loadGLFunc(PFNGLBUFFERSTORAGEPROC, glBufferStorage);\
mlga_loadGLFunc(PFNGLCLEARTEXIMAGEPROC, glClearTexImage);\
mlga_loadGLFunc(PFNGLCLEARTEXSUBIMAGEPROC, glClearTexSubImage);\
mlga_loadGLFunc(PFNGLBINDBUFFERSBASEPROC, glBindBuffersBase);\
mlga_loadGLFunc(PFNGLBINDBUFFERSRANGEPROC, glBindBuffersRange);\
mlga_loadGLFunc(PFNGLBINDTEXTURESPROC, glBindTextures);\
mlga_loadGLFunc(PFNGLBINDSAMPLERSPROC, glBindSamplers);\
mlga_loadGLFunc(PFNGLBINDIMAGETEXTURESPROC, glBindImageTextures);\
mlga_loadGLFunc(PFNGLBINDVERTEXBUFFERSPROC, glBindVertexBuffers);
#endif /* GL_VERSION_4_4 */
#ifdef GL_VERSION_4_5
#define MLGA_LOAD_GL_CORE_4_5_FUNC mlga_loadGLFunc(PFNGLCLIPCONTROLPROC, glClipControl);\
mlga_loadGLFunc(PFNGLCREATETRANSFORMFEEDBACKSPROC, glCreateTransformFeedbacks);\
mlga_loadGLFunc(PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC, glTransformFeedbackBufferBase);\
mlga_loadGLFunc(PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC, glTransformFeedbackBufferRange);\
mlga_loadGLFunc(PFNGLGETTRANSFORMFEEDBACKIVPROC, glGetTransformFeedbackiv);\
mlga_loadGLFunc(PFNGLGETTRANSFORMFEEDBACKI_VPROC, glGetTransformFeedbacki_v);\
mlga_loadGLFunc(PFNGLGETTRANSFORMFEEDBACKI64_VPROC, glGetTransformFeedbacki64_v);\
mlga_loadGLFunc(PFNGLCREATEBUFFERSPROC, glCreateBuffers);\
mlga_loadGLFunc(PFNGLNAMEDBUFFERSTORAGEPROC, glNamedBufferStorage);\
mlga_loadGLFunc(PFNGLNAMEDBUFFERDATAPROC, glNamedBufferData);\
mlga_loadGLFunc(PFNGLNAMEDBUFFERSUBDATAPROC, glNamedBufferSubData);\
mlga_loadGLFunc(PFNGLCOPYNAMEDBUFFERSUBDATAPROC, glCopyNamedBufferSubData);\
mlga_loadGLFunc(PFNGLCLEARNAMEDBUFFERDATAPROC, glClearNamedBufferData);\
mlga_loadGLFunc(PFNGLCLEARNAMEDBUFFERSUBDATAPROC, glClearNamedBufferSubData);\
mlga_loadGLFunc(PFNGLMAPNAMEDBUFFERPROC, glMapNamedBuffer);\
mlga_loadGLFunc(PFNGLMAPNAMEDBUFFERRANGEPROC, glMapNamedBufferRange);\
mlga_loadGLFunc(PFNGLUNMAPNAMEDBUFFERPROC, glUnmapNamedBuffer);\
mlga_loadGLFunc(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC, glFlushMappedNamedBufferRange);\
mlga_loadGLFunc(PFNGLGETNAMEDBUFFERPARAMETERIVPROC, glGetNamedBufferParameteriv);\
mlga_loadGLFunc(PFNGLGETNAMEDBUFFERPARAMETERI64VPROC, glGetNamedBufferParameteri64v);\
mlga_loadGLFunc(PFNGLGETNAMEDBUFFERPOINTERVPROC, glGetNamedBufferPointerv);\
mlga_loadGLFunc(PFNGLGETNAMEDBUFFERSUBDATAPROC, glGetNamedBufferSubData);\
mlga_loadGLFunc(PFNGLCREATEFRAMEBUFFERSPROC, glCreateFramebuffers);\
mlga_loadGLFunc(PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC, glNamedFramebufferRenderbuffer);\
mlga_loadGLFunc(PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC, glNamedFramebufferParameteri);\
mlga_loadGLFunc(PFNGLNAMEDFRAMEBUFFERTEXTUREPROC, glNamedFramebufferTexture);\
mlga_loadGLFunc(PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC, glNamedFramebufferTextureLayer);\
mlga_loadGLFunc(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC, glNamedFramebufferDrawBuffer);\
mlga_loadGLFunc(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC, glNamedFramebufferDrawBuffers);\
mlga_loadGLFunc(PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC, glNamedFramebufferReadBuffer);\
mlga_loadGLFunc(PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC, glInvalidateNamedFramebufferData);\
mlga_loadGLFunc(PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC, glInvalidateNamedFramebufferSubData);\
mlga_loadGLFunc(PFNGLCLEARNAMEDFRAMEBUFFERIVPROC, glClearNamedFramebufferiv);\
mlga_loadGLFunc(PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC, glClearNamedFramebufferuiv);\
mlga_loadGLFunc(PFNGLCLEARNAMEDFRAMEBUFFERFVPROC, glClearNamedFramebufferfv);\
mlga_loadGLFunc(PFNGLCLEARNAMEDFRAMEBUFFERFIPROC, glClearNamedFramebufferfi);\
mlga_loadGLFunc(PFNGLBLITNAMEDFRAMEBUFFERPROC, glBlitNamedFramebuffer);\
mlga_loadGLFunc(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC, glCheckNamedFramebufferStatus);\
mlga_loadGLFunc(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC, glGetNamedFramebufferParameteriv);\
mlga_loadGLFunc(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetNamedFramebufferAttachmentParameteriv);\
mlga_loadGLFunc(PFNGLCREATERENDERBUFFERSPROC, glCreateRenderbuffers);\
mlga_loadGLFunc(PFNGLNAMEDRENDERBUFFERSTORAGEPROC, glNamedRenderbufferStorage);\
mlga_loadGLFunc(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC, glNamedRenderbufferStorageMultisample);\
mlga_loadGLFunc(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC, glGetNamedRenderbufferParameteriv);\
mlga_loadGLFunc(PFNGLCREATETEXTURESPROC, glCreateTextures);\
mlga_loadGLFunc(PFNGLTEXTUREBUFFERPROC, glTextureBuffer);\
mlga_loadGLFunc(PFNGLTEXTUREBUFFERRANGEPROC, glTextureBufferRange);\
mlga_loadGLFunc(PFNGLTEXTURESTORAGE1DPROC, glTextureStorage1D);\
mlga_loadGLFunc(PFNGLTEXTURESTORAGE2DPROC, glTextureStorage2D);\
mlga_loadGLFunc(PFNGLTEXTURESTORAGE3DPROC, glTextureStorage3D);\
mlga_loadGLFunc(PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC, glTextureStorage2DMultisample);\
mlga_loadGLFunc(PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC, glTextureStorage3DMultisample);\
mlga_loadGLFunc(PFNGLTEXTURESUBIMAGE1DPROC, glTextureSubImage1D);\
mlga_loadGLFunc(PFNGLTEXTURESUBIMAGE2DPROC, glTextureSubImage2D);\
mlga_loadGLFunc(PFNGLTEXTURESUBIMAGE3DPROC, glTextureSubImage3D);\
mlga_loadGLFunc(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC, glCompressedTextureSubImage1D);\
mlga_loadGLFunc(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC, glCompressedTextureSubImage2D);\
mlga_loadGLFunc(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC, glCompressedTextureSubImage3D);\
mlga_loadGLFunc(PFNGLCOPYTEXTURESUBIMAGE1DPROC, glCopyTextureSubImage1D);\
mlga_loadGLFunc(PFNGLCOPYTEXTURESUBIMAGE2DPROC, glCopyTextureSubImage2D);\
mlga_loadGLFunc(PFNGLCOPYTEXTURESUBIMAGE3DPROC, glCopyTextureSubImage3D);\
mlga_loadGLFunc(PFNGLTEXTUREPARAMETERFPROC, glTextureParameterf);\
mlga_loadGLFunc(PFNGLTEXTUREPARAMETERFVPROC, glTextureParameterfv);\
mlga_loadGLFunc(PFNGLTEXTUREPARAMETERIPROC, glTextureParameteri);\
mlga_loadGLFunc(PFNGLTEXTUREPARAMETERIIVPROC, glTextureParameterIiv);\
mlga_loadGLFunc(PFNGLTEXTUREPARAMETERIUIVPROC, glTextureParameterIuiv);\
mlga_loadGLFunc(PFNGLTEXTUREPARAMETERIVPROC, glTextureParameteriv);\
mlga_loadGLFunc(PFNGLGENERATETEXTUREMIPMAPPROC, glGenerateTextureMipmap);\
mlga_loadGLFunc(PFNGLBINDTEXTUREUNITPROC, glBindTextureUnit);\
mlga_loadGLFunc(PFNGLGETTEXTUREIMAGEPROC, glGetTextureImage);\
mlga_loadGLFunc(PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC, glGetCompressedTextureImage);\
mlga_loadGLFunc(PFNGLGETTEXTURELEVELPARAMETERFVPROC, glGetTextureLevelParameterfv);\
mlga_loadGLFunc(PFNGLGETTEXTURELEVELPARAMETERIVPROC, glGetTextureLevelParameteriv);\
mlga_loadGLFunc(PFNGLGETTEXTUREPARAMETERFVPROC, glGetTextureParameterfv);\
mlga_loadGLFunc(PFNGLGETTEXTUREPARAMETERIIVPROC, glGetTextureParameterIiv);\
mlga_loadGLFunc(PFNGLGETTEXTUREPARAMETERIUIVPROC, glGetTextureParameterIuiv);\
mlga_loadGLFunc(PFNGLGETTEXTUREPARAMETERIVPROC, glGetTextureParameteriv);\
mlga_loadGLFunc(PFNGLCREATEVERTEXARRAYSPROC, glCreateVertexArrays);\
mlga_loadGLFunc(PFNGLDISABLEVERTEXARRAYATTRIBPROC, glDisableVertexArrayAttrib);\
mlga_loadGLFunc(PFNGLENABLEVERTEXARRAYATTRIBPROC, glEnableVertexArrayAttrib);\
mlga_loadGLFunc(PFNGLVERTEXARRAYELEMENTBUFFERPROC, glVertexArrayElementBuffer);\
mlga_loadGLFunc(PFNGLVERTEXARRAYVERTEXBUFFERPROC, glVertexArrayVertexBuffer);\
mlga_loadGLFunc(PFNGLVERTEXARRAYVERTEXBUFFERSPROC, glVertexArrayVertexBuffers);\
mlga_loadGLFunc(PFNGLVERTEXARRAYATTRIBBINDINGPROC, glVertexArrayAttribBinding);\
mlga_loadGLFunc(PFNGLVERTEXARRAYATTRIBFORMATPROC, glVertexArrayAttribFormat);\
mlga_loadGLFunc(PFNGLVERTEXARRAYATTRIBIFORMATPROC, glVertexArrayAttribIFormat);\
mlga_loadGLFunc(PFNGLVERTEXARRAYATTRIBLFORMATPROC, glVertexArrayAttribLFormat);\
mlga_loadGLFunc(PFNGLVERTEXARRAYBINDINGDIVISORPROC, glVertexArrayBindingDivisor);\
mlga_loadGLFunc(PFNGLGETVERTEXARRAYIVPROC, glGetVertexArrayiv);\
mlga_loadGLFunc(PFNGLGETVERTEXARRAYINDEXEDIVPROC, glGetVertexArrayIndexediv);\
mlga_loadGLFunc(PFNGLGETVERTEXARRAYINDEXED64IVPROC, glGetVertexArrayIndexed64iv);\
mlga_loadGLFunc(PFNGLCREATESAMPLERSPROC, glCreateSamplers);\
mlga_loadGLFunc(PFNGLCREATEPROGRAMPIPELINESPROC, glCreateProgramPipelines);\
mlga_loadGLFunc(PFNGLCREATEQUERIESPROC, glCreateQueries);\
mlga_loadGLFunc(PFNGLGETQUERYBUFFEROBJECTI64VPROC, glGetQueryBufferObjecti64v);\
mlga_loadGLFunc(PFNGLGETQUERYBUFFEROBJECTIVPROC, glGetQueryBufferObjectiv);\
mlga_loadGLFunc(PFNGLGETQUERYBUFFEROBJECTUI64VPROC, glGetQueryBufferObjectui64v);\
mlga_loadGLFunc(PFNGLGETQUERYBUFFEROBJECTUIVPROC, glGetQueryBufferObjectuiv);\
mlga_loadGLFunc(PFNGLMEMORYBARRIERBYREGIONPROC, glMemoryBarrierByRegion);\
mlga_loadGLFunc(PFNGLGETTEXTURESUBIMAGEPROC, glGetTextureSubImage);\
mlga_loadGLFunc(PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC, glGetCompressedTextureSubImage);\
mlga_loadGLFunc(PFNGLGETGRAPHICSRESETSTATUSPROC, glGetGraphicsResetStatus);\
mlga_loadGLFunc(PFNGLGETNCOMPRESSEDTEXIMAGEPROC, glGetnCompressedTexImage);\
mlga_loadGLFunc(PFNGLGETNTEXIMAGEPROC, glGetnTexImage);\
mlga_loadGLFunc(PFNGLGETNUNIFORMDVPROC, glGetnUniformdv);\
mlga_loadGLFunc(PFNGLGETNUNIFORMFVPROC, glGetnUniformfv);\
mlga_loadGLFunc(PFNGLGETNUNIFORMIVPROC, glGetnUniformiv);\
mlga_loadGLFunc(PFNGLGETNUNIFORMUIVPROC, glGetnUniformuiv);\
mlga_loadGLFunc(PFNGLREADNPIXELSPROC, glReadnPixels);\
mlga_loadGLFunc(PFNGLTEXTUREBARRIERPROC, glTextureBarrier);
#endif /* GL_VERSION_4_5 */
#ifdef GL_VERSION_4_6
#define MLGA_LOAD_GL_CORE_4_6_FUNC mlga_loadGLFunc(PFNGLSPECIALIZESHADERPROC, glSpecializeShader);\
mlga_loadGLFunc(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC, glMultiDrawArraysIndirectCount);\
mlga_loadGLFunc(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC, glMultiDrawElementsIndirectCount);\
mlga_loadGLFunc(PFNGLPOLYGONOFFSETCLAMPPROC, glPolygonOffsetClamp);
#endif /* GL_VERSION_4_6 */
#endif /* MLGA_GL_CORE_PROFILE */

#ifndef MLGA_LOAD_GL_CORE_1_0_FUNC
#define MLGA_LOAD_GL_CORE_1_0_FUNC
#endif /* MLGA_LOAD_GL_CORE_1_0_FUNC */
#ifndef MLGA_LOAD_GL_CORE_1_1_FUNC
#define MLGA_LOAD_GL_CORE_1_1_FUNC
#endif /* MLGA_LOAD_GL_CORE__1_FUNC */
#ifndef MLGA_LOAD_GL_CORE_1_2_FUNC
#define MLGA_LOAD_GL_CORE_1_2_FUNC
#endif /* MLGA_LOAD_GL_CORE_1_2_FUNC */
#ifndef MLGA_LOAD_GL_CORE_1_3_FUNC
#define MLGA_LOAD_GL_CORE_1_3_FUNC
#endif /* MLGA_LOAD_GL_CORE_1_3_FUNC */
#ifndef MLGA_LOAD_GL_CORE_1_4_FUNC
#define MLGA_LOAD_GL_CORE_1_4_FUNC
#endif /* MLGA_LOAD_GL_CORE_1_4_FUNC */
#ifndef MLGA_LOAD_GL_CORE_1_5_FUNC
#define MLGA_LOAD_GL_CORE_1_5_FUNC
#endif /* MLGA_LOAD_GL_CORE_1_5_FUNC */
#ifndef MLGA_LOAD_GL_CORE_2_0_FUNC
#define MLGA_LOAD_GL_CORE_2_0_FUNC
#endif /* MLGA_LOAD_GL_CORE_2_0_FUNC */
#ifndef MLGA_LOAD_GL_CORE_2_1_FUNC
#define MLGA_LOAD_GL_CORE_2_1_FUNC
#endif /* MLGA_LOAD_GL_CORE_2_1_FUNC */
#ifndef MLGA_LOAD_GL_CORE_3_0_FUNC
#define MLGA_LOAD_GL_CORE_3_0_FUNC
#endif /* MLGA_LOAD_GL_CORE_3_0_FUNC */
#ifndef MLGA_LOAD_GL_CORE_3_1_FUNC
#define MLGA_LOAD_GL_CORE_3_1_FUNC
#endif /* MLGA_LOAD_GL_CORE_3_1_FUNC */
#ifndef MLGA_LOAD_GL_CORE_3_2_FUNC
#define MLGA_LOAD_GL_CORE_3_2_FUNC
#endif /* MLGA_LOAD_GL_CORE_3_2_FUNC */
#ifndef MLGA_LOAD_GL_CORE_3_3_FUNC
#define MLGA_LOAD_GL_CORE_3_3_FUNC
#endif /* MLGA_LOAD_GL_CORE_3_3_FUNC */
#ifndef MLGA_LOAD_GL_CORE_4_0_FUNC
#define MLGA_LOAD_GL_CORE_4_0_FUNC
#endif /* MLGA_LOAD_GL_CORE_4_0_FUNC */
#ifndef MLGA_LOAD_GL_CORE_4_1_FUNC
#define MLGA_LOAD_GL_CORE_4_1_FUNC
#endif /* MLGA_LOAD_GL_CORE_4_1_FUNC */
#ifndef MLGA_LOAD_GL_CORE_4_2_FUNC
#define MLGA_LOAD_GL_CORE_4_2_FUNC
#endif /* MLGA_LOAD_GL_CORE_4_2_FUNC */
#ifndef MLGA_LOAD_GL_CORE_4_3_FUNC
#define MLGA_LOAD_GL_CORE_4_3_FUNC
#endif /* MLGA_LOAD_GL_CORE_4_3_FUNC */
#ifndef MLGA_LOAD_GL_CORE_4_4_FUNC
#define MLGA_LOAD_GL_CORE_4_4_FUNC
#endif /* MLGA_LOAD_GL_CORE_4_4_FUNC */
#ifndef MLGA_LOAD_GL_CORE_4_5_FUNC
#define MLGA_LOAD_GL_CORE_4_5_FUNC
#endif /* MLGA_LOAD_GL_CORE_4_5_FUNC */
#ifndef MLGA_LOAD_GL_CORE_4_6_FUNC
#define MLGA_LOAD_GL_CORE_4_6_FUNC
#endif /* MLGA_LOAD_GL_CORE_4_6_FUNC */

int mlga_opengl_init(void) {
	MLGA_LOAD_GL_CORE_1_0_FUNC
	MLGA_LOAD_GL_CORE_1_1_FUNC
	MLGA_LOAD_GL_CORE_1_2_FUNC
	MLGA_LOAD_GL_CORE_1_3_FUNC
	MLGA_LOAD_GL_CORE_1_4_FUNC
	MLGA_LOAD_GL_CORE_1_5_FUNC
	MLGA_LOAD_GL_CORE_2_0_FUNC
	MLGA_LOAD_GL_CORE_2_1_FUNC
	MLGA_LOAD_GL_CORE_3_0_FUNC
	MLGA_LOAD_GL_CORE_3_1_FUNC
	MLGA_LOAD_GL_CORE_3_2_FUNC
	MLGA_LOAD_GL_CORE_3_3_FUNC
	MLGA_LOAD_GL_CORE_4_0_FUNC
	MLGA_LOAD_GL_CORE_4_1_FUNC
	MLGA_LOAD_GL_CORE_4_2_FUNC
	MLGA_LOAD_GL_CORE_4_3_FUNC
	MLGA_LOAD_GL_CORE_4_4_FUNC
	MLGA_LOAD_GL_CORE_4_5_FUNC
	MLGA_LOAD_GL_CORE_4_6_FUNC

	return 1;
}