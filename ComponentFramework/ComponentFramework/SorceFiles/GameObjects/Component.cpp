//==================================================
// [Component.cpp] コンポーネントのベース
// 著者：有馬啓太
//--------------------------------------------------
// 説明：コンポーネントの大元の定義
//==================================================

/*----- インクルード -----*/
#include "Component.h"
#include "GameObject.h"

// コンポーネントのリスト
const char* Component::ComponentTypeNames[static_cast<int>(TypeID::MAX)] =
{
	// 自分自身
	"Component"

	//ここに追加したコンポーネントを記述していく
	// レンダリング
	, "RenderComponent"
	, "SpriteComponent"
	
	// 衝突判定
	, "ColliderComponent"

	// 姿勢制御
	, "TransformComponent"

};

//--------------------------------------------------
// コンストラクタ
//--------------------------------------------------
Component::Component(GameObject* owner, int updateOrder)
	: owner_(owner)
	, update_order_(updateOrder)
{
	owner_->AddComponent(this);
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
Component::~Component(void)
{
	owner_->RemoveComponent(this);
}

//--------------------------------------------------
// 初期化処理
//--------------------------------------------------
void Component::Init(void)
{
}

//--------------------------------------------------
// 終了処理
//--------------------------------------------------
void Component::Uninit(void)
{
}

//--------------------------------------------------
// 更新処理
//--------------------------------------------------
void Component::Update(void)
{
}

//--------------------------------------------------
// コンポーネントの姿勢制御の更新
//--------------------------------------------------
void Component::OnUpdateWorldTransform()
{
}

//--------------------------------------------------
// コンポーネントの状態の読み込み
//--------------------------------------------------
void Component::LoadProperties(void)
{
}

//--------------------------------------------------
// コンポーネントの状態の保存
//--------------------------------------------------
void Component::SaveProperties(void)
{
}

//--------------------------------------------------
//				End of File
//--------------------------------------------------
