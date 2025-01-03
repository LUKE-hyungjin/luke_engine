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
		Floor,
		Particle,
		Max = 16,
	};

	enum class eResourceType {
		Texture,
		Mesh,
		Animation,
		AudioClip,
		Shader,
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