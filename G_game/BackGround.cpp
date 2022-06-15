#include "Background.h"
#include "Speedometer.h"
#include "Dxlib.h"


// メモ
// スピードがマイナスになるほど早い。(Y軸の上がマイナスなので)

// 静的メンバ変数の初期化
Background::Speed Background::mNowSpeed = Speed::eAcceleration;
float Background::mMoveSpeed = -100.0f;

Background::Background()
	: MHeight(-1920.0f)
	, MAcceleration(-6.0f)
	, MDeceleration(-7.0f)
	, MMaxSpeed(-1300.0f)
	, MMinSpeed(-300.0f)
	, mBackgroundPosY(0.0f)
{
	// 背景画像の読み込み
	mBackgroundImage = LoadGraph("data/assets/Background.png");
}

Background::~Background()
{
}

void Background::Update(float _deltaTime)
{
	// ボタンが押されていた時 かつ、スクロール速度が最小速度じゃなかったら
	if (CheckHitKey(KEY_INPUT_A) && mMoveSpeed < MMinSpeed)
	{
		mMoveSpeed -= MDeceleration;        // スクロール速度を遅くする
		mNowSpeed = Speed::eDeceleration;   // タグを減速中にする
	}
	// ボタンが押されていなかった時 かつ、スクロール速度が最大速度じゃなかったら
	else if(!CheckHitKey(KEY_INPUT_A) && mMoveSpeed > MMaxSpeed)
	{
		mMoveSpeed += MAcceleration;       // スクロール速度を早くする
		mNowSpeed = Speed::eAcceleration;  // タグを加速中にす
	}

	// 背景ポジションの更新
	mBackgroundPosY += mMoveSpeed * _deltaTime;
}

void Background::Draw()
{
	// 背景の描画
	DrawGraph(0, (int)mBackgroundPosY, mBackgroundImage, true);
	DrawGraph(0, (int)mBackgroundPosY - MHeight, mBackgroundImage, true);

	// 一枚目の画像が画面外に行ったら初期値に戻す
	if (mBackgroundPosY <= MHeight)
	{
		mBackgroundPosY = 0.0f;
	}
}
