#include "Background.h"
#include "Speedometer.h"
#include "Dxlib.h"

// ����
// �X�s�[�h���}�C�i�X�ɂȂ�قǑ����B(Y���̏オ�}�C�i�X�Ȃ̂�)

// �ÓI�����o�ϐ��̏�����
Background::Speed Background::mNowSpeedType = Speed::eAcceleration;
float Background::mMoveSpeed = 0;

Background::Background()
	: MHeight(-1080)
	, MAcceleration(-4.5f)
	, MDeceleration(-5.0f)
	, MMaxSpeed(-1300.0f)
	, MMinSpeed(-500.0f)
	, MScrollNum(50)
	, MAdjustmentLength(MScrollNum * 25)
	, mBackgroundPosY(0.0f)
	, mScrollCount(0)
	, mEndFlag(false)
{
	// ����
	mMoveSpeed = -1300.0f;
	// �X�s�[�h�^�C�v�̏�����
	mNowSpeedType = Speed::eAcceleration;

	// �w�i�摜�̓ǂݍ���
	mBackgroundImage = LoadGraph("data/assets/BackgroundSky.png");     // ��
	mEndBackgroundImage = LoadGraph("data/assets/BackgroundEnd.png");  // �n��

	// �c��̒����̍��v�̌v�Z
	mTotalLength = (MScrollNum + 1) * (MHeight * -1) + MAdjustmentLength;
}

Background::~Background()
{
	DeleteGraph(mBackgroundImage);
}

void Background::Update(float _deltaTime)
{
	
	if (!mEndFlag)
	{
		// �{�^����������Ă����� ���A�X�N���[�����x���ŏ����x����Ȃ�������
		if (CheckHitKey(KEY_INPUT_A) && mMoveSpeed < MMinSpeed)
		{
			mMoveSpeed -= MDeceleration;             // �X�N���[�����x��x������
			mNowSpeedType = Speed::eDeceleration;   // �^�O���������ɂ���
		}
		// �{�^����������Ă��Ȃ������� ���A�X�N���[�����x���ő呬�x����Ȃ�������
		else if (!CheckHitKey(KEY_INPUT_A) && mMoveSpeed > MMaxSpeed)
		{
			mMoveSpeed += MAcceleration;            // �X�N���[�����x�𑁂�����
			mNowSpeedType = Speed::eAcceleration;  // �^�O���������ɂ���
		}

		// �w�i�|�W�V�����̍X�V
		mBackgroundPosY += mMoveSpeed * _deltaTime;
	}

	// @@@test
	mTotalLength += mMoveSpeed * _deltaTime;

	// �w�i�̕`��J��Ԃ�����
	// �X�N���[�����J��Ԃ����񐔂��w��̉񐔂܂ōs���ĂȂ�������
	if (mScrollCount != MScrollNum)
	{
		if (mBackgroundPosY <= MHeight)     // �ꖇ�ڂ̉摜����ʊO�ɍs�������ɏ����l�ɖ߂�
		{
			mBackgroundPosY = 0.0f;
			++mScrollCount;
		}
	}
	// �w��񐔃X�N���[�����J��Ԃ��āA�Ō�̔w�i���`�悳�ꂽ��
	else if (mBackgroundPosY <= MHeight && !mEndFlag)
	{
		mMoveSpeed = 0.0f;
		mEndFlag = true;                   // mEndFlag��true�ɂ���
		mNowSpeedType = Speed::eLanding;   // �^�O�𒅒n�ɂ���
	}
}

void Background::Draw()
{
	// �w�i�̕`��
	DrawGraph(0, (int)mBackgroundPosY, mBackgroundImage, TRUE);

	// �X�N���[�����J��Ԃ����񐔂��w��̉񐔂܂ōs���ĂȂ�������
	if (mScrollCount != MScrollNum)
	{
		DrawGraph(0, (int)mBackgroundPosY - MHeight, mBackgroundImage, TRUE);   // ��̉摜��`��
	}
	// �X�N���[�����J��Ԃ����񐔂��w��̉񐔂܂ōs������
	else
	{
		DrawGraph(0, (int)mBackgroundPosY - MHeight, mEndBackgroundImage, TRUE); // �n�ʂ̉摜��`��
	}
}

