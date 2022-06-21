#pragma once
// saito

#include "UIBase.h"

/* スピードメーターの処理 */
class Speedometer :public UIBase
{
public:
	// 現在メーターがいる色
	enum class MeterColor :unsigned char
	{
		eGreen,
		eYellow,
		eRed,
	};

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

	// 静的メンバ変数
	static MeterColor mMeterColor; // 現在のメーターの色
private:
	// 定数
	const float MArrowMaxPosX;      // 三角の最大ポジション
	const float MArrowMinPosX;      // 三角の最小ポジション
	const float MYellowPos;         // メーターの黄色部分ポジション(右座標)
	const float MRedPos;            // メーターの赤部分ポジション(右座標)

	const float MSpeedControlSoon;  // 三角の速度の増加を制限する
	const float MSpeedControlSlow;  // 三角の速度の減少を制限する
	const float MEndArrowSpeed;     // 着地したときの三角の移動スピード

	// 変数
	int mArrowImage;           // 三角画像
	VECTOR mArrowPos;          // 三角のポジション
	float mMoveSpeed;          // 三角の移動スピード
};

