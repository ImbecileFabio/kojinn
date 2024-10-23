//=================================================================
// [GameManager.h] �Q�[���}�l�[�W���[���W���[���w�b�_
// ���ҁF�L�n�[��
//-----------------------------------------------------------------
// �����F�Q�[���̏�Ԃ�I�u�W�F�N�g���Ǘ����邽�߂̃N���X
//=================================================================
#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_


/*----- �C���N���[�h -----*/
#include "StdAfx.h"
/*----- �\���̒�` -----*/

/*----- �O���錾 -----*/

//-----------------------------------------------------------------
// �Q�[���}�l�[�W���[�N���X
//-----------------------------------------------------------------
class GameManager
{
public:
	GameManager(void);
	~GameManager(void);
	
	class GameManager* Create(void)
	{
		return new GameManager();
	}

	void InitAll(void);
	void UninitAll(void);
	void UpdateAll(void);
	void GenerateOutputAll(void);

	class Renderer* GetRenderer(void) { return renderer_; }

	// �Q�[���I�u�W�F�N�g�̒ǉ�
	void AddGameObject(class GameObject* gameObject);
	void RemoveGameObject(class GameObject* gameObject);

private:
	void UpdateGameObjects(void);	//�X�V����

	// �I�u�W�F�N�g���X�V�����m�F
	bool updating_game_objects_;

	// �Q�[���I�u�W�F�N�g
	std::vector<class GameObject*> game_objects_;
	std::vector<class GameObject*> pending_game_objects_;

private:
	// ������I�u�W�F�N�g�������ɋL�q
	class Renderer* renderer_;	// �����_���[
};


#endif GAME_MANAGER_H_
//=================================================================
//			End of File 
//=================================================================

