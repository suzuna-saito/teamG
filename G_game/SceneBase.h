#pragma once

// �C���N���[�h
#include "DxLib.h"

/* �V�[���̊��N���X */
class SceneBase
{
public:
	// �R���X�g���N�^
	SceneBase();
	// �f�X�g���N�^
	~SceneBase();

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	/// <returns>���݂̃V�[���̃|�C���^</returns>
	virtual SceneBase* Update(float _deltaTime) = 0;

	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	virtual void Draw() = 0;

protected:
	// �V�[���摜
	int mImage;
};

