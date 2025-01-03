#pragma once
#include "Component.h"
namespace luke
{
	class Script : public Component
	{
	public:
		Script();
		~Script();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);
	private:
	};
}