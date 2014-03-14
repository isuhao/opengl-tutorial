/**
 * texture.h
 */

#ifndef _OPENGL_TUTORIAL_TEXTURE_H_
#define _OPENGL_TUTORIAL_TEXTURE_H_

#ifdef __cplusplus
extern "C" {
#endif

	// Load a .BMP file using our custom loader
	extern GLuint load_bmp_file (const char * imagepath);

	//// Since GLFW 3, glfwLoadTexture2D() has been removed. You have to use another texture loading library, 
	//// or do it yourself (just like loadBMP_custom and loadDDS)
	//// Load a .TGA file using GLFW's own loader
	//GLuint loadTGA_glfw(const char * imagepath);

	// Load a .DDS file using GLFW's own loader
	extern GLuint load_dds_file (const char * imagepath);

#ifdef __cplusplus
}
#endif

#endif	/* _OPENGL_TUTORIAL_TEXTURE_H_ */
