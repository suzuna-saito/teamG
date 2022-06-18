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
	// 画像の読み込み
	LoadDivGraph("data/assets/UI/Score2.png",      // 数字
		MAllnum, MNumX, MNumY, MSizeX, MSizeY, mDivisionImage);

	// ポジションの設定
	mNumeraPos.x = 400.0f;  // 数字のポジションX
	mNumeraPos.y = 50.0f;   // 数字のポジションY

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
	// 背景の長さを元に設定
	mRemaining = mBackground->GetTotalLength();  // 残りの距離

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
			num = (int)mRemaining % (int)pow(NUM, i);      // i桁目の数字を取得
			num = num / pow(NUM, i - 1);

			DrawGraph((int)mNumeraPos.x - MSizeX * i, (int)mNumeraPos.y,
				mDivisionImage[num], true);          // i桁目の数字を描画
		}
	}
}
