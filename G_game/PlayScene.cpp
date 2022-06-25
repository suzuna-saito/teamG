// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"

PlayScene::PlayScene()
    : SceneBase(SceneBase::Scene::ePlay)
{
	// ����
	mBackground = new Background();         // �w�i
	mEnemy = new Enemy();                   // �G�l�~�[
	mPlayer = new Player();                 // �v���C���[
	mHeart = new Heart();                   // �c�@
	new Countdown();                        // �J�E���g�_�E��
	new Speedometer();                      // �X�s�[�h���[�^�[
	new Distance(mBackground);              // �c��̒���
}

PlayScene::~PlayScene()
{
	delete mBackground;  // �w�i�̍폜
	delete mEnemy;       // �G�l�~�[�̍폜
	delete mPlayer;      // �v���C���[�̍폜
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
	// �G�l�~�[�̍X�V
	mEnemy->Update();
	// �v���C���[�̍X�V
	mPlayer->BesidePlayerMove();
	mPlayer->PlayerSpeed();
	mPlayer->PlayerLanding();

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void PlayScene::Draw()
{
    // �w�i�̕`��
	mBackground->Draw();
	// �G�l�~�[�̕`��
	mEnemy->Draw();
	// �v���C���[�̕`��
	mPlayer->PlayerDraw();
}
