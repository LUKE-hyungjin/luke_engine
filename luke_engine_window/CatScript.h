#pragma once
#include "..\\luke_engine_source\\Script.h"
#include "..\\luke_engine_source\\Transform.h"

namespace luke
{
	class CatScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};
		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};
		CatScript();
		~CatScript();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
		void SetPlayer(GameObject* player) { mPlayer = player; }
		Vector2 mDest;

	private:
		void sitDown();
		void move();
		void layDown();
		void PlayWalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);
	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;
		float mDeathTime;
		GameObject* mPlayer;
		float mRadian;

	};
}