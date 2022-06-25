// インクルード
#include "TitleScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
	: SceneBase(SceneBase::Scene::eTitle)
	, MMinAlpha(120)
	, MMaxAlpha(225)
	, mAlpha(MMinAlpha)
	, mChangeSpeed(1)
{
	// タイトル画像の読み込み(仮)
	mImage = LoadGraph("data/assets/TitleScene/Back.png");  // 空
	mOtherImage.emplace_back(LoadGraph("data/assets/TitleScene/TitleChar.png")); // タイトル文字
	mOtherImage.emplace_back(LoadGraph("data/assets/TitleScene/Smoke.png"));     // 煙

	// ポジションの設定
	mPos.emplace_back(VGet(0.0f, 60.0f, 0.0f));    // タイトル文字
	mPos.emplace_back(VGet(450.0f, -50.0f, 0.0f)); // 煙
}

TitleScene::~TitleScene()
{
	DeleteGraph(mImage);

	// ベクター型に保存している画像を全て消す
	for (auto image : mOtherImage)
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
	DrawGraph(0, 0, mImage, TRUE);                                    // 空
	DrawGraph(0, (int)mPos[0].y, mOtherImage[0], TRUE);               // タイトル文字

	// ブレンドモードをαブレンドにする（透明度を変える）
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,mAlpha);
	DrawGraph((int)mPos[1].x, (int)mPos[1].y, mOtherImage[1], TRUE);  // 煙
}
