#include "mapch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Masita {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}