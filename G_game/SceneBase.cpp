// �C���N���[�h
#include "SceneBase.h"

// ���݂̃V�[���̏�����
SceneBase::Scene SceneBase::mIsScene = Scene::eInit;

SceneBase::SceneBase(Scene _nowScene)
	: mImage(0)
{
	mIsScene = _nowScene;
}

SceneBase::~SceneBase()
{
	// �����Ȃ�
}