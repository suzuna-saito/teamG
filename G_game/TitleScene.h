#pragma once

// インクルード
#include "SceneBase.h"

/* タイトルシーン */
class TitleScene :public SceneBase
{
public:
	// コンストラクタ
	TitleScene();
	// デストラクタ
	~TitleScene();

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

