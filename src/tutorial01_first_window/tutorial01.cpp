// Include standard headers
#include <iostream>

// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
#include <GL/glew.h>

// Include GLEW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

// key callback function
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    return;
}

// Error callback
static void error_callback(int error, const char* description)
{
    cerr << description << endl;

    return;
}

int main (int argc, char* argv[])
{
    GLFWwindow* window = NULL;

    // Set the error callback, this should be called before glfwInit
    glfwSetErrorCallback(error_callback);

    // Initialise GLFW
    if(!glfwInit())
    {
        cerr << "Failed to initialize GLFW" << endl;
        exit(EXIT_FAILURE);
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow (640, 480, argv[0], NULL, NULL);
 
    if(!window)
    {
        cerr << "Failed to open GLFW window" << endl; 
        glfwTerminate();

        exit(EXIT_FAILURE);
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true;    // Needed in core profile
    if (glewInit() != GLEW_OK) {
        cerr << "Failed to initilize GLEW" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    // Loop until the user closes the window
    while(!glfwWindowShouldClose(window))
    {
        // TODO: Render here
        
        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return(EXIT_SUCCESS);
}

