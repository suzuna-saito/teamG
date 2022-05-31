// インクルード
#include "TitleScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
	: SceneBase()
{
	// タイトル画像の読み込み(仮)
	mImage = LoadGraph("data/assets/Title.png");
}

TitleScene::~TitleScene()
{
}

SceneBase* TitleScene::Update(float _deltaTime)
{
	// シーン遷移条件(エンターを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		// 条件を満たしていたらプレイシーンを生成してそのポインタを返す
		return new PlayScene();
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}

void TitleScene::Draw()
{
	// タイトルの描画
	DrawGraph(0, 0, mImage, true);
}
