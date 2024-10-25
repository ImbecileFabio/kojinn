//==================================================
// [SpriteComponent.h] �`��R���|�[�l���g
// ���ҁF�L�n�[��
//--------------------------------------------------
// �����F�ƂĂ��`��R���|�[�l���g�̐錾
//==================================================
#ifndef SPRITE_COMPONENT_H_
#define SPRITE_COMPONENT_H_

/*----- �C���N���[�h -----*/
#include "../RenderComponent.h"

/*----- �\���̒�` -----*/

/*----- �O���錾 -----*/

//--------------------------------------
// �`��N���X
//--------------------------------------------------
class SpriteComponent :
    public RenderComponent
{
public:
    SpriteComponent(class GameObject* owner, int drawOrder = 100);
    ~SpriteComponent(void);

    void SetObjectName(std::string _objectName);
    void Draw(void);

    // �X�V���ʂ�Ԃ�
    int GetDrawOrder(void) { return draw_order_; }
    // �R���|�[�l���g��ID��Ԃ�
    TypeID GetComponentType(void) const override { return TypeID::SpriteComponent; }

private:
    int draw_order_;            // �X�V����
    std::string object_name_;   // �I�u�W�F�N�g��
};


#endif	// SPRITE_COMPONENT_H_
//==================================================
//				End of FIle
//==================================================#include "../RenderComponent.h"

