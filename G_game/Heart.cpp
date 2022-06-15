#include "Heart.h"

Heart::Heart()
	: UIBase(SceneBase::mIsScene)
{
	// 画像の読み込み
	mImage = LoadGraph("data/assets/UI/Heart.png");       // ハート

	// ポジションの設定
	mPos.x = 10.0f;
	mPos.y = 10.0f;
}

Heart::~Heart()
{
}

void Heart::Update(float _deltaTime)
{
}

void Heart::Draw()
{
	// 描画
	DrawGraph((int)mPos.x, (int)mPos.y, mImage, true);    // ハート
}
