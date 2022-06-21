#pragma once

// �C���N���[�h
#include "DxLib.h"

const int ScreenBeside = 650;
const int ScreenVertical = 1080;
const int ColorDepth = 16;

/* �V�[���̊��N���X */
class SceneBase
{
public:
	// �V�[���̃^�O�i��ށj
	enum class Scene :unsigned char
	{
		eInit,    // �������
		eTitle,   // �^�C�g��
		ePlay,    // �v���C
		eResult,  // ���U���g
	};

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_nowScene">���݂̃V�[��</param>
	SceneBase(Scene _nowScene);
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

	// ���݂̃V�[���^�O
	static Scene mIsScene;

protected:
	// �V�[���摜
	int mImage;
};

