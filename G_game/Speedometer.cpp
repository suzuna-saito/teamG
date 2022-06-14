#include "Speedometer.h"
#include "BackGround.h"

Speedometer::Speedometer()
	: UIBase(SceneBase::mIsScene)
	, MArrowMinPosX(60.0f)
	, MArrowMaxPosX(540.0f)
	, MSpeedControlSoon(0.15f)
	, MSpeedControlSlow(0.186f)
	, mMoveSpeed(0.0f)
{
	// 画像の読み込み
	mImage = LoadGraph("data/assets/Meter.png");       // メーター
	mArrowImage = LoadGraph("data/assets/Arrow.png");  // 三角画像

	// ポジションの設定
	mPos.x = 75.0f;                // メータのポジションｘ
	mPos.y = 900.0f;               // メータのポジションｙ
	mArrowPos.x = MArrowMinPosX;   // 三角のポジションｘ
	mArrowPos.y = 850.0f;          // 三角のポジションy
}

Speedometer::~Speedometer()
{
}

void Speedometer::Update(float _deltaTime)
{
	// 背景のスクロールスピードを利用して移動速度の制限
	if (Background::mNowSpeed == Background::Speed::eAcceleration)
	{
		mMoveSpeed = Background::mMoveSpeed * -MSpeedControlSoon;
	}
	else if (Background::mNowSpeed == Background::Speed::eDeceleration)
	{
		mMoveSpeed = Background::mMoveSpeed * MSpeedControlSlow;
	}

	// 三角のポジション更新
	mArrowPos.x += mMoveSpeed * _deltaTime;

	// 制限処理
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
	DrawGraph((int)mPos.x, (int)mPos.y, mImage, true);                 // メーター
	DrawGraph((int)mArrowPos.x, (int)mArrowPos.y, mArrowImage, true);  // 三角
}
