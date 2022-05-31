// �C���N���[�h
#include "TitleScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
	: SceneBase()
{
	// �^�C�g���摜�̓ǂݍ���(��)
	mImage = LoadGraph("data/assets/Title.png");
}

TitleScene::~TitleScene()
{
}

SceneBase* TitleScene::Update(float _deltaTime)
{
	// �V�[���J�ڏ���(�G���^�[�������ƑJ�ځi���j)
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		// �����𖞂����Ă�����v���C�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new PlayScene();
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void TitleScene::Draw()
{
	// �^�C�g���̕`��
	DrawGraph(0, 0, mImage, true);
}
