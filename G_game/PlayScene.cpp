// インクルード
#include "PlayScene.h"
#include "ResultScene.h"
#include "Enemy.h"
#include <time.h>

PlayScene::PlayScene()
    : SceneBase(),Enemy()
{
    // プレイ画像の読み込み(仮)
    mImage = LoadGraph("data/assets/Play.png");

	//敵の読み込み
	mEnemy1Image;
	mEnemy2Image;
	mEnemy3Image;
	mEnemy4Image;
	mEnemy5Image;

	startTime = clock() / CLOCKS_PER_SEC;
}

PlayScene::~PlayScene()
{
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	// シーン遷移条件(スペースキーを押すと遷移（仮）)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// 条件を満たしていたらリザルトシーンを生成してそのポインタを返す
		return new ResultScene();
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	while (1) { //１分間ループする

		Enemy::Update();
		if (totalTime > setTime) //ループし終わったら
			break;
		endTime = clock() / CLOCKS_PER_SEC;
		totalTime = endTime - startTime;
	}

	//return this;
	return new ResultScene();
}

void PlayScene::Draw()
{
    // プレイの描画
    DrawGraph(0, 0, mImage, true);

	//敵の描画
	//Enemy::Draw();
}
