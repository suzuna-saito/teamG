#include "Background.h"
#include "Dxlib.h"

Background::Background()
	: mWidth(-1920.0f)
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
	// �w�i�̈ړ��X�s�[�h���|�W�V�����ɑ���
	mBackgroundPosY += mMoveSpeed * _deltaTime;
}

void Background::Draw()
{
	// �w�i�̕`��
	DrawGraph(0, (int)mBackgroundPosY, mBackgroundImage, true);
	DrawGraph(0, (int)mBackgroundPosY + 1920.0f, mBackgroundImage, true);

	// �ꖇ�ڂ̉摜����ʊO�ɍs�����珉���l�ɖ߂�
	if (mBackgroundPosY <= mWidth)
	{
		mBackgroundPosY = 0.0f;
	}
}
