//==================================================
// [ColliderComponent.h] �R���C�_�[�̃x�[�X
// ���ҁF�L�n�[��
//--------------------------------------------------
// �����F�������ł�
//==================================================
#ifndef COLLIDER_COMPONENT_H_
#define COLLIDER_COMPONENT_H_

/*----- �C���N���[�h -----*/
#include "../Component.h"
#include "../../subSystem/IndexBuffer.h "
#include "../../subSystem/VertexBuffer.h "

/*----- �\���̒�` -----*/

/*----- �O���錾 -----*/

//--------------------------------------------------
// �R���C�_�[�R���|�[�l���g
//--------------------------------------------------
class ColliderComponent :
    public Component
{
public:
    ColliderComponent(class GameObject* owner, int updateOrder = 100);
    ~ColliderComponent(void);

    void Init();

    virtual TypeID GetComponentType() const override { return TypeID::ColliderComponent; }

private:
    IndexBuffer	 m_IndexBuffer; // �C���f�b�N�X�o�b�t�@
    VertexBuffer<VERTEX_3D>	m_VertexBuffer; // ���_�o�b�t�@

};



#endif	// COLLIDER_COMPONENT_H_
//==================================================
//				End of FIle
//==================================================
