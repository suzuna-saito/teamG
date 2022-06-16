#include "Score.h"

// 自身のインスタンスの初期化
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
	// 画像の読み込み
	//LoadGraph("data/assets/UI/Score.png");      // 文字
	LoadDivGraph("data/assets/UI/Score2.png",      // 数字
		MAllnum,MNumX, MNumY, MSizeX, MSizeY, mDivisionImage);

	// ポジションの設定
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
		// インスタンスを生成
		mScore = new Score();
	}
}

void Score::DeleteInstance()
{
	if (mScore != nullptr)
	{
		// 削除
		delete mScore;
	}
}

void Score::Update(float _deltaTime)
{
	int sub = 0;  // 減点数

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
	// スコアの描画
	int num = 0;
	for (int i = 1; i < mScore->Mdigit+1; ++i)
	{
		num = mScore->mNowScore % (int)pow(NUM, i);      // i桁目の数字を取得
		num = num / pow(NUM, i-1);

		DrawGraph((int)mScore->mNumeraPos.x - mScore->MSizeX * i, (int)mScore->mNumeraPos.y,
			mScore->mDivisionImage[num], true);          // i桁目の数字を描画
	}

}
