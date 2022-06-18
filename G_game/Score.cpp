#include "Score.h"

// 自身のインスタンスの初期化
Score* Score::mScore = nullptr;

Score::Score()
	: MAllnum(10)
	, MNumX(5), MNumY(2)
	, MSizeX(40), MSizeY(50)
	, Mdigit(6)
	, MMaxScore(100000)
	, MSubScore(10)
	, mDivisionImage()
	, mNowScore(MMaxScore)
	, mTopScore(0)
	, mChangeScore(false)
{
	// 画像の読み込み
	mImage = LoadGraph("data/assets/UI/Score.png");// 文字
	LoadDivGraph("data/assets/UI/Score2.png",      // 数字
		MAllnum,MNumX, MNumY, MSizeX, MSizeY, mDivisionImage);

	// ポジションの設定
	mPos.x = 350.0f;        // 文字のポジションX
	mPos.y = 10.0f;         // 文字のポジションY
	mNumeraPos.x = 630.0f;  // 数字のポジションX
	mNumeraPos.y = 50.0f;   // 数字のポジションY
}

Score::~Score()
{
	DeleteGraph(mImage);

	for (int i = 0; i < NUM; ++i)
	{
		DeleteGraph(mDivisionImage[i]);
	}
}

void Score::CreateInstance()
{
	if (mScore == nullptr)
	{
		// インスタンスを生成
		mScore = new Score();
	}
}

void Score::DeleteInstance()
{
	if (mScore != nullptr)
	{
		// 削除
		delete mScore;
	}
}

void Score::Update(float _deltaTime)
{
	// タイトル画面の時
	if (SceneBase::mIsScene == SceneBase::Scene::eTitle)
	{
	}

	// プレイ中かつ、着地していないとき
	if (SceneBase::mIsScene == SceneBase::Scene::ePlay &&
		Background::mNowSpeedType != Background::Speed::eLanding)
	{
		if (mScore->mChangeScore)
		{
			mScore->mChangeScore = false;
		}
		
		mScore->mSubtract(); // メータの位置によって減点していく
	}

	// リザルト画面かつ、最高得点の変更を行ってなかったら
	if (SceneBase::mIsScene == SceneBase::Scene::eResult && !mScore->mChangeScore)
	{
		if (mScore->mTopScore < mScore->mNowScore)    // 今までの最高点数より、今の点数が高かったら
		{
			mScore->mTopScore = mScore->mNowScore;    // 最高点数を更新
		}

		mScore->mNowScore = mScore->MMaxScore;        // 現在の点数を初期化
		mScore->mChangeScore = true;                  // mChangeScoreをtrueにする
	}
}

void Score::Draw()
{
	// スコアの描画

	// プレイ中
	if (SceneBase::mIsScene == SceneBase::Scene::ePlay)
	{
		DrawGraph((int)mScore->mPos.x, (int)mScore->mPos.y, mScore->mImage, true);  // 文字の描画

		int num = 0;
		for (int i = 1; i < mScore->Mdigit + 1; ++i)
		{
			num = mScore->mNowScore % (int)pow(NUM, i);      // i桁目の数字を取得
			num = num / pow(NUM, i - 1);

			DrawGraph((int)mScore->mNumeraPos.x - mScore->MSizeX * i, (int)mScore->mNumeraPos.y,
				mScore->mDivisionImage[num], true);          // i桁目の数字を描画
		}
	}
	// リザルト画面
	else if (SceneBase::mIsScene == SceneBase::Scene::eResult)
	{
		// スコアの描画
		DrawGraph((int)mScore->mPos.x, (int)mScore->mPos.y, mScore->mImage, true);  // 文字の描画

		int num = 0;
		for (int i = 1; i < mScore->Mdigit + 1; ++i)
		{
			num = mScore->mTopScore % (int)pow(NUM, i);      // i桁目の数字を取得
			num = num / pow(NUM, i - 1);

			DrawGraph((int)mScore->mNumeraPos.x - mScore->MSizeX * i, (int)mScore->mNumeraPos.y,
				mScore->mDivisionImage[num], true);          // i桁目の数字を描画
		}
	}
}

void Score::mSubtract()
{
	int sub = 0;  // 減点数

	if (Speedometer::mMeterColor == Speedometer::MeterColor::eYellow)
	{
		sub = MSubScore;
	}
	else if (Speedometer::mMeterColor == Speedometer::MeterColor::eRed)
	{
		sub = MSubScore * 2;
	}

	mNowScore -= sub;
}
