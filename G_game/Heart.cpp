#include "Heart.h"

Heart::Heart()
	: UIBase(SceneBase::mIsScene)
	, MMaxHpSize(75.0f)
	, MMinHpSize(70.0f)
	, MIncrease(0.2f)
	, mHP(3)
{
	// 画像の読み込み
	mImage = LoadGraph("data/assets/UI/Heart.png");       // ハート

	// ポジションの設定
	mPos.x = 20.0f;
	mPos.y = 20.0f;

	// UIのサイズ
	mUIWidth = 70.0f;
	mUIHeight = 70.0f;

	// 拡大率
	mEnlargement = 0.3f;

	// デバック用
	test = 0;
}

Heart::~Heart()
{
	DeleteGraph(mImage);
}

void Heart::Update(float _deltaTime)
{
	// @@@ デバック
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
	mUIHeight += mEnlargement;
	mUIWidth += mEnlargement;

	if (mUIHeight > MMaxHpSize || mUIHeight < MMinHpSize)
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
			int leftPosX = (int)mPos.x + mUIWidth * i;

			DrawExtendGraph(leftPosX, (int)mPos.y,                       // 左上座標
				leftPosX + (int)mUIWidth, (int)mPos.y + (int)mUIHeight,  // 右下座標
				mImage, TRUE);
		}
	}
}
