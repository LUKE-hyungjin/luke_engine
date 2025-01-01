#pragma once
namespace luke::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		Tile,
		//character
		Animal,
		Player,
		Particle,
		Max = 16,
	};

	enum class eResourceType {
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};

	enum class eComponentType
	{
		Transform,
		Colider,
		Rigidbody,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End,
	};
}