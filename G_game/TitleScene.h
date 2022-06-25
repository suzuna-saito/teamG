#pragma once

// �C���N���[�h
#include "SceneBase.h"
#include <vector>

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

private:
	// �萔
	const int MMinAlpha;   // �ŏ������x
	const int MMaxAlpha;   // �ő哧���x

	// �ϐ�
	std::vector<int> mOtherImage;  // �摜
	std::vector<VECTOR> mPos;      // �摜�̃|�W�V����

	int mAlpha;      // �����x
	int mChangeSpeed;// �����x�̕ω��l
};

