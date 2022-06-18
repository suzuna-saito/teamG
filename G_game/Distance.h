#pragma once
// saito

#include "UIBase.h"
#include "Background.h"
#include <DxLib.h>
#include <math.h>

#define NUM 10

/* �c��̒����̏��� */
class Distance :public UIBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_background">�w�i�̃|�C���^</param>
	Distance(Background* _background);
	// �f�X�g���N�^
	~Distance();

	/// <summary>
	/// �����̒����̍X�V����
	/// </summary>
	/// <param name="_deltaTime"></param>
	void Update(float _deltaTime)override;

	/// <summary>
	/// �����̒����`��
	/// </summary>
	void Draw()override;

private:
	// �萔
	const int MAllnum;        // �摜�̕�������
	const int MNumX, MNumY;   // �摜�̏c�A��������
	const int MSizeX, MSizeY; // �������ꂽ�摜��̑傫��
	const int Mdigit;         // ����

	// �ϐ�
	int mDivisionImage[NUM];   // ��������̉摜��ۊǂ���ꏊ
	int  mRemaining;           // �c��̒���
	float mAdjustment;         // �c��̒����̒����l
	float mSubtraction;        // ���Z�l
	VECTOR mNumeraPos;         // �c��̒��� �`����W

	// �w�i�̃|�C���^
	class Background* mBackground;
};

