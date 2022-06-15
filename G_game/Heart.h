#pragma once
// saito

#include "UIBase.h"

/* 残機の処理 */
class Heart :public UIBase
{
public:
	// コンストラクタ
	Heart();
	// デストラクタ
	~Heart();

	/// <summary>
	/// UIの更新処理
	/// </summary>
	void Update(float _deltaTime)override;

	/// <summary>
	/// UIの描画
	/// </summary>
	void Draw()override;
};