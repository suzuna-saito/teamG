#pragma once
// saito

#include "DxLib.h"
#include <math.h>
#include "BackGround.h"
#include "Speedometer.h"

#define NUM 10  // 数字の種類の数（0～9）

/* カウントダウンの処理 */
class Countdown :public UIBase
{
public:
	// コンストラクタ
	Countdown();
	// デストラクタ
	~Countdown();

	/// <summary>
	/// カウントダウンの更新処理
	/// </summary>
	void Update(float _deltaTime)override;

	/// <summary>
	/// カウントダウンの描画
	/// </summary>
	void Draw()override;

private:
	// 定数
	const int MAllnum;        // 画像の分割総数
	const int MNumX, MNumY;   // 画像の縦、横分割数
	const int MSizeX, MSizeY; // 分割された画像一つの大きさ
	const int Mdigit;         // 桁数
	const int MOneSecond;     // 一秒ミリ単位

	// 変数
	int mDivisionImage[NUM]; // 数字一つ分の画像を保管する場所
	VECTOR mNumeraPos;       // 数字 描画座標

	int mStartTime;         // 一秒の計測を始める時間
	int mNowTime;           // 現在のタイム
	int mSubTime;           // 秒数の減算値

};
