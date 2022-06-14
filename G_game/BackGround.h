#pragma once

/* 背景制御 */
class Background
{
public:
	// コンストラクタ
	Background();
	// デストラクタ
	~Background();

	/// <summary>
	/// 背景の更新処理
	/// </summary>
	/// <param name="_deltaTime"></param>
	void Update(float _deltaTime);

	/// <summary>
	/// 背景の描画
	/// </summary>
	void Draw();

private:
	// 定数
	const float mWidth;         // 初期値に戻すタイミング（画面サイズ）

	// 変数
	int mBackgroundImage;       // 背景のイメージ画像
	float mBackgroundPosY;      // 背景ポジションY
	float mMoveSpeed;           // 背景の移動スピード
};

