//==================================================
// [SpriteComponent.h] �`��R���|�[�l���g
// ���ҁF�L�n�[��
//--------------------------------------------------
// �����F�ƂĂ��`��R���|�[�l���g�̐錾
//==================================================

/*----- �C���N���[�h -----*/
#include "../../../StdAfx.h"
#include "SpriteComponent.h"
#include "../../GameObject.h"
#include "../../../GameManager.h"
#include "../../../Renderer.h"

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
SpriteComponent::SpriteComponent(GameObject* owner, int drawOrder)
	: RenderComponent(owner)
	, draw_order_(draw_order_)
{
	this->owner_->GetGameManager()->GetRenderer()->AddSprite(this);

	object_name_ = std::string("�s���ȃI�u�W�F�N�g");
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
SpriteComponent::~SpriteComponent(void)
{
}

//--------------------------------------------------
// ���O���`����֐�
//--------------------------------------------------
void SpriteComponent::SetObjectName(std::string _objectName)
{
	object_name_ = _objectName;
}

void SpriteComponent::Draw(void)
{
	std::cout << object_name_ + "�̉摜���`�悳�ꂽ\n";


}
