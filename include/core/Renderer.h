#ifndef RENDERER_H
#define RENDERER_H

#include <vulkan/vulkan.h>
#include <vector>
#include "VulkanDevice.h"
#include "SwapChain.h"

class Renderer {
public:
    Renderer(VulkanDevice& vulkanDevice, SwapChain& swapChain);
    ~Renderer();

    void init();
    void cleanup();
    void drawFrame();

    VkRenderPass getRenderPass() const { return renderPass; }

private:
    void createRenderPass();
    void createCommandPool();
    void createCommandBuffers();
    void createSyncObjects();
    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    VulkanDevice& vulkanDevice;
    SwapChain& swapChain;
    VkDevice device;
    
    VkRenderPass renderPass;
    
    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;

    const int MAX_FRAMES_IN_FLIGHT = 2;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    size_t currentFrame = 0;
};

#endif // RENDERER_H