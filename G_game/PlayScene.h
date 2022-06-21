#pragma once

// インクルード
#include "SceneBase.h"
#include "Background.h"
#include "Enemy.h"
#include "Distance.h"
#include "Speedometer.h"
#include "Heart.h"

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
	// クラスのポインタ変数
	class Background* mBackground;   // 背景クラス
	class Enemy* mEnemy;             // エネミークラス
	class Heart* mHeart;             // 残機クラス
};

