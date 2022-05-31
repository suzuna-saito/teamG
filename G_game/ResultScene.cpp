// インクルード
#include "ResultScene.h"
#include "TitleScene.h"
#include "PlayScene.h"

ResultScene::ResultScene()
	: SceneBase()
{
	// リザルト画像の読み込み(仮)
	mImage = LoadGraph("data/assets/Result.png");
}

ResultScene::~ResultScene()
{
}

SceneBase* ResultScene::Update(float _deltaTime)
{
	// シーン遷移条件(Aを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_A))
	{
		// 条件を満たしていたらタイトルシーンを生成してそのポインタを返す
		return new TitleScene();
	}
	// シーン遷移条件(Sを押すと遷移（仮）)
	else if (CheckHitKey(KEY_INPUT_S))
	{
		// 条件を満たしていたらプレイシーンを生成してそのポインタを返す
		return new PlayScene();
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}

void ResultScene::Draw()
{
	// リザルトの描画
	DrawGraph(0, 0, mImage, true);
}
