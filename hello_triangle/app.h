#ifndef APP_H_
#define APP_H_

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

class App {
public:
  bool Init();
  void Destroy();

  void MainLoop();

private:
  bool InitResources();
  bool RecordCommandBuffers();
  bool CreateSyncObjects();

  bool DrawFrame();

  int current_frame_ = 0;

  GLFWwindow* window_;

  VkInstance instance_;
  VkDebugUtilsMessengerEXT debug_messenger_;
  VkSurfaceKHR surface_;
  VkPhysicalDevice physical_device_;
  VkDevice device_;
  VkQueue graphics_queue_;
  VkQueue present_queue_;
  VkSwapchainKHR swap_chain_;
  std::vector<VkImage> swap_chain_images_;
  VkFormat swap_chain_image_format_;
  VkExtent2D swap_chain_extent_;
  std::vector<VkImageView> swap_chain_image_views_;
  VkRenderPass render_pass_;
  VkPipelineLayout pipeline_layout_;
  VkPipeline pipeline_;
  std::vector<VkFramebuffer> swap_chain_framebuffers_;
  VkCommandPool command_pool_;
  std::vector<VkCommandBuffer> command_buffers_;
  VkBuffer vertex_buffer_;
  VkDeviceMemory vertex_buffer_memory_;
  std::vector<VkSemaphore> image_ready_semaphores_;
  std::vector<VkSemaphore> render_complete_semaphores_;
  std::vector<VkFence> frame_ready_fences_;
  std::vector<VkFence> image_rendered_fences_;
};

#endif // APP_H_