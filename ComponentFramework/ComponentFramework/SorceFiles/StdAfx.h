//==================================================
// [StdAfx.h] Standard Application Framework Extensions�w�b�_
// ���ҁF�L�n�[��
//--------------------------------------------------
// �����F�܂�C���N���[�h����ꏊ
//==================================================

#ifndef STDAFX_H_
#define STDAFX_H_

#undef UNICODE


#define _CRT_SECURE_NO_WARNINGS

/*----- �C���N���[�h -----*/
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <functional>
#include <locale.h>
#include <string>
#include <cstdint>
#include <chrono>
#include <thread>
#include <vector>
#include <memory>

#pragma warning(push)
#pragma warning(disable:4005)

#pragma warning(pop)

#pragma comment (lib,"winmm.lib")

constexpr uint32_t SCREEN_WIDTH = 1280;
constexpr uint32_t SCREEN_HEIGHT = 720;


/*----- �\���̒�` -----*/

/*----- �O���錾 -----*/


#endif	// STDAFX_H_
//==================================================
//				End of FIle
//==================================================
