//==================================================
// [GameProcess.h] �Q�[�����s�������W���[���w�b�_
// ���ҁF�L�n�[��
//--------------------------------------------------
// �����F�Q�[���̎��s�������܂Ƃ߂��N���X�炵��
//		 �E�B���h�E�̍쐬�����˂Ă܂�
//==================================================
#ifndef GAME_PROCESS_H_
#define GAME_PROCESS_H_

/*----- �C���N���[�h -----*/
#include "StdAfx.h"
/*----- �\���̒�` -----*/


/*----- �O���錾 -----*/


//--------------------------------------------------
// �Q�[���v���Z�X�N���X
//--------------------------------------------------
class GameProcess
{
public:
	GameProcess(uint32_t width, uint32_t height);
	~GameProcess(void);

	bool StartUp(void);
	void Run(void);
	void ShutDown(void);

	// �����擾
	static uint32_t GetWidth() { return width_; }

	// �������擾
	static uint32_t GetHeight() { return height_; }
	
	// �E�B���h�E�n���h����Ԃ�
	static HWND GetWindow(){ return hWnd_; }

private:
	static HINSTANCE hInst_;	// �C���X�^���X�n���h��
	static HWND		 hWnd_;		// �E�B���h�E�n���h��
	static uint32_t	 width_;	// �E�B���h�E�̉���
	static uint32_t	 height_;	// �E�B���h�E�̏c��

	class GameManager* game_manager_;

	bool Init(void);
	void Uninit(void);
	bool InitWnd(void);
	void UninitWnd(void);
	void Update(void);
	void GenerateOutput(void);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
};

#endif // GAME_PROCESS_H_
//==================================================
//				End of FIle
//==================================================
