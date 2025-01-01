#pragma once
#include "..\\luke_engine_source\Script.h"

namespace luke
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack,
		};
		PlayerScript();
		~PlayerScript();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void AttackEffect();
		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;
	private:
		void idle();
		void move();
		void giveWater();

	private:
		eState mState;
		class Animator* mAnimator;

	};
}