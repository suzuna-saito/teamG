#pragma once
#include "SceneBase.h"
#include <vector>
#include <map>

/* ロードシーン */
class LoadScene :public SceneBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_nextScene">次のシーンのタイプ</param>
	LoadScene(Scene _nextScene);
	// デストラクタ
	~LoadScene();

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	SceneBase* Update(float _deltaTime)override;

	/// <summary>
	/// シーンの描画
	/// </summary>
	void Draw()override;

private:
	const int MSecond;      // シーン遷移するまでの時間（ミリ単位）

	Scene mNextSceneType;   // 次のシーンのタイプ
	int mStartTime;         // ロード画面が始まった時間
};

