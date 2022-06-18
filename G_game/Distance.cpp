#include "Distance.h"

Distance::Distance(Background* _background)
	: UIBase(SceneBase::mIsScene)
	, mBackground(_background)
	, MAllnum(10)
	, MNumX(5), MNumY(2)
	, MSizeX(40), MSizeY(50)
	, Mdigit(5)
	, mDivisionImage()
	, mRemaining(0)
	, mAdjustment(10.0f)
	, mSubtraction(0.0f)
{
	// �摜�̓ǂݍ���
	LoadDivGraph("data/assets/UI/Score2.png",      // ����
		MAllnum, MNumX, MNumY, MSizeX, MSizeY, mDivisionImage);

	// �|�W�V�����̐ݒ�
	mNumeraPos.x = 400.0f;  // �����̃|�W�V����X
	mNumeraPos.y = 50.0f;   // �����̃|�W�V����Y

}

Distance::~Distance()
{
	for (int i = 0; i < NUM; ++i)
	{
		DeleteGraph(mDivisionImage[i]);
	}
}

void Distance::Update(float _deltaTime)
{
	// �w�i�̒��������ɐݒ�
	mRemaining = mBackground->GetTotalLength();  // �c��̋���

	if (mRemaining < 0)
	{
		mRemaining = 0;
	}
}

void Distance::Draw()
{
	int num = 0;
	for (int i = 1; i < Mdigit + 1; ++i)
	{
		if (i >= 3)
		{
			num = (int)mRemaining % (int)pow(NUM, i);      // i���ڂ̐������擾
			num = num / pow(NUM, i - 1);

			DrawGraph((int)mNumeraPos.x - MSizeX * i, (int)mNumeraPos.y,
				mDivisionImage[num], true);          // i���ڂ̐�����`��
		}
	}
}
