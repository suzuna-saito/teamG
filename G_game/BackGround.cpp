#include "Background.h"
#include "Dxlib.h"

Background::Background()
	: MHeight(-1920.0f)
	, mBackgroundPosY(0.0f)
	, mMoveSpeed(-500.0f)
{
	// 背景画像の読み込み
	mBackgroundImage = LoadGraph("data/assets/Background.png");
}

Background::~Background()
{
}

void Background::Update(float _deltaTime)
{
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
