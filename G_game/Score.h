#pragma once
// saito

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
};

