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
	/// 残機の更新処理
	/// </summary>
	void Update(float _deltaTime)override;

	/// <summary>
	/// 残機の描画
	/// </summary>
	void Draw()override;

private:
	// 定数
	const float MMaxHpSize;   // HP画像の最大の大きさ
	const float MMinHpSize;   // HP画像の最小の大きさ
	const float MIncrease;    // 拡大率の増加数
	// 変数
	int mHP;        // HP

	int test;       // デバッグ用

public:
	int GetHP() { return mHP; }
};