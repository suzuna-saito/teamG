// インクルード
#include "LoadScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "PlayScene.h"

LoadScene::LoadScene(Scene _nextScene)
	: SceneBase(SceneBase::Scene::eLoad)
	, MSecond(5000)
	, MHalfSecond(500)
	, mStartTime(GetNowCount())
	, MInitWidthSize(220)
	, MDrawExpansion(35)
	, MMaxWidthSize(MInitWidthSize + MDrawExpansion * 3)
	, MDrawHeight(190)
	, MRightPosX(150)
	, MRightPosY(250)
	, MMaxKoyakeSizeY(20)
	, MMinKoyakeSizeY(0)
	, mDrawWidth(MInitWidthSize)
	, mSize(MMinKoyakeSizeY)
	, mChangeSize(1)
	, mWeitTime(500)
{
	// ロード画像の読み込み(仮)
	mImages.emplace_back(LoadGraph("data/assets/LoadScene/Load.png"));      // 文字
	mImages.emplace_back(LoadGraph("data/assets/LoadScene/Koyake.png"));    // キャラクター

	// ポジションの設定
	mPos.emplace_back(VGet(280.0f, 850.0f, 0.0f)); // 文字
	mPos.emplace_back(VGet(450.0f, 550.0f, 0.0f)); // キャラクター

	// 次のシーンのタイプ
	mNextSceneType = _nextScene;
}

LoadScene::~LoadScene()
{
	// ベクター型に保存している画像を全て消す
	for (auto image : mImages)
	{
		DeleteGraph(image);
	}
}

SceneBase* LoadScene::Update(float _deltaTime)
{
	// ロード画面に入って指定の秒数たったら
	if (GetNowCount() - mStartTime >= MSecond)
	{
		// mNextSceneTypeによって、次のシーンを生成
		if (mNextSceneType == Scene::eTitle)
		{
			return new TitleScene();
		}
		else if (mNextSceneType == Scene::ePlay)
		{
			return new PlayScene();
		}
		else if (mNextSceneType == Scene::eResult)
		{
			return new ResultScene();
		}
	}

	// 描画する矩形サイズの変更(loading)
	if (mDrawWidth <= MMaxWidthSize)  // 描画する矩形サイズが最大までいってなかったら
	{
		if (GetNowCount() - mStartTime >= mWeitTime) // 0.5秒たったら
		{
			mDrawWidth += MDrawExpansion;  // 描画サイズを大きくする

			mWeitTime += MHalfSecond;      // 更新を待つ時間を0.5秒増やす 
		}
	}
	else
	{
		mDrawWidth = MInitWidthSize;   // 初期サイズに戻す
	}

	// キャラクターのサイズを変える(koyake)
	if (mSize > MMaxKoyakeSizeY ||    // 今のサイズが最大より上になったら または
		mSize < MMinKoyakeSizeY)      // 今のサイズが最小未満になったら
	{
		mChangeSize *= -1;            // サイズ変化値の符号を変える
	}

	// サイズを変える
	mSize += mChangeSize;
	
	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return this;
}

void LoadScene::Draw()
{
	// 指定矩形部分のみ描画（loading）
	DrawRectGraph((int)mPos[loadImage::eChar].x, (int)mPos[loadImage::eChar].y,0, 0,
		mDrawWidth, MDrawHeight,mImages[loadImage::eChar], TRUE, FALSE);
	// 拡大縮小描画(koyake)
	DrawExtendGraph(
		(int)mPos[loadImage::eKoyake].x, (int)mPos[loadImage::eKoyake].y - mSize,                    // 左上
		(int)mPos[loadImage::eKoyake].x + MRightPosX, (int)mPos[loadImage::eKoyake].y + MRightPosY,  // 右下
		mImages[loadImage::eKoyake], TRUE);

}
