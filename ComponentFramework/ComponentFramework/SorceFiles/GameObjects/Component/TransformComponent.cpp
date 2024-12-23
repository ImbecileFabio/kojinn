//==================================================
// [TransformComponent.h] 姿勢制御コンポーネント
// 著者：有馬啓太
//--------------------------------------------------
// 説明：姿勢制御コンポーネントのベース
//==================================================

/*----- インクルード -----*/
#include "../../StdAfx.h"
#include "TransformComponent.h"

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
TransformComponent::TransformComponent(GameObject* owner, int updateOrder)
	: Component(owner, updateOrder)
{

}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
TransformComponent::~TransformComponent(void)
{
}

//--------------------------------------------------
// 初期化処理
//--------------------------------------------------
void TransformComponent::Init(void)
{
}

//--------------------------------------------------
// 終了処理
//--------------------------------------------------
void TransformComponent::Uninit(void)
{
}

//--------------------------------------------------
// 更新処理
//--------------------------------------------------
void TransformComponent::Update(void)
{
	CallTransform();
}

//--------------------------------------------------
// 呼び出し処理
//--------------------------------------------------
void TransformComponent::CallTransform(void)
{
	std::cout << "[Transform] -> 呼び出し\n";
}

//=================================================================
//			End of File 
//=================================================================