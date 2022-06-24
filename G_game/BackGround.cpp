#include "Background.h"
#include "Speedometer.h"
#include "Dxlib.h"

// メモ
// スピードがマイナスになるほど早い。(Y軸の上がマイナスなので)

// 静的メンバ変数の初期化
Background::Speed Background::mNowSpeedType = Speed::eAcceleration;
float Background::mMoveSpeed = 0;

Background::Background()
	: MHeight(-1080)
	, MAcceleration(-4.5f)
	, MDeceleration(-5.0f)
	, MMaxSpeed(-1300.0f)
	, MMinSpeed(-500.0f)
	, MScrollNum(50)
	, MAdjustmentLength(MScrollNum * 25)
	, mBackgroundPosY(0.0f)
	, mScrollCount(0)
	, mEndFlag(false)
{
	// 初速
	mMoveSpeed = -1300.0f;
	// スピードタイプの初期化
	mNowSpeedType = Speed::eAcceleration;

	// 背景画像の読み込み
	mBackgroundImage = LoadGraph("data/assets/BackgroundSky.png");     // 空
	mEndBackgroundImage = LoadGraph("data/assets/BackgroundEnd.png");  // 地面

	// 残りの長さの合計の計算
	mTotalLength = (MScrollNum + 1) * (MHeight * -1) + MAdjustmentLength;
}

Background::~Background()
{
	DeleteGraph(mBackgroundImage);
}

void Background::Update(float _deltaTime)
{
	
	if (!mEndFlag)
	{
		// ボタンが押されていた時 かつ、スクロール速度が最小速度じゃなかったら
		if (CheckHitKey(KEY_INPUT_A) && mMoveSpeed < MMinSpeed)
		{
			mMoveSpeed -= MDeceleration;             // スクロール速度を遅くする
			mNowSpeedType = Speed::eDeceleration;   // タグを減速中にする
		}
		// ボタンが押されていなかった時 かつ、スクロール速度が最大速度じゃなかったら
		else if (!CheckHitKey(KEY_INPUT_A) && mMoveSpeed > MMaxSpeed)
		{
			mMoveSpeed += MAcceleration;            // スクロール速度を早くする
			mNowSpeedType = Speed::eAcceleration;  // タグを加速中にする
		}

		// 背景ポジションの更新
		mBackgroundPosY += mMoveSpeed * _deltaTime;
	}

	// @@@test
	mTotalLength += mMoveSpeed * _deltaTime;

	// 背景の描画繰り返し処理
	// スクロールを繰り返した回数が指定の回数まで行ってなかったら
	if (mScrollCount != MScrollNum)
	{
		if (mBackgroundPosY <= MHeight)     // 一枚目の画像が画面外に行った時に初期値に戻す
		{
			mBackgroundPosY = 0.0f;
			++mScrollCount;
		}
	}
	// 指定回数スクロールを繰り返して、最後の背景が描画されたら
	else if (mBackgroundPosY <= MHeight && !mEndFlag)
	{
		mMoveSpeed = 0.0f;
		mEndFlag = true;                   // mEndFlagをtrueにする
		mNowSpeedType = Speed::eLanding;   // タグを着地にする
	}
}

void Background::Draw()
{
	// 背景の描画
	DrawGraph(0, (int)mBackgroundPosY, mBackgroundImage, TRUE);

	// スクロールを繰り返した回数が指定の回数まで行ってなかったら
	if (mScrollCount != MScrollNum)
	{
		DrawGraph(0, (int)mBackgroundPosY - MHeight, mBackgroundImage, TRUE);   // 空の画像を描画
	}
	// スクロールを繰り返した回数が指定の回数まで行ったら
	else
	{
		DrawGraph(0, (int)mBackgroundPosY - MHeight, mEndBackgroundImage, TRUE); // 地面の画像を描画
	}
}

