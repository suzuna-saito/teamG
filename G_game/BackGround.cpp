#include "Background.h"
#include "Dxlib.h"

Background::Background()
	: MHeight(-1920.0f)
	, mBackgroundPosY(0.0f)
	, mMoveSpeed(-500.0f)
{
	// �w�i�摜�̓ǂݍ���
	mBackgroundImage = LoadGraph("data/assets/Background.png");
}

Background::~Background()
{
}

void Background::Update(float _deltaTime)
{
	// �w�i�|�W�V�����̍X�V
	mBackgroundPosY += mMoveSpeed * _deltaTime;
}

void Background::Draw()
{
	// �w�i�̕`��
	DrawGraph(0, (int)mBackgroundPosY, mBackgroundImage, true);
	DrawGraph(0, (int)mBackgroundPosY - MHeight, mBackgroundImage, true);

	// �ꖇ�ڂ̉摜����ʊO�ɍs�����珉���l�ɖ߂�
	if (mBackgroundPosY <= MHeight)
	{
		mBackgroundPosY = 0.0f;
	}
}
