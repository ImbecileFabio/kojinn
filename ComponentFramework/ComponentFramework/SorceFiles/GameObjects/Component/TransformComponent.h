//==================================================
// [TransformComponent.h] �p������R���|�[�l���g
// ���ҁF�L�n�[��
//--------------------------------------------------
// �����F�p������R���|�[�l���g�̃x�[�X
//==================================================
#ifndef TRANSFORM_COMPONENT_H_
#define TRANSFORM_COMPONENT_H_

/*----- �C���N���[�h -----*/
#include <SimpleMath.h>
#include "../Component.h"
#include "../../subSystem/dx11helper.h"


/*----- �\���̒�` -----*/

/*----- �O���錾 -----*/

//--------------------------------------------------
// �p������R���|�[�l���g
//--------------------------------------------------
class TransformComponent : Component
{
public:
	TransformComponent(class GameObject* owner, int updateOrder = 100);
	~TransformComponent(void);

	void Init(void) override;
	void Uninit(void) override;
	void Update(void) override;

	void CallTransform(void);

	virtual TypeID GetComponentType() const override { return TypeID::TransformComponent; }

private:
	// SRT���i�p�����j
	DirectX::SimpleMath::Vector3 m_Position = DirectX::SimpleMath::Vector3(0.0f, 0.0f, 0.0f);
	DirectX::SimpleMath::Vector3 m_Rotation = DirectX::SimpleMath::Vector3(0.0f, 0.0f, 0.0f);
	DirectX::SimpleMath::Vector3 m_Scale = DirectX::SimpleMath::Vector3(1.0f, 1.0f, 1.0f);


};

#endif	// TRANSFORM_COMPONENT_H_
//==================================================
//				End of FIle
//==================================================

