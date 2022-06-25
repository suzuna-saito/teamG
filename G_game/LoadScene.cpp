// �C���N���[�h
#include "LoadScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "PlayScene.h"

LoadScene::LoadScene(Scene _nextScene)
	: SceneBase(SceneBase::Scene::eLoad)
	, MSecond(3000)
	, mStartTime(GetNowCount())
{
	// ���[�h�摜�̓ǂݍ���(��)
	mImage = LoadGraph("data/assets/ResultScene/Result.png");

	// ���̃V�[���̃^�C�v
	mNextSceneType = _nextScene;
}

LoadScene::~LoadScene()
{
	DeleteGraph(mImage);
}

SceneBase* LoadScene::Update(float _deltaTime)
{
	// ���[�h��ʂɓ����Ďw��̕b����������
	if (GetNowCount() - mStartTime >= MSecond)
	{
		// mNextSceneType�ɂ���āA���̃V�[���𐶐�
		if (mNextSceneType == Scene::eTitle)
		{
			return new TitleScene();
		}
		else if (mNextSceneType == Scene::ePlay)
		{
			return new PlayScene();
		}
		else if (mNextSceneType == Scene::eResult)
		{
			return new ResultScene();
		}
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void LoadScene::Draw()
{
	// ���[�h�̕`��
	DrawGraph(0, 0, mImage, TRUE);
}
