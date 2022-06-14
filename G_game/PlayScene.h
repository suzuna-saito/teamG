#pragma once

// インクルード
#include "SceneBase.h"
#include "Background.h"

/* プレイシーン */
class PlayScene :public SceneBase
{
public:
	// コンストラクタ
	PlayScene();
	// デストラクタ
	~PlayScene();

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
	// 背景クラスのポインタ
	class Background* mBackground;
};

