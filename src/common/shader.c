/**
 * shader.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>

#include "shader.h"

/**
 * @brief read a text file
 *
 * @note DON'T forget free the buffer allocated and returned
 */
static char* read (const char* filename)
{
	FILE * file;
	char * buffer;
	size_t size;

	file = fopen(filename, "rb");
	if (!file) {
		fprintf( stderr, "Unable to open file \"%s\".\n", filename);
		return NULL;
	}
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	buffer = (char *) malloc((size + 1) * sizeof(char *));
	fread(buffer, sizeof(char), size, file);
	buffer[size] = '\0';
	fclose(file);
	return buffer;	
}

/**
 * @brief Compile one shader from string buffer
 */
static GLuint compile (const char* buf, GLenum type)
{
	GLint compile_status;
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &buf, 0);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
	if (compile_status == GL_FALSE) {
		GLchar messages[256];
		glGetShaderInfoLog(shader, sizeof(messages), 0, &messages[0]);
		fprintf(stderr, "%s\n", messages);
		exit(EXIT_FAILURE);
	}
	
	return shader;
}

/**
 * @brief load one shader from string
 */
static GLuint load (const char* buf, GLenum type)
{
	GLuint shader = 0;

	if(buf) {
		shader = compile (buf, type);
	}

	return shader;
}

/**
 * @brief load one shader from file
 */
static GLuint load_file (const char* filename, GLenum type)
{
	GLuint shader = 0;
	
	char* buf = read (filename);

	if(buf) {
		shader = compile (buf, type);
		free(buf);
	}

	return shader;
}

GLuint load_shaders (const char* vert_str, const char* frag_str)
{
	GLuint program = 0;
	GLuint vertex_shader = 0;
	GLuint fragment_shader = 0;
	GLint link_ok = GL_FALSE;

	program = glCreateProgram();
	if(glIsProgram(program) == GL_FALSE) {
		fprintf(stderr, "Fail to create GLSL program\n");
		exit(EXIT_FAILURE);
	}

	vertex_shader = load (vert_str, GL_VERTEX_SHADER);
	fragment_shader = load (frag_str, GL_FRAGMENT_SHADER);

	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
	if (!link_ok) {
		glDetachShader(program, vertex_shader);
		glDetachShader(program, fragment_shader);
		fprintf(stderr, "Fail to glLinkProgram\n");
		exit(EXIT_FAILURE);
	}

	glDetachShader(program, vertex_shader);
	glDetachShader(program, fragment_shader);

	return program;
}

GLuint load_shader_files (const char* vert_file, const char* frag_file)
{
	GLuint program = 0;
	GLuint vertex_shader = 0;
	GLuint fragment_shader = 0;
	GLint link_ok = GL_FALSE;

	program = glCreateProgram();
	if(glIsProgram(program) == GL_FALSE) {
		fprintf(stderr, "Fail to create GLSL program\n");
		exit(EXIT_FAILURE);
	}

	vertex_shader = load_file (vert_file, GL_VERTEX_SHADER);
	fragment_shader = load_file (frag_file, GL_FRAGMENT_SHADER);

	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
	if (!link_ok) {
		glDetachShader(program, vertex_shader);
		glDetachShader(program, fragment_shader);
		fprintf(stderr, "Fail to glLinkProgram\n");
		exit(EXIT_FAILURE);
	}

	glDetachShader(program, vertex_shader);
	glDetachShader(program, fragment_shader);

	return program;
}
