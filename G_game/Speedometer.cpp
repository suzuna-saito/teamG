#include "Speedometer.h"
#include "BackGround.h"

// 静的メンバ変数の初期化
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
	// 画像の読み込み
	mImage = LoadGraph("data/assets/UI/Meter.png");       // メーター
	mArrowImage = LoadGraph("data/assets/UI/Arrow.png");  // 三角画像

	// ポジションの設定
	mPos.x = 75.0f;                // メータのポジションｘ
	mPos.y = 950.0f;               // メータのポジションｙ
	mArrowPos.x = MArrowMaxPosX;   // 三角のポジションｘ

	mArrowPos.y = 900.0f;          // 三角のポジションy
}

Speedometer::~Speedometer()
{
	DeleteGraph(mImage);
	DeleteGraph(mArrowImage);
}

void Speedometer::Update(float _deltaTime)
{
	// 背景のスクロールスピードを利用して移動速度の処理
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

	// 三角のポジション更新
	mArrowPos.x += mMoveSpeed * _deltaTime;

	// 現在の三角のポジションによってタイプを変更する
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

	// 移動制限
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
	// 描画
	DrawGraph((int)mPos.x, (int)mPos.y, mImage, TRUE);                 // メーター
	DrawGraph((int)mArrowPos.x, (int)mArrowPos.y, mArrowImage, TRUE);  // 三角
}
