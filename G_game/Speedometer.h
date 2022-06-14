#pragma once
// saito

#include "UIBase.h"

/* スピードメーターの処理 */
class Speedometer :public UIBase
{
public:
	// コンストラクタ
	Speedometer();
	// デストラクタ
	~Speedometer();

	/// <summary>
	/// UIの更新処理
	/// </summary>
	void Update(float _deltaTime)override;

	/// <summary>
	/// UIの描画
	/// </summary>
	void Draw()override;

private:
	// 定数
	const float MArrowMaxPosX;      // 三角の最大ポジション
	const float MArrowMinPosX;      // 三角の最小ポジション
	const float MSpeedControlSoon;  // 速度の増加を制限する
	const float MSpeedControlSlow;  // 速度の減少を制限する

	// 変数
	int mArrowImage;           // 三角画像
	VECTOR mArrowPos;          // 三角のポジション
	float mMoveSpeed;          // 三角の移動スピード
};

