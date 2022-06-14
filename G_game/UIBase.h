#pragma once
// saito

#include <vector>
#include "SceneBase.h"

/* UIの基底クラス */
class UIBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_UI">UIBaseのポインタ</param>
	UIBase(UIBase* _ui);
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

private:
	// 各自のUIを生成したシーン
	SceneBase::Scene mDirthplaceScene;
};

