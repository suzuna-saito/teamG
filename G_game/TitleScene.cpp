// インクルード
#include "TitleScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
	: SceneBase(SceneBase::Scene::eTitle)
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
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Button.png"));    // ボタン
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Button2.png"));   // カーソルがあってる時のボタン

	// ポジションの設定
	mPos.emplace_back(VGet(0.0f, 0.0f, 0.0f));     // 背景
	mPos.emplace_back(VGet(0.0f, 0.0f, 0.0f));     // 文字
	mPos.emplace_back(VGet(450.0f, -50.0f, 0.0f)); // 煙
	mPos.emplace_back(VGet(0.0f, 580.0f, 0.0f));   // ボタン
	mPos.emplace_back(VGet(0.0f, 810.0f, 0.0f));   // ボタン2
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
	// シーン遷移条件(エンターを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		// ブレンドモードをノーブレンドに戻して次のシーンに行く
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// 条件を満たしていたらプレイシーンを生成してそのポインタを返す
		return new PlayScene();
	}

	// マウスカーソルがボタンにあっているか
	GetMousePoint(&mMousePosX, &mMousePosY);  // マウスの位置を取得
	if (mMousePosX > mPos[eButton].x + 50 && mMousePosX < mPos[eButton].x + 600 &&
		mMousePosY > mPos[eButton].y + 60 && mMousePosY < mPos[eButton].y + 190)
	{
		mNowCursorPos = CursorPos::eStart;
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

	if (mNowCursorPos == CursorPos::eStart)
	{
		DrawGraph((int)mPos[Image::eButton].x, (int)mPos[Image::eButton].y, mImages[Image::eButton2], TRUE);   // ボタン
	}
	else
	{
		DrawGraph((int)mPos[Image::eButton].x, (int)mPos[Image::eButton].y, mImages[Image::eButton], TRUE);   // ボタン
	}

	//DrawGraph((int)mPos[Image::eButton2].x, (int)mPos[Image::eButton2].y, mImages[Image::eButton], TRUE); // ボタン2

	DrawGraph((int)mPos[Image::eChar].x, (int)mPos[Image::eChar].y, mImages[Image::eChar], TRUE);         // 文字

	// ブレンドモードをαブレンドにする（透明度を変える）
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,mAlpha);
	DrawGraph((int)mPos[Image::eSmoke].x, (int)mPos[Image::eSmoke].y, mImages[Image::eSmoke], TRUE);  // 煙



	////////////// デバッグ
	unsigned int Cr;

	Cr = GetColor(0, 0, 0);    // 白色の値を取得

	DrawLine(mPos[eButton].x+50, 640, mPos[eButton].x + 600, 770, Cr);    // 線を描画
}
