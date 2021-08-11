#include "mapch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Masita {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		MA_CORE_ASSERT(windowHandle, "Window handle is null");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MA_CORE_ASSERT(status, "Failed to initialize Glad");

		MA_CORE_INFO("OpenGL Info:");
		MA_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		MA_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		MA_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}