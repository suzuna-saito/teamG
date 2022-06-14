// インクルード
#include "PlayScene.h"
#include "ResultScene.h"

PlayScene::PlayScene()
    : SceneBase()
{
    // 背景の生成
	mBackground = new Background();
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

	// 背景の更新
	mBackground->Update(_deltaTime);

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}

void PlayScene::Draw()
{
    // 背景の描画
	mBackground->Draw();
}
