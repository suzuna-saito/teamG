#include "Score.h"

// ���g�̃C���X�^���X�̏�����
Score* Score::mScore = nullptr;

Score::Score()
	: MAllnum(10)
	, MNumX(5), MNumY(2)
	, MSizeX(40), MSizeY(50)
	, Mdigit(6)
	, MMaxScore(100000)
	, MSubScore(10)
	, mDivisionImage()
	, mNowScore(MMaxScore)
	, mTopScore(0)
	, mChangeScore(false)
{
	// �摜�̓ǂݍ���
	mImage = LoadGraph("data/assets/UI/Score.png");// ����
	LoadDivGraph("data/assets/UI/Score2.png",      // ����
		MAllnum,MNumX, MNumY, MSizeX, MSizeY, mDivisionImage);

	// �|�W�V�����̐ݒ�
	mPos.x = 350.0f;        // �����̃|�W�V����X
	mPos.y = 10.0f;         // �����̃|�W�V����Y
	mNumeraPos.x = 630.0f;  // �����̃|�W�V����X
	mNumeraPos.y = 50.0f;   // �����̃|�W�V����Y
}

Score::~Score()
{
	DeleteGraph(mImage);

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
	// �^�C�g����ʂ̎�
	if (SceneBase::mIsScene == SceneBase::Scene::eTitle)
	{
	}

	// �v���C�����A���n���Ă��Ȃ��Ƃ�
	if (SceneBase::mIsScene == SceneBase::Scene::ePlay &&
		Background::mNowSpeedType != Background::Speed::eLanding)
	{
		if (mScore->mChangeScore)
		{
			mScore->mChangeScore = false;
		}
		
		mScore->mSubtract(); // ���[�^�̈ʒu�ɂ���Č��_���Ă���
	}

	// ���U���g��ʂ��A�ō����_�̕ύX���s���ĂȂ�������
	if (SceneBase::mIsScene == SceneBase::Scene::eResult && !mScore->mChangeScore)
	{
		if (mScore->mTopScore < mScore->mNowScore)    // ���܂ł̍ō��_�����A���̓_��������������
		{
			mScore->mTopScore = mScore->mNowScore;    // �ō��_�����X�V
		}

		mScore->mNowScore = mScore->MMaxScore;        // ���݂̓_����������
		mScore->mChangeScore = true;                  // mChangeScore��true�ɂ���
	}
}

void Score::Draw()
{
	// �X�R�A�̕`��

	// �v���C��
	if (SceneBase::mIsScene == SceneBase::Scene::ePlay)
	{
		DrawGraph((int)mScore->mPos.x, (int)mScore->mPos.y, mScore->mImage, true);  // �����̕`��

		int num = 0;
		for (int i = 1; i < mScore->Mdigit + 1; ++i)
		{
			num = mScore->mNowScore % (int)pow(NUM, i);      // i���ڂ̐������擾
			num = num / pow(NUM, i - 1);

			DrawGraph((int)mScore->mNumeraPos.x - mScore->MSizeX * i, (int)mScore->mNumeraPos.y,
				mScore->mDivisionImage[num], true);          // i���ڂ̐�����`��
		}
	}
	// ���U���g���
	else if (SceneBase::mIsScene == SceneBase::Scene::eResult)
	{
		// �X�R�A�̕`��
		DrawGraph((int)mScore->mPos.x, (int)mScore->mPos.y, mScore->mImage, true);  // �����̕`��

		int num = 0;
		for (int i = 1; i < mScore->Mdigit + 1; ++i)
		{
			num = mScore->mTopScore % (int)pow(NUM, i);      // i���ڂ̐������擾
			num = num / pow(NUM, i - 1);

			DrawGraph((int)mScore->mNumeraPos.x - mScore->MSizeX * i, (int)mScore->mNumeraPos.y,
				mScore->mDivisionImage[num], true);          // i���ڂ̐�����`��
		}
	}
}

void Score::mSubtract()
{
	int sub = 0;  // ���_��

	if (Speedometer::mMeterColor == Speedometer::MeterColor::eYellow)
	{
		sub = MSubScore;
	}
	else if (Speedometer::mMeterColor == Speedometer::MeterColor::eRed)
	{
		sub = MSubScore * 2;
	}

	mNowScore -= sub;
}
