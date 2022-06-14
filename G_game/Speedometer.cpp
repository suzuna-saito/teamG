#include "Speedometer.h"
#include "BackGround.h"

Speedometer::Speedometer()
	: UIBase(SceneBase::mIsScene)
	, MArrowMinPosX(60.0f)
	, MArrowMaxPosX(540.0f)
	, MSpeedControlSoon(0.15f)
	, MSpeedControlSlow(0.186f)
	, mMoveSpeed(0.0f)
{
	// �摜�̓ǂݍ���
	mImage = LoadGraph("data/assets/Meter.png");       // ���[�^�[
	mArrowImage = LoadGraph("data/assets/Arrow.png");  // �O�p�摜

	// �|�W�V�����̐ݒ�
	mPos.x = 75.0f;                // ���[�^�̃|�W�V������
	mPos.y = 900.0f;               // ���[�^�̃|�W�V������
	mArrowPos.x = MArrowMinPosX;   // �O�p�̃|�W�V������
	mArrowPos.y = 850.0f;          // �O�p�̃|�W�V����y
}

Speedometer::~Speedometer()
{
}

void Speedometer::Update(float _deltaTime)
{
	// �w�i�̃X�N���[���X�s�[�h�𗘗p���Ĉړ����x�̐���
	if (Background::mNowSpeed == Background::Speed::eAcceleration)
	{
		mMoveSpeed = Background::mMoveSpeed * -MSpeedControlSoon;
	}
	else if (Background::mNowSpeed == Background::Speed::eDeceleration)
	{
		mMoveSpeed = Background::mMoveSpeed * MSpeedControlSlow;
	}

	// �O�p�̃|�W�V�����X�V
	mArrowPos.x += mMoveSpeed * _deltaTime;

	// ��������
	if (mArrowPos.x < MArrowMinPosX)
	{
		mMoveSpeed = 0.0f;
		mArrowPos.x = MArrowMinPosX;
	}
	if (mArrowPos.x > MArrowMaxPosX)
	{
		mMoveSpeed = 0.0f;
		mArrowPos.x = MArrowMaxPosX;
	}
}

void Speedometer::Draw()
{
	// �`��
	DrawGraph((int)mPos.x, (int)mPos.y, mImage, true);                 // ���[�^�[
	DrawGraph((int)mArrowPos.x, (int)mArrowPos.y, mArrowImage, true);  // �O�p
}
