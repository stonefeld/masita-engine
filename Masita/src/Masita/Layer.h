#pragma once

#include "Masita/Core.h"
#include "Masita/Events/Event.h"

namespace Masita {

	class MASITA_API Layer
	{
	public:
		Layer(const std::string& name="Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};

}