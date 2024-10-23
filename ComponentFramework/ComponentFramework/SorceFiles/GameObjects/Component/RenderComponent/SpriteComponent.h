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
    SpriteComponent(class GameObject* owner, int drawOrder = 100);
    ~SpriteComponent(void);

    void SetObjectName(std::string objectName);
    void Draw(void);

    int GetDrawOrder(void) { return draw_order_; }

    TypeID GetComponentType(void) const override { return TypeID::SpriteComponent; }

private:
    int draw_order_;
    std::string object_name_;
};


#endif	// SPRITE_COMPONENT_H_
//==================================================
//				End of FIle
//==================================================#include "../RenderComponent.h"

