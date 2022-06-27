#pragma once
#include "SceneBase.h"
#include <vector>
#include <map>

/* ロードシーン */
class LoadScene :public SceneBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_nextScene">次に生成したいシーンのタイプ</param>
	LoadScene(Scene _nextScene);
	// デストラクタ
	~LoadScene();

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
	enum loadImage :unsigned char
	{
		eChar,    // 文字
		eKoyake,  // キャラクター（こやけ！）
	};

	const int MSecond;        // シーン遷移するまでの時間（ミリ単位）
	const int MHalfSecond;    // 0.5秒（ミリ秒単位）

	const int MDrawHeight;    // 文字画像の描画する縦幅
	const int MInitWidthSize; // 文字画像の描画する横幅の初期値
	const int MDrawExpansion; // 文字画像の描画するサイズの拡大値
	const int MMaxWidthSize;  // 文字画像の描画するサイズの最大値

	const int MRightPosX;        // キャラクターの右下座標X
	const int MRightPosY;        // キャラクターの右下座標Y
	const int MMaxKoyakeSizeY;   // キャラクター画像の最大サイズY
	const int MMinKoyakeSizeY;   // キャラクター画像の最小サイズY

	Scene mNextSceneType;   // 次のシーンのタイプ
	int mStartTime;         // ロード画面が始まった時間
	int mWeitTime;          // まつ時間

	std::vector<int> mImages;  // 画像
	std::vector<VECTOR> mPos;  // 画像のポジション
	int mDrawWidth;            // 文字画像の描画する横幅
	int mSize;                 // キャラクター画像の描画サイズ
	int mChangeSize;           // キャラクター画像の描画サイズ変更値
};

