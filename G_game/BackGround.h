#pragma once
// saito

/* 背景制御 */
class Background
{
public:

	// スピードのタグ
	enum class Speed :unsigned char
	{
		eAcceleration,  // 加速中
		eDeceleration,  // 減速中
	};

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

	// 静的メンバ変数
	static Speed mNowSpeed;      // 現在のスピード状況
	static float mMoveSpeed;     // 背景の移動スピード

private:
	// 定数
	const float MHeight;         // 画面サイズ(縦)
	const float MAcceleration;   // 背景の加速スピード
	const float MDeceleration;   // 背景の減速スピード
	const float MMaxSpeed;       // 最大スピード
	const float MMinSpeed;       // 最小スピード

	// 変数
	int mBackgroundImage;       // 背景のイメージ画像
	float mBackgroundPosY;      // 背景ポジションY
};

