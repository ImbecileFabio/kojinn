//==================================================
// [Component.h] �R���|�[�l���g�x�[�X�w�b�_
// ���ҁF�L�n�[��
//--------------------------------------------------
// �����F�R���|�[�l���g�̑匳
//==================================================
#ifndef COMPONENT_H_
#define COMPONENT_H_

/*----- �C���N���[�h -----*/

/*----- �\���̒�` -----*/

/*----- �O���錾 -----*/


//--------------------------------------------------
// �R���|�[�l���g�N���X
//--------------------------------------------------
class Component
{
public:
	enum class TypeID
	{
		None = -1
		// �x�[�X�N���X
		, Component

		// �����ɒǉ������R���|�[�l���g�������Ă���
		, RenderComponent
		, SpriteComponent
		, PlayerComponent

		// �R���|�[�l���g�̍ő�l
		, MAX
	};

	static const char* ComponentTypeNames[static_cast<int>(TypeID::MAX)];

public:
	Component(class GameObject* gameObject, int updateOrder = 100);
	virtual ~Component(void);

	virtual void Init(void);
	virtual void Uninit(void);
	virtual void Update(void);

	virtual void OnUpdateWorldTransform();

	// ��ŃT�u�N���X���������㏑���ł���悤��
	virtual void CallComponent(void) {};


	class GameObject* GetOwner(void) { return owner_; }
	int GetUpdateOrder(void) const { return update_order_; }

	virtual TypeID GetComponentType() const = 0;

	// ���[�h, �Z�[�u
	virtual void LoadProperties(void);
	virtual void SaveProperties(void);

protected:
	class GameObject* owner_;	// �����i�R���|�[�l���g�j�̏��L��
	int update_order_;			// �������g�̍X�V����
};


#endif	// COMPONENT_H_
//==================================================
//				End of FIle
//==================================================
