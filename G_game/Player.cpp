// �C���N���[�h
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"

Player::Player() :m_PlayerX(0), m_PlayerY(0), m_MouseX(0), m_MouseY(0)
{

	//�v���C���[�̏����ʒu�̑��
	m_PlayerX = FirstPosX;
	m_PlayerY = FirstPosY;
	//�v���C���[�摜�̓ǂݍ���
	pImage = LoadGraph("data/assets/Player.png");
}

Player::~Player()
{
}

/// <summary>
/// �v���C���[�̕`��
/// </summary>
void Player::PlayerDraw()
{
	char StrBuf[128], StrBuf2[32];
	int StringCr, BoxCr = 0;
	// ��ʍ���̗̈�ɍ����l�p��`���O�ɕ`���Ă����������������
	DrawBox(0, 0, 640, 32, BoxCr, TRUE);

	// ���F�̒l���擾
	StringCr = GetColor(255, 255, 255);
	// ���̒l���擾
	BoxCr = GetColor(0, 0, 0);
	// ���W�������`��
	DrawFormatString(0, 0, StringCr, "���W�w %d�@�@���W�x %d", m_MouseX, m_MouseY);


	DrawGraph(m_PlayerX, m_PlayerY, pImage, TRUE);
}

void Player::PlayerMove()
{
	/// <summary>
	/// �}�E�X�̍��W���Ƃ�
	/// </summary>
	GetMousePoint(&m_MouseX, &m_MouseY);
	
	/// <summary>
	/// ��ʂ̍����ɃJ�[�\��������A�N���b�N�����ꍇLeftPos�Ɉړ�����
	/// </summary>
	if (m_MouseX <= ScreenBeside / 3 && GetMouseInput()&MOUSE_INPUT_LEFT) 
		m_PlayerX = LeftPosX;

	/// <summary>
	/// ��ʂ̐^�񒆂ɃJ�[�\��������A�N���b�N�����ꍇMiddlePos�Ɉړ�����
	/// </summary>
	else if ((ScreenBeside / 3 < m_MouseX) && (m_MouseX <= ScreenBeside * 2 / 3) && GetMouseInput() & MOUSE_INPUT_LEFT)
		m_PlayerX = MiddlePosX;

	/// <summary>
	/// ��ʂ̉E���ɃJ�[�\��������A�N���b�N�����ꍇLeftPos�Ɉړ�����
	/// </summary>
	else if (m_MouseX > ScreenBeside * 2/ 3 && GetMouseInput() & MOUSE_INPUT_LEFT)
		m_PlayerX = RightPosX;
}
