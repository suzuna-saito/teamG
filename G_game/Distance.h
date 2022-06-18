#pragma once
// saito

#include "UIBase.h"
#include "Background.h"
#include <DxLib.h>
#include <math.h>

#define NUM 10

/* 残りの長さの処理 */
class Distance :public UIBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_background">背景のポインタ</param>
	Distance(Background* _background);
	// デストラクタ
	~Distance();

	/// <summary>
	/// 距離の長さの更新処理
	/// </summary>
	/// <param name="_deltaTime"></param>
	void Update(float _deltaTime)override;

	/// <summary>
	/// 距離の長さ描画
	/// </summary>
	void Draw()override;

private:
	// 定数
	const int MAllnum;        // 画像の分割総数
	const int MNumX, MNumY;   // 画像の縦、横分割数
	const int MSizeX, MSizeY; // 分割された画像一つの大きさ
	const int Mdigit;         // 桁数

	// 変数
	int mDivisionImage[NUM];   // 数字一つ分の画像を保管する場所
	int  mRemaining;           // 残りの長さ
	float mAdjustment;         // 残りの長さの調整値
	float mSubtraction;        // 減算値
	VECTOR mNumeraPos;         // 残りの長さ 描画座標

	// 背景のポインタ
	class Background* mBackground;
};

