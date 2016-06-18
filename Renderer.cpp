/*
 *  Renderer.cpp
 *  
 *  Created by Nicolas Aubry on 18-06-2016
 *  Copyright 2016 Nicolas Aubry. All rights reserved.
 *  
 */

#include "Renderer.h"

Renderer::Renderer()
{
	this->initVulkan();
	this->listDevices();
}

Renderer::~Renderer()
{
	this->destroyVulkan();
}

void								Renderer::initVulkan()
{
	VkApplicationInfo				appInfo{};
	appInfo.sType					= VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.apiVersion				= VK_MAKE_VERSION(1, 0, 13);


	VkInstanceCreateInfo			instanceInfo {};

	instanceInfo.sType				= VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceInfo.pApplicationInfo	= &appInfo;

	VkResult result = vkCreateInstance(&instanceInfo, nullptr, &this->_vkInstace);

	if (result != VK_SUCCESS)
	{
		assert(0 && "vkCreateInstace failed...");
		std::exit(VK_INIT_FAILED);
	}
}

void								Renderer::listDevices()
{
	uint32_t						gpuCount = 0;

	vkEnumeratePhysicalDevices(this->_vkInstace, &gpuCount, nullptr);
	std::vector<VkPhysicalDevice>	gpusList(gpuCount);
	vkEnumeratePhysicalDevices(this->_vkInstace, &gpuCount, gpusList.data());

	for each (VkPhysicalDevice device in gpusList)
	{
		VkPhysicalDeviceProperties props{};

		vkGetPhysicalDeviceProperties(device, &props);

		std::cout << "Vulkan Physical Device" << std::endl;
		std::cout << props.deviceName << std::endl;
	}
}

void								Renderer::destroyVulkan()
{
	vkDestroyInstance(this->_vkInstace, nullptr);
	this->_vkInstace = nullptr;
}
