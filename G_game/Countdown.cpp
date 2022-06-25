#include "Countdown.h"

Countdown::Countdown()
	: UIBase(SceneBase::mIsScene)
	, MAllnum(10)
	, MNumX(5), MNumY(2)
	, MSizeX(40), MSizeY(50)
	, Mdigit(3)
	, MOneSecond(1000)
	, mDivisionImage()
	, mStartTime(GetNowCount())
	, mNowTime(300)
	, mSubTime(0)
{
	// �摜�̓ǂݍ���
	LoadDivGraph("data/assets/UI/Score2.png",      // ����
		MAllnum, MNumX, MNumY, MSizeX, MSizeY, mDivisionImage);

	// �|�W�V�����̐ݒ�
	mPos.x = 350.0f;        // �����̃|�W�V����X
	mPos.y = 10.0f;         // �����̃|�W�V����Y
	mNumeraPos.x = 630.0f;  // �����̃|�W�V����X
	mNumeraPos.y = 50.0f;   // �����̃|�W�V����Y
}

Countdown::~Countdown()
{
	DeleteGraph(mImage);

	for (int i = 0; i < NUM; ++i)
	{
		DeleteGraph(mDivisionImage[i]);
	}
}

void Countdown::Update(float _deltaTime)
{
	// ���n���Ă��Ȃ��Ƃ��A���A�v���J�n����1�b���߂����Ƃ�
	if (Background::mNowSpeedType != Background::Speed::eLanding &&
		GetNowCount()- mStartTime >= MOneSecond)
	{
		// ���[�^�̈ʒu�ɂ���Č��Z���Ă���
		mSubTime = 1;  // ���Z�l

		if (Speedometer::mMeterColor == Speedometer::MeterColor::eYellow)
		{
			mSubTime = mSubTime * 2;
		}
		else if (Speedometer::mMeterColor == Speedometer::MeterColor::eRed)
		{
			mSubTime = mSubTime * 3;
		}

		mNowTime -= mSubTime;        // ���݂̃^�C�������炷

		mStartTime = GetNowCount();  // �v���J�n���Ԃ̍X�V
	}
}

void Countdown::Draw()
{
	// �^�C���̕`��
	int num = 0;
	for (int i = 1; i < Mdigit + 1; ++i)
	{
		num = mNowTime % (int)pow(NUM, i);       // i���ڂ̐������擾
		num = num / pow(NUM, i - 1);

		DrawGraph((int)mNumeraPos.x - MSizeX * i, (int)mNumeraPos.y,
			mDivisionImage[num], true);          // i���ڂ̐�����`��
	}
}
