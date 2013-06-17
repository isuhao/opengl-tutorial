// Include standard headers
#include <iostream>

// Include GLEW. Always include it before gl.h and glfw.h, since it's a bit magic.
#include <GL/glew.h>

// Include GLEW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>

// key callback function
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    return;
}

int main (void)
{
    using namespace std;
    using namespace glm;

    GLFWwindow* window = NULL;

    // Initialise GLFW
    if(!glfwInit())
    {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow (640, 480, "Tutorial01", NULL, NULL);
 
    if(!window)
    {
        cerr << "Failed to open GLFW window" << endl; 
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true;    // Needed in core profile
    if (glewInit() != GLEW_OK) {
        cerr << "Failed to initilize GLEW" << endl;
        glfwTerminate();
        return -1;
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

    glfwTerminate();
    return 0;
}

