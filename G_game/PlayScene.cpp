// インクルード
#include "PlayScene.h"
#include "ResultScene.h"

PlayScene::PlayScene()
    : SceneBase(SceneBase::Scene::ePlay)
{
	// 生成
	mBackground = new Background();         // 背景
	mSpeedmeter = new Speedometer();        // スピードメーター
	new Distance(mBackground);              // 残りの長さ
	new Heart();                            // 残機
}

PlayScene::~PlayScene()
{
	delete mBackground;  // 背景の削除
	delete mSpeedmeter;  // スピードメーターの削除
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	// 地面まで着地して、メーターが左まで来たら
	if (mSpeedmeter->GetmArrowStopFlag())
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
