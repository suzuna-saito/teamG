// インクルード
#include "LoadScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "PlayScene.h"

LoadScene::LoadScene(Scene _nextScene)
	: SceneBase(SceneBase::Scene::eLoad)
	, MSecond(3000)
	, mStartTime(GetNowCount())
{
	// ロード画像の読み込み(仮)
	mImage = LoadGraph("data/assets/ResultScene/Result.png");

	// 次のシーンのタイプ
	mNextSceneType = _nextScene;
}

LoadScene::~LoadScene()
{
	DeleteGraph(mImage);
}

SceneBase* LoadScene::Update(float _deltaTime)
{
	// ロード画面に入って指定の秒数たったら
	if (GetNowCount() - mStartTime >= MSecond)
	{
		// mNextSceneTypeによって、次のシーンを生成
		if (mNextSceneType == Scene::eTitle)
		{
			return new TitleScene();
		}
		else if (mNextSceneType == Scene::ePlay)
		{
			return new PlayScene();
		}
		else if (mNextSceneType == Scene::eResult)
		{
			return new ResultScene();
		}
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}

void LoadScene::Draw()
{
	// ロードの描画
	DrawGraph(0, 0, mImage, TRUE);
}
