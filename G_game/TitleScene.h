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
	// �摜�̃^�O�i��ށj
	enum Image :unsigned char
	{
		eBack,    // �w�i
		eChar,    // ����
		eSmoke,   // ��
		eButton,  // �{�^��
		eButton2, // ��̃{�^���Ƃ͕ʂ̃{�^��
	};

	// �J�[�\�������킹�Ă���ʒu
	enum class CursorPos :unsigned char
	{
		eNone,    // �ǂ��ɂ������Ă��Ȃ�
		eStart,   // �X�^�[�g
		eScore,   // �X�R�A
	};

	/// <summary>
	/// CursorPos�ɍ��킹�ă{�^���̕`��
	/// </summary>
	void DrawButton();

	// �萔
	const int MCollisionLeftX;   // �{�^���̍�X���W�@�����l�i�����蔻��j
	const int MCollisionRightX;  // �{�^���̉EX���W�@�����l�i�����蔻��j
	const int MCollisionLeftY;   // �{�^���̍�Y���W�@�����l�i�����蔻��j
	const int MCollisionRightY;  // �{�^���̉EY���W�@�����l�i�����蔻��j
	const int MMinAlpha;   // �ŏ������x
	const int MMaxAlpha;   // �ő哧���x

	// �ϐ�
	std::vector<int> mImages;  // �摜
	std::vector<VECTOR> mPos;  // �摜�̃|�W�V����
	
	int mMousePosX;          // �}�E�X�̃|�W�V����
	int mMousePosY;          // �}�E�X�̃|�W�V����
	CursorPos mNowCursorPos; // ���݃J�[�\�������킹�Ă���|�W�V����

	int mAlpha;              // �����x
	int mChangeSpeed;        // �����x�̕ω��l
};

