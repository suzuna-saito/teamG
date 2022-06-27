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
	/// <param name="_nextScene">���ɐ����������V�[���̃^�C�v</param>
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
	// �摜�̃^�O�i��ށj
	enum loadImage :unsigned char
	{
		eChar,    // ����
		eKoyake,  // �L�����N�^�[�i���₯�I�j
	};

	const int MSecond;        // �V�[���J�ڂ���܂ł̎��ԁi�~���P�ʁj
	const int MHalfSecond;    // 0.5�b�i�~���b�P�ʁj

	const int MDrawHeight;    // �����摜�̕`�悷��c��
	const int MInitWidthSize; // �����摜�̕`�悷�鉡���̏����l
	const int MDrawExpansion; // �����摜�̕`�悷��T�C�Y�̊g��l
	const int MMaxWidthSize;  // �����摜�̕`�悷��T�C�Y�̍ő�l

	const int MRightPosX;        // �L�����N�^�[�̉E�����WX
	const int MRightPosY;        // �L�����N�^�[�̉E�����WY
	const int MMaxKoyakeSizeY;   // �L�����N�^�[�摜�̍ő�T�C�YY
	const int MMinKoyakeSizeY;   // �L�����N�^�[�摜�̍ŏ��T�C�YY

	Scene mNextSceneType;   // ���̃V�[���̃^�C�v
	int mStartTime;         // ���[�h��ʂ��n�܂�������
	int mWeitTime;          // �܂���

	std::vector<int> mImages;  // �摜
	std::vector<VECTOR> mPos;  // �摜�̃|�W�V����
	int mDrawWidth;            // �����摜�̕`�悷�鉡��
	int mSize;                 // �L�����N�^�[�摜�̕`��T�C�Y
	int mChangeSize;           // �L�����N�^�[�摜�̕`��T�C�Y�ύX�l
};

