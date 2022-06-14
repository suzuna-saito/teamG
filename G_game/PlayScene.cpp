// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"
#include "Speedometer.h"

PlayScene::PlayScene()
    : SceneBase(SceneBase::Scene::ePlay)
{
	// ����
	mBackground = new Background();  // �w�i
	new Speedometer();               // �X�s�[�h���[�^�[
}

PlayScene::~PlayScene()
{
	// �w�i�̍폜
	delete mBackground;
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	// �V�[���J�ڏ���(�X�y�[�X�L�[�������ƑJ�ځi���j)
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// �����𖞂����Ă����烊�U���g�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new ResultScene();
	}

	// �w�i�̍X�V
	mBackground->Update(_deltaTime);

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void PlayScene::Draw()
{
    // �w�i�̕`��
	mBackground->Draw();
}
