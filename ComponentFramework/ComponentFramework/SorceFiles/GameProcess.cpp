//==================================================
// [GameProcess.h] �Q�[�����s�������W���[��
// ���ҁF�L�n�[��
//--------------------------------------------------
// �����F�Q�[���̎��s�������܂Ƃ߂��N���X�̒�`
//		 �E�B���h�E�̍쐬
//==================================================

/*----- �C���N���[�h -----*/
#include "StdAfx.h"
#include "GameProcess.h"
#include "GameManager.h"
#include "Renderer.h"

const auto ClassName = TEXT("2024 framework �ЂȌ`");	// �E�B���h�E�N���X
const auto WindowName = TEXT("2024 framework �ЂȌ`(�t�B�[���h�`��)");	// �E�B���h�E��

HINSTANCE	GameProcess::hInst_;		// �C���X�^���X�n���h��
HWND		GameProcess::hWnd_;			// �E�B���h�E�n���h��
uint32_t	GameProcess::width_;		// �E�B���h�E�̉���
uint32_t	GameProcess::height_;		// �E�B���h�E�̏c��

//--------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------
GameProcess::GameProcess(uint32_t width, uint32_t height)
	: game_manager_(nullptr)
{
	width_ = width;
	height_ = height;

	timeBeginPeriod(1);
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
GameProcess::~GameProcess(void)
{
	timeEndPeriod(1);
}

//--------------------------------------------------
// �N������
//--------------------------------------------------
bool GameProcess::StartUp(void)
{
	std::cout << "[�Q�[���v���Z�X] -> �N��\n";
	std::cout << "\n";

	// �����������ǂ���
	bool is_init_success;

	is_init_success = GameProcess::Init();

	return is_init_success;
}

//--------------------------------------------------
// ���s����
//--------------------------------------------------
void GameProcess::Run(void)
{
	std::cout << "[�Q�[���v���Z�X] -> ���s\n";
	std::cout << "\n";

	// ���b�Z�[�W
	MSG msg = {};

	// FPS�v���p�ϐ�
	int fpsCounter = 0;
	long long oldTick = GetTickCount64(); // �O��v�����̎���
	long long nowTick = oldTick; // ����v�����̎���

	// FPS�Œ�p�ϐ�
	LARGE_INTEGER liWork; // work�����ϐ��͍�Ɨp�ϐ�
	long long frequency;// �ǂꂭ�炢�ׂ������Ԃ��J�E���g�ł��邩
	QueryPerformanceFrequency(&liWork);
	frequency = liWork.QuadPart;
	// ���ԁi�P�ʁF�J�E���g�j�擾
	QueryPerformanceCounter(&liWork);
	long long oldCount = liWork.QuadPart;// �O��v�����̎���
	long long nowCount = oldCount;// ����v�����̎���

	//--------------------------------------------------
	// �Q�[�����[�v
	//--------------------------------------------------
	while (true)
	{
		// �V���Ƀ��b�Z�[�W�������
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// �E�B���h�E�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			// �uWM_QUI�v���b�Z�[�W���󂯎�����烋�[�v�𔲂���
			if (msg.message == WM_QUIT) { break; }
		}
		else
		{
			QueryPerformanceCounter(&liWork);	// ���ݎ��Ԃ��擾
			nowCount = liWork.QuadPart;
			// 1/60	�b���o�߂�����?
			if (nowCount >= oldCount + frequency / 60)
			{
				GameProcess::Update();
				GameProcess::GenerateOutput();

				fpsCounter++;	// �Q�[�������s������+1����
				oldCount = nowCount;
			}
		}
	}

	// �I������
	//Uninit();
}

//--------------------------------------------------
// ��~����
//--------------------------------------------------
void GameProcess::ShutDown(void)
{
	std::cout << "[�Q�[���v���Z�X] -> ��~\n";

	GameProcess::Uninit();
}

//--------------------------------------------------
// ����������
//--------------------------------------------------
bool GameProcess::Init(void)
{
	std::cout << "[�Q�[���v���Z�X] -> �������������J�n��\n";

	{
		// �E�B���h�E�𐶐�
		InitWnd();

		// �Q�[���}�l�[�W���𐶐�
		game_manager_ = game_manager_->Create();
		if (false) { return false; }
	}
	std::cout << "[�Q�[���v���Z�X] -> �������������I����\n";
	std::cout << "\n";

	return true;
}

//--------------------------------------------------
// �I������
//--------------------------------------------------
void GameProcess::Uninit(void)
{
	std::cout << "[�Q�[���v���Z�X] -> ���I�������J�n��\n";
	{
		delete game_manager_;
	}

	std::cout << "[�Q�[���v���Z�X] -> ���I�������I����\n";
	std::cout << "\n";

}

//--------------------------------------------------
// �E�B���h�E�̏���������
//--------------------------------------------------
bool GameProcess::InitWnd(void)
{
	std::cout << "[�Q�[���v���Z�X] -> �E�B���h�E�������J�n\n";

	// �C���X�^���X�n���h�����擾
	auto hInst = GetModuleHandle(nullptr);
	if (hInst == nullptr) { return false; }

	// �E�B���h�E�̐ݒ�
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.hIcon = LoadIcon(hInst, IDI_APPLICATION);
	wc.hCursor = LoadCursor(hInst, IDC_ARROW);
	wc.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = ClassName;
	wc.hIconSm = LoadIcon(hInst, IDI_APPLICATION);

	// �E�B���h�E�̓o�^
	if (!RegisterClassEx(&wc)) { return false; }

	// �C���X�^���X�n���h���ݒ�
	hInst_ = hInst;
	
	// �E�B���h�E���̃T�C�Y��ݒ�
	RECT rc = {};
	rc.right = static_cast<LONG>(width_);
	rc.bottom = static_cast<LONG>(height_);

	// �E�B���h�E�̃T�C�Y�𒲐�
	auto style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
	AdjustWindowRect(&rc, style, FALSE);

	// �E�B���h�E�𐶐�.
	hWnd_ = CreateWindowEx(
		0,
		//        WS_EX_TOPMOST,
		ClassName,
		WindowName,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		rc.right - rc.left,
		rc.bottom - rc.top,
		nullptr,
		nullptr,
		hInst_,
		nullptr);

	if (hWnd_ == nullptr)
	{
		return false;
	}

	// �E�B���h�E��\��.
	ShowWindow(hWnd_, SW_SHOWNORMAL);

	// �E�B���h�E���X�V.
	UpdateWindow(hWnd_);

	// �E�B���h�E�Ƀt�H�[�J�X��ݒ�.
	SetFocus(hWnd_);

	std::cout << "[�Q�[���v���Z�X] -> �E�B���h�E�������I��\n";

	// ����I��.
	return true;
}

//--------------------------------------------------
// �E�B���h�E�̏I������
//--------------------------------------------------
void GameProcess::UninitWnd(void)
{
	std::cout << "[�Q�[���v���Z�X] -> �E�B���h�E�I�������J�n\n";

	// �E�B���h�E�̓o�^������
	if(hInst_ != nullptr)
	{
		UnregisterClass(ClassName, hInst_);	
	}

	hInst_ = nullptr;
	hWnd_ = nullptr;

	std::cout << "[�Q�[���v���Z�X] -> �E�B���h�E�I�������J�n\n";
	std::cout << "\n";
}


//--------------------------------------------------
// �X�V����
//--------------------------------------------------
void GameProcess::Update(void)
{
	std::cout << "[�Q�[���v���Z�X] -> ���X�V�����J�n��\n";

	{
		game_manager_->UpdateAll();
	}
	std::cout << "[�Q�[���v���Z�X] -> ���X�V�����I����\n";
	std::cout << "\n";

}

//--------------------------------------------------
// �o�͐�������
//--------------------------------------------------
void GameProcess::GenerateOutput(void)
{
	std::cout << "[�Q�[���v���Z�X] -> ���o�͐��������J�n��\n";

	{
		// �I�u�W�F�N�g�`��
		game_manager_->GenerateOutputAll();
	}
	std::cout << "[�Q�[���v���Z�X] -> ���o�͐��������I����\n";
	std::cout << "\n";
}

//--------------------------------------------------
// �E�B���h�E�v���V�[�W��
//--------------------------------------------------
LRESULT CALLBACK GameProcess::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:	// �E�B���h�E�j�����b�Z�[�W
	{
		PostQuitMessage(0);	// �uWM_QUIT�v ���b�Z�[�W�𑗂� -> �A�v���I��
	}
	break;

	case WM_CLOSE:	// �ux�v�{�^���������ꂽ��
	{
		int res = MessageBoxA(NULL, "�����܂��H", "�m�F", MB_OKCANCEL);
		if (res == IDOK)
		{
			DestroyWindow(hWnd);	// �uWM_DESTROY�v���b�Z�[�W�𑗂�
		}
	}
	break;

	case WM_KEYDOWN:	// �L�[���͂����������b�Z�[�W
	{
		if (LOWORD(wParam) == VK_ESCAPE)	// ���͂��ꂽ�L�[��ESC�Ȃ�
		{
			PostMessage(hWnd, WM_CLOSE, wParam, lParam);	// �uWM_CLOSE�v�𑗂�
		}
	}
	break;

	default:	// �󂯎�������b�Z�[�W�ɑ΂��ăf�t�H���g�̏��������s
	{
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}
	}

	return 0;
}
//==================================================
//				End of FIle
//==================================================