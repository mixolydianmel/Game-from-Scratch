#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    GLFWwindow *window;

    if (!glfwInit())
    {
        std::cerr << "Err initializing GLFW" << std::endl;
    }

    window = glfwCreateWindow(800, 600, "opengl", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    int gladVersion = gladLoadGL(glfwGetProcAddress);
    std::cout << "GL " << GLAD_VERSION_MAJOR(gladVersion)
            << "." << GLAD_VERSION_MINOR(gladVersion) << std::endl;

    glClearColor(1.f,0.f,0.f,1.f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
