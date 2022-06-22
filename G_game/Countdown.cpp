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
	// 画像の読み込み
	LoadDivGraph("data/assets/UI/Score2.png",      // 数字
		MAllnum, MNumX, MNumY, MSizeX, MSizeY, mDivisionImage);

	// ポジションの設定
	mPos.x = 350.0f;        // 文字のポジションX
	mPos.y = 10.0f;         // 文字のポジションY
	mNumeraPos.x = 630.0f;  // 数字のポジションX
	mNumeraPos.y = 50.0f;   // 数字のポジションY
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
	// 着地していないとき、かつ、計測開始から1秒が過ぎたとき
	if (Background::mNowSpeedType != Background::Speed::eLanding &&
		GetNowCount()- mStartTime >= MOneSecond)
	{
		// メータの位置によって減算していく
		mSubTime = 1;  // 減算値

		if (Speedometer::mMeterColor == Speedometer::MeterColor::eYellow)
		{
			mSubTime = mSubTime * 2;
		}
		else if (Speedometer::mMeterColor == Speedometer::MeterColor::eRed)
		{
			mSubTime = mSubTime * 3;
		}

		mNowTime -= mSubTime;        // 現在のタイムを減らす

		mStartTime = GetNowCount();  // 計測開始時間の更新
	}
}

void Countdown::Draw()
{
	// タイムの描画
	int num = 0;
	for (int i = 1; i < Mdigit + 1; ++i)
	{
		num = mNowTime % (int)pow(NUM, i);       // i桁目の数字を取得
		num = num / pow(NUM, i - 1);

		DrawGraph((int)mNumeraPos.x - MSizeX * i, (int)mNumeraPos.y,
			mDivisionImage[num], true);          // i桁目の数字を描画
	}
}
