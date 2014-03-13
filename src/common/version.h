/**
 * version.h
 */

#ifndef _OPENGL_TUTORIAL_VERSION_H_
#define _OPENGL_TUTORIAL_VERSION_H_

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @brief Get OpenGL Versions
	 * @param[out] major The major version
	 * @param[out] minor The minor version
	 */
	extern void get_version (int *major, int *minor);


	/**
	 * @brief Get OpenGL Shading Language Versions
	 * @param[out] major The major version
	 * @param[out] minor The minor version
	 */
	extern void get_glsl_version (int *major, int *minor);

#ifdef __cplusplus
}
#endif

#endif
