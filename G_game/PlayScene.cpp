// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"

PlayScene::PlayScene()
    : SceneBase(SceneBase::Scene::ePlay)
{
	// ����
	mBackground = new Background();         // �w�i
	mHeart = new Heart();                   // �c�@
	new Speedometer();                      // �X�s�[�h���[�^�[
	new Distance(mBackground);              // �c��̒���
}

PlayScene::~PlayScene()
{
	delete mBackground;  // �w�i�̍폜
	delete mSpeedmeter;  // �X�s�[�h���[�^�[�̍폜
	delete mHeart;       // �c�@�̍폜
}

SceneBase* PlayScene::Update(float _deltaTime)
{
	// �n�ʂ܂Œ��n���āA���[�^�[�����܂ŗ�����
	if (mHeart->GetHP() == 0)
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
