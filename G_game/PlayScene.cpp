// �C���N���[�h
#include "PlayScene.h"
#include "ResultScene.h"
#include "Enemy.h"
#include <time.h>

PlayScene::PlayScene()
    : SceneBase(),Enemy()
{
    // �v���C�摜�̓ǂݍ���(��)
    mImage = LoadGraph("data/assets/Play.png");

	//�G�̓ǂݍ���
	mEnemy1Image;
	mEnemy2Image;
	mEnemy3Image;
	mEnemy4Image;
	mEnemy5Image;

	startTime = clock() / CLOCKS_PER_SEC;
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
	while (1) { //�P���ԃ��[�v����

		Enemy::Update();
		if (totalTime > setTime) //���[�v���I�������
			break;
		endTime = clock() / CLOCKS_PER_SEC;
		totalTime = endTime - startTime;
	}

	//return this;
	return new ResultScene();
}

void PlayScene::Draw()
{
    // �v���C�̕`��
    DrawGraph(0, 0, mImage, true);

	//�G�̕`��
	//Enemy::Draw();
}
