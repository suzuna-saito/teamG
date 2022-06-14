#include "Background.h"
#include "Dxlib.h"

Background::Background()
	: MHeight(-1920.0f)
	, mBackgroundPosY(0.0f)
	, mMoveSpeed(-500.0f)
{
	// ”wŒi‰æ‘œ‚Ì“Ç‚İ‚İ
	mBackgroundImage = LoadGraph("data/assets/Background.png");
}

Background::~Background()
{
}

void Background::Update(float _deltaTime)
{
	// ”wŒiƒ|ƒWƒVƒ‡ƒ“‚ÌXV
	mBackgroundPosY += mMoveSpeed * _deltaTime;
}

void Background::Draw()
{
	// ”wŒi‚Ì•`‰æ
	DrawGraph(0, (int)mBackgroundPosY, mBackgroundImage, true);
	DrawGraph(0, (int)mBackgroundPosY - MHeight, mBackgroundImage, true);

	// ˆê–‡–Ú‚Ì‰æ‘œ‚ª‰æ–ÊŠO‚És‚Á‚½‚ç‰Šú’l‚É–ß‚·
	if (mBackgroundPosY <= MHeight)
	{
		mBackgroundPosY = 0.0f;
	}
}
