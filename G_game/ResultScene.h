#pragma once

// �C���N���[�h
#include "SceneBase.h"

/* ���U���g�V�[�� */
class ResultScene :public SceneBase
{
public:
	// �R���X�g���N�^
	ResultScene();
	// �f�X�g���N�^
	~ResultScene();

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	/// <returns>���݂̃V�[���̃|�C���^</returns>
	SceneBase* Update(float _deltaTime)override;

	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	void Draw()override;
};

