#pragma once

// インクルード
#include "DxLib.h"

const int ScreenBeside = 650;
const int ScreenVertical = 1080;
const int ColorDepth = 16;

/* シーンの基底クラス */
class SceneBase
{
public:
	// コンストラクタ
	SceneBase();
	// デストラクタ
	~SceneBase();

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	virtual SceneBase* Update(float _deltaTime) = 0;

	/// <summary>
	/// シーンの描画
	/// </summary>
	virtual void Draw() = 0;

protected:
	// シーン画像
	int mImage;
};

