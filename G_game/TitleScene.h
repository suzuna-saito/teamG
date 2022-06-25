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
	// 画像のタグ（種類）
	enum Image :unsigned char
	{
		eBack,    // 背景
		eChar,    // 文字
		eSmoke,   // 煙
		eButton,  // ボタン
		eButton2, // 上のボタンとは別のボタン
	};

	// カーソルが合わせている位置
	enum class CursorPos :unsigned char
	{
		eNone,    // どこにも合っていない
		eStart,   // スタート
		eScore,   // スコア
	};

	/// <summary>
	/// CursorPosに合わせてボタンの描画
	/// </summary>
	void DrawButton();

	// 定数
	const int MCollisionLeftX;   // ボタンの左X座標　調整値（当たり判定）
	const int MCollisionRightX;  // ボタンの右X座標　調整値（当たり判定）
	const int MCollisionLeftY;   // ボタンの左Y座標　調整値（当たり判定）
	const int MCollisionRightY;  // ボタンの右Y座標　調整値（当たり判定）
	const int MMinAlpha;   // 最小透明度
	const int MMaxAlpha;   // 最大透明度

	// 変数
	std::vector<int> mImages;  // 画像
	std::vector<VECTOR> mPos;  // 画像のポジション
	
	int mMousePosX;          // マウスのポジション
	int mMousePosY;          // マウスのポジション
	CursorPos mNowCursorPos; // 現在カーソルが合わせているポジション

	int mAlpha;              // 透明度
	int mChangeSpeed;        // 透明度の変化値
};

