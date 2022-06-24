#pragma once

// インクルード
#include "SceneBase.h"
#include <vector>

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

private:
	// 定数
	const int MMinAlpha;   // 最小透明度
	const int MMaxAlpha;   // 最大透明度

	// 変数
	std::vector<int> mOtherImage;  // 画像
	std::vector<VECTOR> mPos;      // 画像のポジション

	int mAlpha;      // 透明度
	int mChangeSpeed;// 透明度の変化値
};

