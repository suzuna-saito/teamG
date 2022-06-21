// インクルード
#include "ResultScene.h"
#include "PlayScene.h"

PlayScene::PlayScene()
	: SceneBase()
{
	// プレイ画像の読み込み(仮)
	mImage = LoadGraph("data/assets/Play.png");

	//プレイヤーを描画
	mPlayer = new Player();
}

PlayScene::~PlayScene()
{
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	//プレイヤーを移動
	mPlayer->PlayerMove();

	// シーン遷移条件(スペースキーを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// 条件を満たしていたらリザルトシーンを生成してそのポインタを返す
		return new ResultScene();
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}

void PlayScene::Draw()
{
	// プレイの描画
	DrawGraph(0, 0, mImage, true);

	mPlayer->PlayerDraw();
	
}

