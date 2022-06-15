#include "Speedometer.h"
#include "BackGround.h"

// �ÓI�����o�ϐ��̏�����
bool Speedometer::mArrowStopFlag = false;

Speedometer::Speedometer()
	: UIBase(SceneBase::mIsScene)
	, MArrowMinPosX(60.0f)
	, MArrowMaxPosX(540.0f)
	, MSpeedControlSoon(0.2f)
	, MSpeedControlSlow(0.2f)
	, MEndArrowSpeed(500.0f)
	, mMoveSpeed(0.0f)
{
	// �摜�̓ǂݍ���
	mImage = LoadGraph("data/assets/UI/Meter.png");       // ���[�^�[
	mArrowImage = LoadGraph("data/assets/UI/Arrow.png");  // �O�p�摜

	// �|�W�V�����̐ݒ�
	mPos.x = 75.0f;                // ���[�^�̃|�W�V������
	mPos.y = 950.0f;               // ���[�^�̃|�W�V������
	mArrowPos.x = MArrowMaxPosX;   // �O�p�̃|�W�V������
	mArrowPos.y = 900.0f;          // �O�p�̃|�W�V����y

	// �t���O�̏�����
	mArrowStopFlag = false;
}

Speedometer::~Speedometer()
{
	DeleteGraph(mImage);
	DeleteGraph(mArrowImage);
}

void Speedometer::Update(float _deltaTime)
{
	// �w�i�̃X�N���[���X�s�[�h�𗘗p���Ĉړ����x�̐���
	if (Background::mNowSpeedType == Background::Speed::eAcceleration)
	{
		mMoveSpeed = Background::mMoveSpeed * -MSpeedControlSoon;
	}
	else if (Background::mNowSpeedType == Background::Speed::eDeceleration)
	{
		mMoveSpeed = Background::mMoveSpeed * MSpeedControlSlow;
	}
	else if (Background::mNowSpeedType == Background::Speed::eLanding)
	{
		mMoveSpeed = -MEndArrowSpeed;
	}

	// �O�p�̃|�W�V�����X�V
	mArrowPos.x += mMoveSpeed * _deltaTime;

	// ��������
	if (mArrowPos.x < MArrowMinPosX)
	{
		mMoveSpeed = 0.0f;
		mArrowPos.x = MArrowMinPosX;

		if (Background::mNowSpeedType == Background::Speed::eLanding)  // ��ԍ��܂ŎO�p���s�����Ƃ�
		{                                                              // ���n���Ă���
			mArrowStopFlag = true;
		}
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
