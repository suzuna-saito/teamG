// インクルード
#include "PlayScene.h"
#include "ResultScene.h"

PlayScene::PlayScene()
    : SceneBase(SceneBase::Scene::ePlay)
{
	// 生成
	mBackground = new Background();         // 背景
	mEnemy = new Enemy();                   // エネミー
	mPlayer = new Player();                 // プレイヤー
	mHeart = new Heart();                   // 残機
	new Countdown();                        // カウントダウン
	new Speedometer();                      // スピードメーター
	new Distance(mBackground);              // 残りの長さ
}

PlayScene::~PlayScene()
{
	delete mBackground;  // 背景の削除
	delete mEnemy;       // エネミーの削除
	delete mPlayer;      // プレイヤーの削除
	delete mHeart;       // 残機の削除
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	// 地面まで着地して、メーターが左まで来たら
	if (mHeart->GetHP() == 0)
	{
		// 条件を満たしていたらリザルトシーンを生成してそのポインタを返す
		return new ResultScene();
	}

	// 背景の更新
	mBackground->Update(_deltaTime);
	// エネミーの更新
	mEnemy->Update();
	// プレイヤーの更新
	mPlayer->BesidePlayerMove();
	mPlayer->PlayerSpeed();
	mPlayer->PlayerLanding();

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}

void PlayScene::Draw()
{
    // 背景の描画
	mBackground->Draw();
	// エネミーの描画
	mEnemy->Draw();
	// プレイヤーの描画
	mPlayer->PlayerDraw();
}
