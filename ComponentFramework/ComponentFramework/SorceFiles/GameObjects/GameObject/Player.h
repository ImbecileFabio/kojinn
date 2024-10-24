//==================================================
// [Camera.h] �J�����I�u�W�F�N�g�w�b�_
// ���ҁF�L�n�[��
//--------------------------------------------------
// �����F�J�����̏�����錾
//==================================================
#ifndef PLAYER_H_
#define PLAYER_H_

/*----- �C���N���[�h -----*/
#include "../GameObject.h"
/*----- �\���̒�` -----*/

/*----- �O���錾 -----*/

//--------------------------------------------------
// �J�G���I�u�W�F�N�g
//--------------------------------------------------
class Player : public GameObject
{
public:
	Player(class GameManager* gameManager);
	~Player(void);

	void UpdateGameObject(void) override;

	virtual TypeID GetType(void) const { return TypeID::Player; }
private:
	class SpriteComponent* sprite_;
};


#endif	// PLAYER_H_
//==================================================
//				End of FIle
//==================================================

