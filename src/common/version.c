/**
 * version.c
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include "version.h"

void get_version (int* major, int* minor)
{
	const char* verstr = (const char*) glGetString(GL_VERSION);
	if((verstr == NULL) || (sscanf(verstr, "%d.%d", major, minor) != 2)) {
		*major = *minor = 0;
		fprintf(stderr, "Invalid GL_VERSION format!!!\n");
	}
}

void get_glsl_version (int* major, int* minor)
{
	int gl_major, gl_minor;
	get_version(&gl_major, &gl_minor);

	*major = *minor = 0;
	if(gl_major == 1) {
		/* GL v1.x can provide GLSL v1.00 only as an extension */
		const char* extstr = (const char*)glGetString(GL_EXTENSIONS);
		if((extstr != NULL) && (strstr(extstr, "GL_ARB_shading_language_100") != NULL))
		{
			*major = 1;
			*minor = 0;
		}
	} else if (gl_major >= 2) {
		/* GL v2.0 and greater must parse the version string */
		const char* verstr = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

		if((verstr == NULL) || (sscanf(verstr, "%d.%d", major, minor) != 2))
		{
			*major = *minor = 0;
			fprintf(stderr, "Invalid GL_SHADING_LANGUAGE_VERSION format!!!\n");
		}
	}
}
