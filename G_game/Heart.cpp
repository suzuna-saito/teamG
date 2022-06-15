#include "Heart.h"

Heart::Heart()
	: UIBase(SceneBase::mIsScene)
{
	// �摜�̓ǂݍ���
	mImage = LoadGraph("data/assets/UI/Heart.png");       // �n�[�g

	// �|�W�V�����̐ݒ�
	mPos.x = 10.0f;
	mPos.y = 10.0f;
}

Heart::~Heart()
{
}

void Heart::Update(float _deltaTime)
{
}

void Heart::Draw()
{
	// �`��
	DrawGraph((int)mPos.x, (int)mPos.y, mImage, true);    // �n�[�g
}
