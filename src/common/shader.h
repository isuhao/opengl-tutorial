/**
 * shader.h
 */

#ifndef _OPENGL_TUTORIAL_SHADER_H_
#define _OPENGL_TUTORIAL_SHADER_H_

#ifdef __cplusplus
extern "C" {
#endif

	GLuint load_shaders (const char* vert_str, const char* frag_str);

	GLuint load_shader_files (const char* vert_file, const char* frag_file);

#ifdef __cplusplus
}
#endif

#endif
