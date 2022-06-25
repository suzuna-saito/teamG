#pragma once
#include "SceneBase.h"
#include <vector>
#include <map>

/* ���[�h�V�[�� */
class LoadScene :public SceneBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_nextScene">���̃V�[���̃^�C�v</param>
	LoadScene(Scene _nextScene);
	// �f�X�g���N�^
	~LoadScene();

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	/// <returns>���݂̃V�[���̃|�C���^</returns>
	SceneBase* Update(float _deltaTime)override;

	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	void Draw()override;

private:
	const int MSecond;      // �V�[���J�ڂ���܂ł̎��ԁi�~���P�ʁj

	Scene mNextSceneType;   // ���̃V�[���̃^�C�v
	int mStartTime;         // ���[�h��ʂ��n�܂�������
};

