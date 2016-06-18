/*
 *  Renderer.h
 *  
 *  Created by Nicolas Aubry on 18-06-2016
 *  Copyright 2016 Nicolas Aubry. All rights reserved.
 *  
 */

#ifndef __RENDERER_H__
#define __RENDERER_H__

//Vulkan includes
#include <vulkan\vulkan.h>

//Commoon/STD includes
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <vector>

//Local includes
#include "UtilsAndEnums.h"

class					Renderer
{
	// -- Attributs
private:
	VkInstance			_vkInstace = nullptr;
	// --!Attributs

	// -- CTors & DTor
public:
	Renderer();
	~Renderer();

private:
	// --!CTors & DTor

	// -- Methods
public:

private:
	void				initVulkan();
	void				listDevices();
	void				destroyVulkan();
	// --!Methods
};

#endif//__RENDERER_H__

