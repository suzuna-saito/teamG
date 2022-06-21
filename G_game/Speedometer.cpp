#include "Speedometer.h"
#include "BackGround.h"

// �ÓI�����o�ϐ��̏�����
Speedometer::MeterColor Speedometer::mMeterColor = MeterColor::eGreen;

Speedometer::Speedometer()
	: UIBase(SceneBase::mIsScene)
	, MArrowMinPosX(60.0f)
	, MArrowMaxPosX(540.0f)
	, MYellowPos(440.0f)
	, MRedPos(260.0f)
	, MSpeedControlSoon(0.15f)
	, MSpeedControlSlow(0.15f)
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
}

Speedometer::~Speedometer()
{
	DeleteGraph(mImage);
	DeleteGraph(mArrowImage);
}

void Speedometer::Update(float _deltaTime)
{
	// �w�i�̃X�N���[���X�s�[�h�𗘗p���Ĉړ����x�̏���
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
		mMoveSpeed = 0.0f;
	}

	// �O�p�̃|�W�V�����X�V
	mArrowPos.x += mMoveSpeed * _deltaTime;

	// ���݂̎O�p�̃|�W�V�����ɂ���ă^�C�v��ύX����
	if (mArrowPos.x <= MRedPos)
	{
		mMeterColor = MeterColor::eRed;
	}
	else if (mArrowPos.x <= MYellowPos)
	{
		mMeterColor = MeterColor::eYellow;
	}
	else
	{
		mMeterColor = MeterColor::eGreen;
	}

	// �ړ�����
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
	DrawGraph((int)mPos.x, (int)mPos.y, mImage, TRUE);                 // ���[�^�[
	DrawGraph((int)mArrowPos.x, (int)mArrowPos.y, mArrowImage, TRUE);  // �O�p
}
