#pragma once

// インクルード
#include "SceneBase.h"

/* リザルトシーン */
class ResultScene :public SceneBase
{
public:
	// コンストラクタ
	ResultScene();
	// デストラクタ
	~ResultScene();

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	SceneBase* Update(float _deltaTime)override;

	/// <summary>
	/// シーンの描画
	/// </summary>
	void Draw()override;
};

