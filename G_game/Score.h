#pragma once
// saito

#include "DxLib.h"
#include <math.h>
#include "BackGround.h"
#include "Speedometer.h"

#define NUM 10  // 数字の種類の数（0～9）または 割る数

/* スコアの処理 */
class Score
{
public:
	// コンストラクタ
	Score();
	// デストラクタ
	~Score();

	// インスタンスを生成する
	static void CreateInstance();
	// インスタンスを削除する
	static void DeleteInstance();

	/// <summary>
	/// スコアの更新処理
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	static void Update(float _deltaTime);

	/// <summary>
	/// スコアの描画
	/// </summary>
	static void Draw();
private:
	// Scoreの実体（アプリ内に唯一存在）
	static Score* mScore;

	// 定数
	const int MAllnum;        // 画像の分割総数
	const int MNumX, MNumY;   // 画像の縦、横分割数
	const int MSizeX, MSizeY; // 分割された画像一つの大きさ
	const int Mdigit;         // 桁数
	const int MMaxScore;      // スコアの最高得点
	const int MSubScore;      // スコアの減点数

	// 変数
	int mImage;              // スコア文字画像
	int mDivisionImage[NUM]; // 数字一つ分の画像を保管する場所
	VECTOR mPos;        // スコア文字描画座標
	VECTOR mNumeraPos;  // 数字 描画座標

	int mNowScore;      // 現在のスコア
	int mTopScore;      // 今までのスコアで一番いい点数
	bool mChangeScore;  // 最高スコアの変更を行ったかどうか

	// 関数
	void mSubtract();   // スコアの点を引く
};

