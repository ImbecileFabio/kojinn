//==================================================
// [SpriteComponent.h] 描画コンポーネント
// 著者：有馬啓太
//--------------------------------------------------
// 説明：とても描画コンポーネントの宣言
//==================================================
#ifndef SPRITE_COMPONENT_H_
#define SPRITE_COMPONENT_H_

/*----- インクルード -----*/
#include "../RenderComponent.h"
/*----- 構造体定義 -----*/

/*----- 前方宣言 -----*/

//--------------------------------------
// 描画クラス
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

