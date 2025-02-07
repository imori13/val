#ifndef SWAPCHAIN_H
#define SWAPCHAIN_H

#include <vulkan/vulkan.h>
#include <vector>
#include <stdexcept>
#include "VulkanDevice.h"

class SwapChain {
public:
    SwapChain(VulkanDevice& vulkanDevice, uint32_t width, uint32_t height);
    ~SwapChain();

    void init();
    void cleanup();

    VkSwapchainKHR getSwapChain() const { return swapChain; }
    const std::vector<VkImageView>& getImageViews() const { return swapChainImageViews; }
    const std::vector<VkFramebuffer>& getFramebuffers() const { return swapChainFramebuffers; }
    VkFormat getImageFormat() const { return swapChainImageFormat; }
    VkExtent2D getExtent() const { return swapChainExtent; }

    void createFramebuffers(VkRenderPass renderPass);

private:
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    void createSwapChain();
    void createImageViews();

    VulkanDevice& vulkanDevice;
    VkDevice device;
    VkSurfaceKHR surface;
    uint32_t width;
    uint32_t height;

    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

#endif // SWAPCHAIN_H