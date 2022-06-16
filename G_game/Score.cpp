#include "Score.h"

// ���g�̃C���X�^���X�̏�����
Score* Score::mScore = nullptr;

Score::Score()
	: MAllnum(10)
	, MNumX(5), MNumY(2)
	, MSizeX(40), MSizeY(50)
	, Mdigit(6)
	, MSubScore(10)
	, mDivisionImage()
	, mPos()// @@@
	, mNowScore(100000)

{
	// �摜�̓ǂݍ���
	//LoadGraph("data/assets/UI/Score.png");      // ����
	LoadDivGraph("data/assets/UI/Score2.png",      // ����
		MAllnum,MNumX, MNumY, MSizeX, MSizeY, mDivisionImage);

	// �|�W�V�����̐ݒ�
	mNumeraPos.x = 630.0f;
	mNumeraPos.y = 20.0f;
}

Score::~Score()
{
	for (int i = 0; i < NUM; ++i)
	{
		DeleteGraph(mDivisionImage[i]);
	}
}

void Score::CreateInstance()
{
	if (mScore == nullptr)
	{
		// �C���X�^���X�𐶐�
		mScore = new Score();
	}
}

void Score::DeleteInstance()
{
	if (mScore != nullptr)
	{
		// �폜
		delete mScore;
	}
}

void Score::Update(float _deltaTime)
{
	int sub = 0;  // ���_��

	if (Background::mNowSpeedType != Background::Speed::eLanding)
	{
		if (Speedometer::mMeterColor == Speedometer::MeterColor::eYellow)
		{
			sub = mScore->MSubScore;
		}
		else if (Speedometer::mMeterColor == Speedometer::MeterColor::eRed)
		{
			sub = mScore->MSubScore * 2;
		}

		mScore->mNowScore -= sub;
	}
}

void Score::Draw()
{
	// �X�R�A�̕`��
	int num = 0;
	for (int i = 1; i < mScore->Mdigit+1; ++i)
	{
		num = mScore->mNowScore % (int)pow(NUM, i);      // i���ڂ̐������擾
		num = num / pow(NUM, i-1);

		DrawGraph((int)mScore->mNumeraPos.x - mScore->MSizeX * i, (int)mScore->mNumeraPos.y,
			mScore->mDivisionImage[num], true);          // i���ڂ̐�����`��
	}

}
