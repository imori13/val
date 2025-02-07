#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>

class Window {
public:
    Window(uint32_t width, uint32_t height, const std::string& title);
    ~Window();

    GLFWwindow* getGLFWwindow() const { return window; }
    bool shouldClose() const;
    void pollEvents() const;

private:
    GLFWwindow* window;
    uint32_t width;
    uint32_t height;
};

#endif // WINDOW_H