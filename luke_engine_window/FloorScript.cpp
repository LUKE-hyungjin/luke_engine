#include "FloorScript.h"
#include "CatScript.h"
#include "Input.h"
#include "Transform.h"
#include "LukeTime.h"
#include "GameObject.h"
#include "Animator.h"
#include "Object.h"
#include "Rigidbody.h"
namespace luke
{
	FloorScript::FloorScript()
	{
	}
	FloorScript::~FloorScript()
	{
	}
	void FloorScript::Initialize()
	{
	}
	void FloorScript::Update()
	{

	}
	void FloorScript::LateUpdate()
	{
	}
	void FloorScript::Render()
	{
	}
	void FloorScript::OnCollisionEnter(Collider* other)
	{
		Rigidbody* playerRb = other->GetOwner()->GetComponent<Rigidbody>();
		Transform* playerTr = other->GetOwner()->GetComponent<Transform>();
		Collider* playerCol = other;
		Rigidbody* floorRb = GetOwner()->GetComponent<Rigidbody>();
		Transform* floorTr = GetOwner()->GetComponent<Transform>();
		Collider* floorCol = GetOwner()->GetComponent<Collider>();
		float len = fabs(playerTr->GetPosition().y - floorTr->GetPosition().y);
		float scale = fabs(playerCol->GetSize().y * 100 / 2.0f - floorCol->GetSize().y * 100 / 2.0f);
		if (len < scale)
		{
			Vector2 playerPos = playerTr->GetPosition();
			playerPos.y -= (scale - len) - 1.0f;
			playerTr->SetPosition(playerPos);
		}
		playerRb->SetGround(true);
	}
	void FloorScript::OnCollisionStay(Collider* other)
	{
	}
	void FloorScript::OnCollisionExit(Collider* other)
	{
	}

}