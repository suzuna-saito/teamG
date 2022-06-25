// インクルード
#include "TitleScene.h"
#include "LoadScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
	: SceneBase(SceneBase::Scene::eTitle)
	, MCollisionLeftX(50)
	, MCollisionRightX(600)
	, MCollisionLeftY(60)
	, MCollisionRightY(190)
	, MMinAlpha(100)
	, MMaxAlpha(225)
	, mMousePosX(0)
	, mMousePosY(0)
	, mNowCursorPos(CursorPos::eNone)
	, mAlpha(MMinAlpha)
	, mChangeSpeed(2)
{
	// タイトル画像の読み込み(仮)
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Back.png"));      // 背景
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Char.png"));      // 文字
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Smoke.png"));     // 煙
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Button.png"));    // 普通のボタン
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Button2.png"));   // カーソルがあってる時のボタン

	// ポジションの設定
	mPos.emplace_back(VGet(0.0f, 0.0f, 0.0f));     // 背景
	mPos.emplace_back(VGet(0.0f, 0.0f, 0.0f));     // 文字
	mPos.emplace_back(VGet(450.0f, -50.0f, 0.0f)); // 煙
	mPos.emplace_back(VGet(0.0f, 580.0f, 0.0f));   // startボタン
	mPos.emplace_back(VGet(0.0f, 810.0f, 0.0f));   // scoreボタン
}

TitleScene::~TitleScene()
{
	// ベクター型に保存している画像を全て消す
	for (auto image : mImages)
	{
		DeleteGraph(image);
	}
}

SceneBase* TitleScene::Update(float _deltaTime)
{
	// マウスカーソルがstartにあってるかつ、クリックボタンが押されたら
	if (mNowCursorPos == CursorPos::eStart && 
		(GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		// ブレンドモードをノーブレンドに戻す
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// 条件を満たしていたらプレイシーンを生成してそのポインタを返す
		return new LoadScene(Scene::ePlay);
	}

	// マウスカーソルがボタンにあっているか
	GetMousePoint(&mMousePosX, &mMousePosY);  // マウスの位置を取得
	// Startボタンの枠内にマウスカーソルがあれば
	if (mMousePosX > mPos[eButton].x + MCollisionLeftX && mMousePosX < mPos[eButton].x + MCollisionRightX &&
		mMousePosY > mPos[eButton].y + MCollisionLeftY && mMousePosY < mPos[eButton].y + MCollisionRightY)
	{
		mNowCursorPos = CursorPos::eStart;    // タイプをeStartに変更
	}
	// Scoreボタンの枠内にマウスカーソルがあれば
	else if (mMousePosX > mPos[eButton2].x + MCollisionLeftX && mMousePosX < mPos[eButton2].x + MCollisionRightX &&
		mMousePosY > mPos[eButton2].y + MCollisionLeftY && mMousePosY < mPos[eButton2].y + MCollisionRightY)
	{
		mNowCursorPos = CursorPos::eScore;    // タイプをeScoreに変更 
	}
	else
	{
		mNowCursorPos = CursorPos::eNone;
	}


	// 煙の透明度を変える
	if (mAlpha > MMaxAlpha ||    // 今の透明度が最大より上になったら または
		mAlpha < MMinAlpha)      // 今の透明度が最小未満になったら
	{
		mChangeSpeed *= -1;      // 透明度の変化値の符号を変える
	}

	// 透明度を変える
	mAlpha += mChangeSpeed;


	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}

void TitleScene::Draw()
{
	// タイトルの描画
	// ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph((int)mPos[Image::eBack].x, (int)mPos[Image::eBack].y, mImages[Image::eBack], TRUE);         // 背景

	DrawButton();                                                                                         // ボタン

	DrawGraph((int)mPos[Image::eChar].x, (int)mPos[Image::eChar].y, mImages[Image::eChar], TRUE);         // 文字

	// ブレンドモードをαブレンドにする（透明度を変える）
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,mAlpha);
	DrawGraph((int)mPos[Image::eSmoke].x, (int)mPos[Image::eSmoke].y, mImages[Image::eSmoke], TRUE);      // 煙
}

void TitleScene::DrawButton()
{
	// マウスカーソルがStartにあっていたら
	if (mNowCursorPos == CursorPos::eStart)
	{
		DrawGraph((int)mPos[Image::eButton].x, (int)mPos[Image::eButton].y, mImages[Image::eButton2], TRUE);   // startボタン(明るく描画)
		DrawGraph((int)mPos[Image::eButton2].x, (int)mPos[Image::eButton2].y, mImages[Image::eButton], TRUE);  // scoreボタン
	}
	// マウスカーソルがScoreにあっていたら
	else if (mNowCursorPos == CursorPos::eScore)
	{
		DrawGraph((int)mPos[Image::eButton].x, (int)mPos[Image::eButton].y, mImages[Image::eButton], TRUE);   // startボタン
		DrawGraph((int)mPos[Image::eButton2].x, (int)mPos[Image::eButton2].y, mImages[Image::eButton2], TRUE);  // scoreボタン(明るく描画)
	}
	else
	{
		DrawGraph((int)mPos[Image::eButton].x, (int)mPos[Image::eButton].y, mImages[Image::eButton], TRUE);    // startボタン
		DrawGraph((int)mPos[Image::eButton2].x, (int)mPos[Image::eButton2].y, mImages[Image::eButton], TRUE);  // scoreボタン
	}
}
