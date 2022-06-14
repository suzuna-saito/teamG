#pragma once
// saito

#include "UIBase.h"

/* �X�s�[�h���[�^�[�̏��� */
class Speedometer :public UIBase
{
public:
	// �R���X�g���N�^
	Speedometer();
	// �f�X�g���N�^
	~Speedometer();

	/// <summary>
	/// UI�̍X�V����
	/// </summary>
	void Update(float _deltaTime)override;

	/// <summary>
	/// UI�̕`��
	/// </summary>
	void Draw()override;

private:
	// �萔
	const float MArrowMaxPosX;      // �O�p�̍ő�|�W�V����
	const float MArrowMinPosX;      // �O�p�̍ŏ��|�W�V����
	const float MSpeedControlSoon;  // ���x�̑����𐧌�����
	const float MSpeedControlSlow;  // ���x�̌����𐧌�����

	// �ϐ�
	int mArrowImage;           // �O�p�摜
	VECTOR mArrowPos;          // �O�p�̃|�W�V����
	float mMoveSpeed;          // �O�p�̈ړ��X�s�[�h
};

