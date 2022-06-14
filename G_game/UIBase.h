#pragma once
// saito

#include <vector>
#include <DxLib.h>
#include "SceneBase.h"

/* UIの基底クラス */
class UIBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_nowScene">生成された時のシーン</param>
	UIBase(const SceneBase::Scene& _nowScene);
	// デストラクタ
	~UIBase();

	/// <summary>
	/// UIの更新処理
	/// </summary>
	virtual void Update(float _deltaTime) = 0;

	/// <summary>
	/// UIの描画
	/// </summary>
	virtual void Draw() = 0;

protected:
	// 変数
	VECTOR mPos;         // ポジション
	int mImage;          // UI画像
	float mEnlargement;  // 拡大率

private:
	// 各自のUIを生成したシーン
	SceneBase::Scene mDirthplaceScene;

public: // ゲッター、セッター
	// 各UIが生成された時のシーンを返す
	SceneBase::Scene GetDirthplaceScene() { return mDirthplaceScene; }
};

