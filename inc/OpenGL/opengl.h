#ifndef MLGA_H
#define MLGA_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "KHR/khrplatform.h"

#ifdef MLGA_GL_COMPATIBILITY_PROFILE
	#ifdef MLGA_GL_CORE_PROFILE
		#error "MLGA_GL_COMPATIBILITY_PROFILE and MLGA_GL_CORE_PROFILE are mutually exclusive"
	#endif /* MLGA_GL_CORE_PROFILE */
	#include "GL/gl.h"
	#include "GL/glext.h"
#endif /* MLGA_GL_COMPATIBILITY_PROFILE */

#ifdef MLGA_GL_CORE_PROFILE
	#ifdef MLGA_GL_COMPATIBILITY_PROFILE
		#error "MLGA_GL_CORE_PROFILE and MLGA_GL_COMPATIBILITY_PROFILE are mutually exclusive"
	#endif /* MLGA_GL_COMPATIBILITY_PROFILE */
	#include "GL/glcorearb.h"
#endif /* MLGA_GL_CORE_PROFILE */

#ifdef _WIN32
	#include "GL/wglext.h"
#endif /* MLGA_PLATFORM_WINDOWS */

#ifdef __linux__
	#include "GL/glxext.h"
#endif /* MLGA_PLATFORM_LINUX */

void *mlga_getGLFuncAddress(const char *name);
#define _mlga_glFunc(type, name) ((type)mlga_getGLFuncAddress(#name))
int mlga_init(void);

#ifdef WGL_ARB_buffer_region
#define wglCreateBufferRegionARB _mlga_glFunc(PFNWGLCREATEBUFFERREGIONARBPROC, wglCreateBufferRegionARB)
#define wglDeleteBufferRegionARB _mlga_glFunc(PFNWGLDELETEBUFFERREGIONARBPROC, wglDeleteBufferRegionARB)
#define wglSaveBufferRegionARB _mlga_glFunc(PFNWGLSAVEBUFFERREGIONARBPROC, wglSaveBufferRegionARB)
#define wglRestoreBufferRegionARB _mlga_glFunc(PFNWGLRESTOREBUFFERREGIONARBPROC, wglRestoreBufferRegionARB)
#endif /* WGL_ARB_buffer_region */

#ifdef WGL_ARB_create_context
#define wglCreateContextAttribsARB _mlga_glFunc(PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB)
#endif /* WGL_ARB_create_context */

#ifdef WGL_ARB_extensions_string
#define wglGetExtensionsStringARB _mlga_glFunc(PFNWGLGETEXTENSIONSSTRINGARBPROC, wglGetExtensionsStringARB)
#endif /* WGL_ARB_extensions_string */

#ifdef WGL_ARB_make_current_read
#define wglMakeContextCurrentARB _mlga_glFunc(PFNWGLMAKECONTEXTCURRENTARBPROC, wglMakeContextCurrentARB)
#define wglGetCurrentReadDCARB _mlga_glFunc(PFNWGLGETCURRENTREADDCARBPROC, wglGetCurrentReadDCARB)
#endif /* WGL_ARB_make_current_read */

#ifdef WGL_ARB_pbuffer
#define wglCreatePbufferARB _mlga_glFunc(PFNWGLCREATEPBUFFERARBPROC, wglCreatePbufferARB)
#define wglGetPbufferDCARB _mlga_glFunc(PFNWGLGETPBUFFERDCARBPROC, wglGetPbufferDCARB)
#define wglReleasePbufferDCARB _mlga_glFunc(PFNWGLRELEASEPBUFFERDCARBPROC, wglReleasePbufferDCARB)
#define wglDestroyPbufferARB _mlga_glFunc(PFNWGLDESTROYPBUFFERARBPROC, wglDestroyPbufferARB)
#define wglQueryPbufferARB _mlga_glFunc(PFNWGLQUERYPBUFFERARBPROC, wglQueryPbufferARB)
#endif /* WGL_ARB_pbuffer */

#ifdef WGL_ARB_pixel_format_float
#define wglGetPixelFormatAttribivARB _mlga_glFunc(PFNWGLGETPIXELFORMATATTRIBIVARBPROC, wglGetPixelFormatAttribivARB)
#define wglGetPixelFormatAttribfvARB _mlga_glFunc(PFNWGLGETPIXELFORMATATTRIBFVARBPROC, wglGetPixelFormatAttribfvARB)
#define wglChoosePixelFormatARB _mlga_glFunc(PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB)
#endif /* WGL_ARB_pixel_format_float */

#ifdef WGL_ARB_render_texture
#define wglBindTexImageARB _mlga_glFunc(PFNWGLBINDTEXIMAGEARBPROC, wglBindTexImageARB)
#define wglReleaseTexImageARB _mlga_glFunc(PFNWGLRELEASETEXIMAGEARBPROC, wglReleaseTexImageARB)
#define wglSetPbufferAttribARB _mlga_glFunc(PFNWGLSETPBUFFERATTRIBARBPROC, wglSetPbufferAttribARB)
#endif /* WGL_ARB_render_texture */

#ifdef WGL_3DL_stereo_control
#define wglSetStereoEmitterState3DL _mlga_glFunc(PFNWGLSETSTEREOEMITTERSTATE3DLPROC, wglSetStereoEmitterState3DL)
#endif /* WGL_3DL_stereo_control */

#ifdef WGL_AMD_gpu_association
#define wglGetGPUIDsAMD _mlga_glFunc(PFNWGLGETGPUIDSAMDPROC, wglGetGPUIDsAMD)
#define wglGetGPUInfoAMD _mlga_glFunc(PFNWGLGETGPUINFOAMDPROC, wglGetGPUInfoAMD)
#define wglGetContextGPUIDAMD _mlga_glFunc(PFNWGLGETCONTEXTGPUIDAMDPROC, wglGetContextGPUIDAMD)
#define wglCreateAssociatedContextAMD _mlga_glFunc(PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC, wglCreateAssociatedContextAMD)
#define wglCreateAssociatedContextAttribsAMD _mlga_glFunc(PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC, wglCreateAssociatedContextAttribsAMD)
#define wglDeleteAssociatedContextAMD _mlga_glFunc(PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC, wglDeleteAssociatedContextAMD)
#define wglMakeAssociatedContextCurrentAMD _mlga_glFunc(PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC, wglMakeAssociatedContextCurrentAMD)
#define wglGetCurrentAssociatedContextAMD _mlga_glFunc(PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC, wglGetCurrentAssociatedContextAMD)
#define wglBlitContextFramebufferAMD _mlga_glFunc(PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC, wglBlitContextFramebufferAMD)
#endif /* WGL_AMD_gpu_association */

#ifdef WGL_EXT_display_color_table
#define wglCreateDisplayColorTableEXT _mlga_glFunc(PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC, wglCreateDisplayColorTableEXT)
#define wglLoadDisplayColorTableEXT _mlga_glFunc(PFNWGLLOADDISPLAYCOLORTABLEEXTPROC, wglLoadDisplayColorTableEXT)
#define wglBindDisplayColorTableEXT _mlga_glFunc(PFNWGLBINDDISPLAYCOLORTABLEEXTPROC, wglBindDisplayColorTableEXT)
#define wglDestroyDisplayColorTableEXT _mlga_glFunc(PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC, wglDestroyDisplayColorTableEXT)
#endif /* WGL_EXT_display_color_table */

#ifdef WGL_EXT_extensions_string
#define wglGetExtensionsStringEXT _mlga_glFunc(PFNWGLGETEXTENSIONSSTRINGEXTPROC, wglGetExtensionsStringEXT)
#endif /* WGL_EXT_extensions_string */

#ifdef WGL_EXT_make_current_read
#define wglMakeContextCurrentEXT _mlga_glFunc(PFNWGLMAKECONTEXTCURRENTEXTPROC, wglMakeContextCurrentEXT)
#define wglGetCurrentReadDCEXT _mlga_glFunc(PFNWGLGETCURRENTREADDCEXTPROC, wglGetCurrentReadDCEXT)
#endif /* WGL_EXT_make_current_read */

#ifdef WGL_EXT_pbuffer
#define wglCreatePbufferEXT _mlga_glFunc(PFNWGLCREATEPBUFFEREXTPROC, wglCreatePbufferEXT)
#define wglGetPbufferDCEXT _mlga_glFunc(PFNWGLGETPBUFFERDCEXTPROC, wglGetPbufferDCEXT)
#define wglReleasePbufferDCEXT _mlga_glFunc(PFNWGLRELEASEPBUFFERDCEXTPROC, wglReleasePbufferDCEXT)
#define wglDestroyPbufferEXT _mlga_glFunc(PFNWGLDESTROYPBUFFEREXTPROC, wglDestroyPbufferEXT)
#define wglQueryPbufferEXT _mlga_glFunc(PFNWGLQUERYPBUFFEREXTPROC, wglQueryPbufferEXT)
#endif /* WGL_EXT_pbuffer */

#ifdef WGL_EXT_pixel_format
#define wglGetPixelFormatAttribivEXT _mlga_glFunc(PFNWGLGETPIXELFORMATATTRIBIVEXTPROC, wglGetPixelFormatAttribivEXT)
#define wglGetPixelFormatAttribfvEXT _mlga_glFunc(PFNWGLGETPIXELFORMATATTRIBFVEXTPROC, wglGetPixelFormatAttribfvEXT)
#define wglChoosePixelFormatEXT _mlga_glFunc(PFNWGLCHOOSEPIXELFORMATEXTPROC, wglChoosePixelFormatEXT)
#endif /* WGL_EXT_pixel_format */

#ifdef WGL_EXT_swap_control
#define wglSwapIntervalEXT _mlga_glFunc(PFNWGLSWAPINTERVALEXTPROC, wglSwapIntervalEXT)
#define wglGetSwapIntervalEXT _mlga_glFunc(PFNWGLGETSWAPINTERVALEXTPROC, wglGetSwapIntervalEXT)
#endif /* WGL_EXT_swap_control */

#ifdef WGL_I3D_digital_video_control
#define wglGetDigitalVideoParametersI3D _mlga_glFunc(PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC, wglGetDigitalVideoParametersI3D)
#define wglSetDigitalVideoParametersI3D _mlga_glFunc(PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC, wglSetDigitalVideoParametersI3D)
#endif /* WGL_I3D_digital_video_control */

#ifdef WGL_I3D_gamma
#define wglGetGammaTableParametersI3D _mlga_glFunc(PFNWGLGETGAMMATABLEPARAMETERSI3DPROC, wglGetGammaTableParametersI3D)
#define wglSetGammaTableParametersI3D _mlga_glFunc(PFNWGLSETGAMMATABLEPARAMETERSI3DPROC, wglSetGammaTableParametersI3D)
#define wglGetGammaTableI3D _mlga_glFunc(PFNWGLGETGAMMATABLEI3DPROC, wglGetGammaTableI3D)
#define wglSetGammaTableI3D _mlga_glFunc(PFNWGLSETGAMMATABLEI3DPROC, wglSetGammaTableI3D)
#endif /* WGL_I3D_gamma */

#ifdef WGL_I3D_genlock
#define wglEnableGenlockI3D _mlga_glFunc(PFNWGLENABLEGENLOCKI3DPROC, wglEnableGenlockI3D)
#define wglDisableGenlockI3D _mlga_glFunc(PFNWGLDISABLEGENLOCKI3DPROC, wglDisableGenlockI3D)
#define wglIsEnabledGenlockI3D _mlga_glFunc(PFNWGLISENABLEDGENLOCKI3DPROC, wglIsEnabledGenlockI3D)
#define wglGenlockSourceI3D _mlga_glFunc(PFNWGLGENLOCKSOURCEI3DPROC, wglGenlockSourceI3D)
#define wglGetGenlockSourceI3D _mlga_glFunc(PFNWGLGETGENLOCKSOURCEI3DPROC, wglGetGenlockSourceI3D)
#define wglGenlockSourceEdgeI3D _mlga_glFunc(PFNWGLGENLOCKSOURCEEDGEI3DPROC, wglGenlockSourceEdgeI3D)
#define wglGetGenlockSourceEdgeI3D _mlga_glFunc(PFNWGLGETGENLOCKSOURCEEDGEI3DPROC, wglGetGenlockSourceEdgeI3D)
#define wglGenlockSampleRateI3D _mlga_glFunc(PFNWGLGENLOCKSAMPLERATEI3DPROC, wglGenlockSampleRateI3D)
#define wglGetGenlockSampleRateI3D _mlga_glFunc(PFNWGLGETGENLOCKSAMPLERATEI3DPROC, wglGetGenlockSampleRateI3D)
#define wglGenlockSourceDelayI3D _mlga_glFunc(PFNWGLGENLOCKSOURCEDELAYI3DPROC, wglGenlockSourceDelayI3D)
#define wglGetGenlockSourceDelayI3D _mlga_glFunc(PFNWGLGETGENLOCKSOURCEDELAYI3DPROC, wglGetGenlockSourceDelayI3D)
#define wglQueryGenlockMaxSourceDelayI3D _mlga_glFunc(PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC, wglQueryGenlockMaxSourceDelayI3D)
#endif /* WGL_I3D_genlock */

#ifdef WGL_I3D_image_buffer
#define wglCreateImageBufferI3D _mlga_glFunc(PFNWGLCREATEIMAGEBUFFERI3DPROC, wglCreateImageBufferI3D)
#define wglDestroyImageBufferI3D _mlga_glFunc(PFNWGLDESTROYIMAGEBUFFERI3DPROC, wglDestroyImageBufferI3D)
#define wglAssociateImageBufferEventsI3D _mlga_glFunc(PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC, wglAssociateImageBufferEventsI3D)
#define wglReleaseImageBufferEventsI3D _mlga_glFunc(PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC, wglReleaseImageBufferEventsI3D)
#endif /* WGL_I3D_image_buffer */

#ifdef WGL_I3D_swap_frame_lock
#define wglEnableFrameLockI3D _mlga_glFunc(PFNWGLENABLEFRAMELOCKI3DPROC, wglEnableFrameLockI3D)
#define wglDisableFrameLockI3D _mlga_glFunc(PFNWGLDISABLEFRAMELOCKI3DPROC, wglDisableFrameLockI3D)
#define wglIsEnabledFrameLockI3D _mlga_glFunc(PFNWGLISENABLEDFRAMELOCKI3DPROC, wglIsEnabledFrameLockI3D)
#define wglQueryFrameLockMasterI3D _mlga_glFunc(PFNWGLQUERYFRAMELOCKMASTERI3DPROC, wglQueryFrameLockMasterI3D)
#endif /* WGL_I3D_swap_frame_lock */

#ifdef WGL_I3D_swap_frame_usage
#define wglGetFrameUsageI3D _mlga_glFunc(PFNWGLGETFRAMEUSAGEI3DPROC, wglGetFrameUsageI3D)
#define wglBeginFrameTrackingI3D _mlga_glFunc(PFNWGLBEGINFRAMETRACKINGI3DPROC, wglBeginFrameTrackingI3D)
#define wglEndFrameTrackingI3D _mlga_glFunc(PFNWGLENDFRAMETRACKINGI3DPROC, wglEndFrameTrackingI3D)
#define wglQueryFrameTrackingI3D _mlga_glFunc(PFNWGLQUERYFRAMETRACKINGI3DPROC, wglQueryFrameTrackingI3D)
#endif /* WGL_I3D_swap_frame_usage */

#ifdef WGL_NV_DX_interop
#define wglDXSetResourceShareHandleNV _mlga_glFunc(PFNWGLDXSETRESOURCESHAREHANDLENVPROC, wglDXSetResourceShareHandleNV)
#define wglDXOpenDeviceNV _mlga_glFunc(PFNWGLDXOPENDEVICENVPROC, wglDXOpenDeviceNV)
#define wglDXCloseDeviceNV _mlga_glFunc(PFNWGLDXCLOSEDEVICENVPROC, wglDXCloseDeviceNV)
#define wglDXRegisterObjectNV _mlga_glFunc(PFNWGLDXREGISTEROBJECTNVPROC, wglDXRegisterObjectNV)
#define wglDXUnregisterObjectNV _mlga_glFunc(PFNWGLDXUNREGISTEROBJECTNVPROC, wglDXUnregisterObjectNV)
#define wglDXObjectAccessNV _mlga_glFunc(PFNWGLDXOBJECTACCESSNVPROC, wglDXObjectAccessNV)
#define wglDXLockObjectsNV _mlga_glFunc(PFNWGLDXLOCKOBJECTSNVPROC, wglDXLockObjectsNV)
#define wglDXUnlockObjectsNV _mlga_glFunc(PFNWGLDXUNLOCKOBJECTSNVPROC, wglDXUnlockObjectsNV)
#endif /* WGL_NV_DX_interop */

#ifdef WGL_NV_copy_image
#define wglCopyImageSubDataNV _mlga_glFunc(PFNWGLCOPYIMAGESUBDATANVPROC, wglCopyImageSubDataNV)
#endif /* WGL_NV_copy_image */

#ifdef WGL_NV_delay_before_swap
#define wglDelayBeforeSwapNV _mlga_glFunc(PFNWGLDELAYBEFORESWAPNVPROC, wglDelayBeforeSwapNV)
#endif /* WGL_NV_delay_before_swap */

#ifdef WGL_NV_gpu_affinity
#define wglEnumGpusNV _mlga_glFunc(PFNWGLENUMGPUSNVPROC, wglEnumGpusNV)
#define wglEnumGpuDevicesNV _mlga_glFunc(PFNWGLENUMGPUDEVICESNVPROC, wglEnumGpuDevicesNV)
#define wglCreateAffinityDCNV _mlga_glFunc(PFNWGLCREATEAFFINITYDCNVPROC, wglCreateAffinityDCNV)
#define wglEnumGpusFromAffinityDCNV _mlga_glFunc(PFNWGLENUMGPUSFROMAFFINITYDCNVPROC, wglEnumGpusFromAffinityDCNV)
#define wglDeleteDCNV _mlga_glFunc(PFNWGLDELETEDCNVPROC, wglDeleteDCNV)
#endif /* WGL_NV_gpu_affinity */

#ifdef WGL_NV_present_video
#define wglEnumerateVideoDevicesNV _mlga_glFunc(PFNWGLENUMERATEVIDEODEVICESNVPROC, wglEnumerateVideoDevicesNV)
#define wglBindVideoDeviceNV _mlga_glFunc(PFNWGLBINDVIDEODEVICENVPROC, wglBindVideoDeviceNV)
#define wglQueryCurrentContextNV _mlga_glFunc(PFNWGLQUERYCURRENTCONTEXTNVPROC, wglQueryCurrentContextNV)
#endif /* WGL_NV_present_video */

#ifdef WGL_NV_swap_group
#define wglJoinSwapGroupNV _mlga_glFunc(PFNWGLJOINSWAPGROUPNVPROC, wglJoinSwapGroupNV)
#define wglBindSwapBarrierNV _mlga_glFunc(PFNWGLBINDSWAPBARRIERNVPROC, wglBindSwapBarrierNV)
#define wglQuerySwapGroupNV _mlga_glFunc(PFNWGLQUERYSWAPGROUPNVPROC, wglQuerySwapGroupNV)
#define wglQueryMaxSwapGroupsNV _mlga_glFunc(PFNWGLQUERYMAXSWAPGROUPSNVPROC, wglQueryMaxSwapGroupsNV)
#define wglQueryFrameCountNV _mlga_glFunc(PFNWGLQUERYFRAMECOUNTNVPROC, wglQueryFrameCountNV)
#define wglResetFrameCountNV _mlga_glFunc(PFNWGLRESETFRAMECOUNTNVPROC, wglResetFrameCountNV)
#endif /* WGL_NV_swap_group */

#ifdef WGL_NV_vertex_array_range
#define wglAllocateMemoryNV _mlga_glFunc(PFNWGLALLOCATEMEMORYNVPROC, wglAllocateMemoryNV
#define wglFreeMemoryNV _mlga_glFunc(PFNWGLFREEMEMORYNVPROC, wglFreeMemoryNV
#endif /* WGL_NV_vertex_array_range */

#ifdef WGL_NV_video_capture
#define wglBindVideoCaptureDeviceNV _mlga_glFunc(PFNWGLBINDVIDEOCAPTUREDEVICENVPROC, wglBindVideoCaptureDeviceNV)
#define wglEnumerateVideoCaptureDevicesNV _mlga_glFunc(PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC, wglEnumerateVideoCaptureDevicesNV)
#define wglLockVideoCaptureDeviceNV _mlga_glFunc(PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC, wglLockVideoCaptureDeviceNV)
#define wglQueryVideoCaptureDeviceNV _mlga_glFunc(PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC, wglQueryVideoCaptureDeviceNV)
#define wglReleaseVideoCaptureDeviceNV _mlga_glFunc(PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC, wglReleaseVideoCaptureDeviceNV)
#endif /* WGL_NV_video_capture */

#ifdef WGL_NV_video_output
#define wglGetVideoDeviceNV _mlga_glFunc(PFNWGLGETVIDEODEVICENVPROC, wglGetVideoDeviceNV)
#define wglReleaseVideoDeviceNV _mlga_glFunc(PFNWGLRELEASEVIDEODEVICENVPROC, wglReleaseVideoDeviceNV)
#define wglBindVideoImageNV _mlga_glFunc(PFNWGLBINDVIDEOIMAGENVPROC, wglBindVideoImageNV)
#define wglReleaseVideoImageNV _mlga_glFunc(PFNWGLRELEASEVIDEOIMAGENVPROC, wglReleaseVideoImageNV)
#define wglSendPbufferToVideoNV _mlga_glFunc(PFNWGLSENDPBUFFERTOVIDEONVPROC, wglSendPbufferToVideoNV)
#define wglGetVideoInfoNV _mlga_glFunc(PFNWGLGETVIDEOINFONVPROC, wglGetVideoInfoNV)
#endif /* WGL_NV_video_output */

#ifdef WGL_OML_sync_control
#define wglGetSyncValuesOML _mlga_glFunc(PFNWGLGETSYNCVALUESOMLPROC, wglGetSyncValuesOML)
#define wglGetMscRateOML _mlga_glFunc(PFNWGLGETMSCRATEOMLPROC, wglGetMscRateOML)
#define wglSwapBuffersMscOML _mlga_glFunc(PFNWGLSWAPBUFFERSMSCOMLPROC, wglSwapBuffersMscOML)
#define wglSwapLayerBuffersMscOML _mlga_glFunc(PFNWGLSWAPLAYERBUFFERSMSCOMLPROC, wglSwapLayerBuffersMscOML)
#define wglWaitForMscOML _mlga_glFunc(PFNWGLWAITFORMSCOMLPROC, wglWaitForMscOML)
#define wglWaitForSbcOML _mlga_glFunc(PFNWGLWAITFORSBCOMLPROC, wglWaitForSbcOML)
#endif /* WGL_OML_sync_control */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MLGA_H */