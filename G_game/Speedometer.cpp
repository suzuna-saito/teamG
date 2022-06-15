#include "Speedometer.h"
#include "BackGround.h"

// 静的メンバ変数の初期化
bool Speedometer::mArrowStopFlag = false;

Speedometer::Speedometer()
	: UIBase(SceneBase::mIsScene)
	, MArrowMinPosX(60.0f)
	, MArrowMaxPosX(540.0f)
	, MSpeedControlSoon(0.2f)
	, MSpeedControlSlow(0.2f)
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

	// フラグの初期化
	mArrowStopFlag = false;
}

Speedometer::~Speedometer()
{
	DeleteGraph(mImage);
	DeleteGraph(mArrowImage);
}

void Speedometer::Update(float _deltaTime)
{
	// 背景のスクロールスピードを利用して移動速度の制限
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
		mMoveSpeed = -MEndArrowSpeed;
	}

	// 三角のポジション更新
	mArrowPos.x += mMoveSpeed * _deltaTime;

	// 制限処理
	if (mArrowPos.x < MArrowMinPosX)
	{
		mMoveSpeed = 0.0f;
		mArrowPos.x = MArrowMinPosX;

		if (Background::mNowSpeedType == Background::Speed::eLanding)  // 一番左まで三角が行ったとき
		{                                                              // 着地してたら
			mArrowStopFlag = true;
		}
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
