#pragma once
// saito

#include "UIBase.h"

/* �X�s�[�h���[�^�[�̏��� */
class Speedometer :public UIBase
{
public:
	// ���݃��[�^�[������F
	enum class MeterColor :unsigned char
	{
		eGreen,
		eYellow,
		eRed,
	};

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
	static MeterColor mMeterColor; // ���݂̃��[�^�[�̐F
private:
	// �萔
	const float MArrowMaxPosX;      // �O�p�̍ő�|�W�V����
	const float MArrowMinPosX;      // �O�p�̍ŏ��|�W�V����
	const float MYellowPos;         // ���[�^�[�̉��F�����|�W�V����(�E���W)
	const float MRedPos;            // ���[�^�[�̐ԕ����|�W�V����(�E���W)

	const float MSpeedControlSoon;  // �O�p�̑��x�̑����𐧌�����
	const float MSpeedControlSlow;  // �O�p�̑��x�̌����𐧌�����
	const float MEndArrowSpeed;     // ���n�����Ƃ��̎O�p�̈ړ��X�s�[�h

	// �ϐ�
	int mArrowImage;           // �O�p�摜
	VECTOR mArrowPos;          // �O�p�̃|�W�V����
	float mMoveSpeed;          // �O�p�̈ړ��X�s�[�h
};

