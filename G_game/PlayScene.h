#pragma once

// �C���N���[�h
#include "SceneBase.h"
#include "Enemy.h"

/* �v���C�V�[�� */
class PlayScene :public SceneBase,Enemy
{
public:
	// �R���X�g���N�^
	PlayScene();
	// �f�X�g���N�^
	~PlayScene();

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

