#pragma once

// �C���N���[�h
#include "DxLib.h"

//�v���C���[�̏����ʒu
const int FirstPosX = 325;
const int FirstPosY = 100;

const int LeftPosX = 162;
const int MiddlePosX = 325;
const int RightPosX = 487;

//�v���C���[�N���X
class Player
{
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	/// <summary>
	/// �v���C���[�̏������W���
	/// </summary>
	/// <param name="a">�@X���W�@</param>
	/// <param name="b">�@Y���W�@</param>
	void FirstPostion();

	/// <summary>
	/// �v���C���[�̕`��
	/// </summary>
	void PlayerDraw();

	void PlayerMove();


private:

	int pImage;
	int m_PlayerX;
	int m_PlayerY;
	int m_MouseX;
	int m_MouseY;
};