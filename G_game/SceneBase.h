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
	// シーンのタグ（種類）
	enum class Scene :unsigned char
	{
		eInit,    // 初期状態
		eTitle,   // タイトル
		ePlay,    // プレイ
		eResult,  // リザルト
	};

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_nowScene">現在のシーン</param>
	SceneBase(Scene _nowScene);
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

	// 現在のシーンタグ
	static Scene mIsScene;

protected:
	// シーン画像
	int mImage;
};

