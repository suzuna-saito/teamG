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

	// �ÓI�����o�ϐ�
	static bool mArrowStopFlag;    // �n�ʂɒ��n������ɎO�p�����܂ōs�������ǂ���
private:
	// �萔
	const float MArrowMaxPosX;      // �O�p�̍ő�|�W�V����
	const float MArrowMinPosX;      // �O�p�̍ŏ��|�W�V����
	const float MSpeedControlSoon;  // ���x�̑����𐧌�����
	const float MSpeedControlSlow;  // ���x�̌����𐧌�����
	const float MEndArrowSpeed;     // ���n�����Ƃ��̎O�p�̈ړ��X�s�[�h

	// �ϐ�
	int mArrowImage;           // �O�p�摜
	VECTOR mArrowPos;          // �O�p�̃|�W�V����
	float mMoveSpeed;          // �O�p�̈ړ��X�s�[�h
};

