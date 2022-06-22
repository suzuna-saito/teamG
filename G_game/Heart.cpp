#include "Heart.h"

Heart::Heart()
	: UIBase(SceneBase::mIsScene)
	, MMaxHpSize(55.0f)
	, MMinHpSize(50.0f)
	, MIncrease(0.2f)
	, mHP(3)
{
	// 画像の読み込み
	mImage = LoadGraph("data/assets/UI/Heart.png");       // ハート

	// ポジションの設定
	mPos.x = 20.0f;
	mPos.y = 20.0f;

	// UIのサイズ
	mUISizeX = 50.0f;
	mUISizeY = 50.0f;

	// 拡大率
	mEnlargement = 0.15f;

	// デバック用
	test = 0;
}

Heart::~Heart()
{
	DeleteGraph(mImage);
}

void Heart::Update(float _deltaTime)
{
	// @@@ デバッグ
	// Bを押すと体力減少
	if (CheckHitKey(KEY_INPUT_B) && test == 0)
	{
		--mHP;

		if (mEnlargement < 0.0f)          // 画像を縮小中だったら
		{
			mEnlargement -= MIncrease;
		}
		else                              // 画像を拡大中だったら
		{
			mEnlargement += MIncrease;
		}
		
		test = 1;
	}
	if (!CheckHitKey(KEY_INPUT_B))
	{
		test = 0;
	}

	// Hpの大きさを拡大、縮小
	mUISizeY += mEnlargement;
	mUISizeX += mEnlargement;

	if (mUISizeY > MMaxHpSize || mUISizeY < MMinHpSize)
	{
		mEnlargement *= -1.0f;
	}
}

void Heart::Draw()
{
	// HPの描画
	if (mHP != 0)
	{
		for (int i = 0; i < mHP; ++i)   // HPが減ったら表示数を減らす
		{
			// 左上座標の計算
			int leftPosX = (int)mPos.x + (int)mUISizeX * i;

			DrawExtendGraph(leftPosX, (int)mPos.y,                       // 左上座標
				leftPosX + (int)mUISizeX, (int)mPos.y + (int)mUISizeY,  // 右下座標
				mImage, TRUE);
		}
	}
}
