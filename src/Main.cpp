#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <array>

int main(void)
{
    // ----- Initialization -----
    GLFWwindow *window;

    if (!glfwInit())
    {
        std::cerr << "Err initializing GLFW" << std::endl;
    }

    window = glfwCreateWindow(800, 600, "opengl", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    GLenum status = glewInit();
    if (status != GLEW_OK)
    {
        std::cerr << "Err initializing GLEW" << std::endl;
        std::cerr << glewGetErrorString(status) << std::endl;
    }

    // ----- Processing -----
    std::array<float,12> verts = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f
    };
    std::array<unsigned int,6> indices = {
        0, 1, 2,
        1, 3, 2
    };

    // VBO
    unsigned int vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // EBO
    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*indices.size(), indices.data(), GL_STATIC_DRAW);

    // VS
    const char *vsrc = "#version 330 core\n"
        "layout (location = 0) in vec3 vPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(vPos,1.0);\n"
        "}\0";

    unsigned int vs;
    vs = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vs, 1, &vsrc, NULL);
    glCompileShader(vs);

    // We'll take care of error handling once we build out a shader importer
    
    // FS
    const char *fsrc = "#version 330 core\n"
        "out vec4 fragColor;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   fragColor = vec4(0.9, 0.4, 0.2, 1.0);\n"
        "}\0";

    unsigned int fs;
    fs = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fs, 1, &fsrc, NULL);
    glCompileShader(fs);

    // Program
    unsigned int prgm = glCreateProgram();
    glAttachShader(prgm, vs);
    glAttachShader(prgm, fs);
    glLinkProgram(prgm);

    glDeleteShader(vs);
    glDeleteShader(fs);

    // VAO
    unsigned int vao;
    glGenVertexArrays(1, &vao);

    // Binding
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*verts.size(), verts.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
    glEnableVertexAttribArray(0);

    // ----- Drawing -----

    glClearColor(0.f,0.f,0.f,1.f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(prgm);
        glBindVertexArray(vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
