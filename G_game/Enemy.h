#pragma once
//yoshihara

class Enemy
{
public:
	// コンストラクタ
	Enemy();
	// デストラクタ
	~Enemy();

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <param name="_deltaTime"></param>
	//void Update(float _deltaTime);
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// セットするポジション
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void SetPosition(int x, int y);

	/// <summary>
	/// 画像１
	/// </summary>
	/// <param name="fileName"></param>
	void Set1Image(const char* fileName);

	/// <summary>
	/// 画像２
	/// </summary>
	/// <param name="fileName"></param>
	void Set2Image(const char* fileName);

	/// <summary>
	/// 画像３
	/// </summary>
	/// <param name="fileName"></param>
	void Set3Image(const char* fileName);

	/// <summary>
	/// 画像４
	/// </summary>
	/// <param name="fileName"></param>
	void Set4Image(const char* fileName);

	/// <summary>
	/// 画像５
	/// </summary>
	/// <param name="fileName"></param>
	void Set5Image(const char* fileName);

private:
	//定数
	int cnt; //描画移動
	//変数
	float mEnemyPosiX[5];      // 敵ポジションX
	float mEnemyPosiY[5];      // 敵ポジションY


protected:
	int mEnemy1Image;       // 敵１のイメージ画像
	int mEnemy2Image;       // 敵２のイメージ画像
	int mEnemy3Image;       // 敵３のイメージ画像
	int mEnemy4Image;       // 敵４のイメージ画像
	int mEnemy5Image;       // 敵５のイメージ画像

	double startTime, endTime; //start時間とend時間
	double totalTime = 0.0, setTime = 40.0; //total時間とset時間
};
