#pragma once

// �C���N���[�h
#include "SceneBase.h"

/* �^�C�g���V�[�� */
class TitleScene :public SceneBase
{
public:
	// �R���X�g���N�^
	TitleScene();
	// �f�X�g���N�^
	~TitleScene();

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

