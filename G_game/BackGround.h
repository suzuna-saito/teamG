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
		eLanding,       // 着地
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
	static Speed mNowSpeedType;  // 現在のスピード状況
	static float mMoveSpeed;     // 背景の移動スピード

private:
	// 定数
	const int MAdjustmentLength; // 長さの微調整値
	const int MHeight;           // 画面サイズ(縦)
	const float MAcceleration;   // 背景の加速スピード
	const float MDeceleration;   // 背景の減速スピード
	const float MMaxSpeed;       // 最大スピード
	const float MMinSpeed;       // 最小スピード

	const int MScrollNum;       // スクロールを止めるタイミング回数

	// 変数
	int mTotalLength;           // 合計の長さ
	int mBackgroundImage;       // 背景のイメージ画像
	int mEndBackgroundImage;    // 一番下の背景のイメージ画像
	float mBackgroundPosY;      // 背景ポジションY

	int mScrollCount;           // スクロールを繰り返した回数カウント
	bool mEndFlag;              // 着地地点まで背景を描画したかどうか

public:  // ゲッター、セッター
	// 合計の長さを取得
	int GetTotalLength() { return mTotalLength; }
};

