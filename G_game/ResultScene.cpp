// �C���N���[�h
#include "ResultScene.h"
#include "TitleScene.h"
#include "PlayScene.h"

ResultScene::ResultScene()
	: SceneBase(SceneBase::Scene::eResult)
{
	// ���U���g�摜�̓ǂݍ���(��)
	mImage = LoadGraph("data/assets/Result.png");
}

ResultScene::~ResultScene()
{
}

SceneBase* ResultScene::Update(float _deltaTime)
{
	// �V�[���J�ڏ���(A�������ƑJ�ځi���j)
	if (CheckHitKey(KEY_INPUT_A))
	{
		// �����𖞂����Ă�����^�C�g���V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new TitleScene();
	}
	// �V�[���J�ڏ���(S�������ƑJ�ځi���j)
	else if (CheckHitKey(KEY_INPUT_S))
	{
		// �����𖞂����Ă�����v���C�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new PlayScene();
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void ResultScene::Draw()
{
	// ���U���g�̕`��
	DrawGraph(0, 0, mImage, true);
}
