// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"

PlayScene::PlayScene()
    : SceneBase()
{
    // �v���C�摜�̓ǂݍ���(��)
    mImage = LoadGraph("data/assets/Play.png");
}

PlayScene::~PlayScene()
{
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	// �V�[���J�ڏ���(�X�y�[�X�L�[�������ƑJ�ځi���j)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// �����𖞂����Ă����烊�U���g�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new ResultScene();
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void PlayScene::Draw()
{
    // �v���C�̕`��
    DrawGraph(0, 0, mImage, true);
}
