// �C���N���[�h
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"
#include "Background.h"


Player::Player()
	:mMouseX(0)
	,mMouseY(0)
	,mClickLog(0)
	,mClickTmpLog(0)
	,mBackground(0)
	, mLandingSpeed(0)
	, mLandDis(0)
{
	//�v���C���[�̏����ʒu�̑��
	mPlayerX = FIRSTPOSX;
	mPlayerY = FIRSTPOSY;
	//�v���C���[�摜�̓ǂݍ���
	pImage = LoadGraph("data/assets/Player.png");
	//�}�E�X�N���b�N�̏�����
	mMouseClick = FALSE;

}

Player::~Player()
{
}

/// <summary>
/// �v���C���[�̕`��
/// </summary>
void Player::PlayerDraw()
{
	int StringCr, BoxCr = 0;
	// ��ʍ���̗̈�ɍ����l�p��`���O�ɕ`���Ă����������������
	DrawBox(0, 0, 640, 32, BoxCr, TRUE);

	// ���F�̒l���擾
	StringCr = GetColor(255, 255, 255);
	// ���̒l���擾
	BoxCr = GetColor(0, 0, 0);
	// ���W�������`��
	DrawFormatString(0, 0, StringCr, "�������O�̑��x:%d", mLandingSpeed);
	//��������Ԃ̊m�F
	DrawFormatString(300, 0, StringCr, "%d�@�@%d", mClickLog, mClickTmpLog);


	DrawGraph(mPlayerX, mPlayerY, pImage, TRUE);
}

void Player::BesidePlayerMove()
{
	/// �}�E�X�̍��W���Ƃ�
	GetMousePoint(&mMouseX, &mMouseY);
	
	/// ��ʂ̍����ɃJ�[�\��������A�N���b�N�����ꍇLeftPos�Ɉړ�����
	if (mMouseX <= ScreenBeside / 3 && MouseLeftClick())
		mPlayerX = LEFTPOSX;


	/// ��ʂ̐^�񒆂ɃJ�[�\��������A�N���b�N�����ꍇMiddlePos�Ɉړ�����
	else if ((ScreenBeside / 3 < mMouseX) && (mMouseX <= ScreenBeside * 2 / 3) && MouseLeftClick())
		mPlayerX = MIDDLEPOSX;


	/// ��ʂ̉E���ɃJ�[�\��������A�N���b�N�����ꍇLeftPos�Ɉړ�����
	else if (mMouseX > ScreenBeside * 2/ 3 && MouseLeftClick())
		mPlayerX = RIGHTPOSX;
}

int Player::MouseLeftClick()
{
	//���N���b�N���ꂽ��
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		mClickTmpLog = 1;
		return TRUE;
	}
	//���N���b�N����Ȃ�������
	else
	{
		mClickTmpLog = 0;
		return FALSE;
	}
}

int  Player::MouseLongPress()
{
	//�O�t���[���Ɣ�r����
	if (mClickTmpLog == mClickLog)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Player::PlayerSpeed()
{
	if (MouseLongPress())
	{
		Background::mMoveSpeed;
	}
	mClickLog = mClickTmpLog;
}

void Player::PlayerLandingPreparation(float _deltaTime)
{
	mLandDis = mBackground->GetTotalLength();

	if (mLandDis == BEFORELANDING)
	{
		mLandingSpeed = Background::mMoveSpeed * _deltaTime;
	}
}

void Player::PlayerLanding()
{
	if (Background::mMoveSpeed == 0)
	{
		mPlayerY += (int)mLandingSpeed;
	}
}

