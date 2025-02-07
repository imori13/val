#include "pch.h"
#include "Window.h"

Window::Window(uint32_t width, uint32_t height, const std::string& title)
    : width(width), height(height)
{
    if (!glfwInit()) {
        throw std::runtime_error("GLFWの初期化に失敗しました");
    }
    // Vulkan用（OpenGL無効）
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    // リサイズ不可（必要に応じて）
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        throw std::runtime_error("ウィンドウの作成に失敗しました");
    }
}

Window::~Window() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::pollEvents() const {
    glfwPollEvents();
} 