#pragma once

// �C���N���[�h
#include "SceneBase.h"
#include "Background.h"
#include "Distance.h"
#include "Speedometer.h"
#include "Heart.h"

/* �v���C�V�[�� */
class PlayScene :public SceneBase
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

private:
	// �w�i�N���X�̃|�C���^
	class Background* mBackground;
	// �X�s�[�h���[�^�[�N���X�̃|�C���^
	class Speedometer* mSpeedmeter;
};

