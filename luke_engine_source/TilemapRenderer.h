#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"
namespace luke
{
	class TilemapRenderer : public Component
	{
	public:
		TilemapRenderer();
		~TilemapRenderer();
		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render()  override;
		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }
		Vector2 GetIndex() const { return mIndex; }
		void SetIndex(Vector2 index) { mIndex = index; }
	public:
		static Vector2 TileSize;
		static Vector2 OriginTileSize;
		static Vector2 SelectedIndex;
	private:
		Vector2 mTileSize;
		graphics::Texture* mTexture;
		Vector2 mSize;
		Vector2 mIndex;
	};
}