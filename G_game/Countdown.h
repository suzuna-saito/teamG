#pragma once
// saito

#include "DxLib.h"
#include <math.h>
#include "BackGround.h"
#include "Speedometer.h"

#define NUM 10  // �����̎�ނ̐��i0�`9�j

/* �J�E���g�_�E���̏��� */
class Countdown :public UIBase
{
public:
	// �R���X�g���N�^
	Countdown();
	// �f�X�g���N�^
	~Countdown();

	/// <summary>
	/// �J�E���g�_�E���̍X�V����
	/// </summary>
	void Update(float _deltaTime)override;

	/// <summary>
	/// �J�E���g�_�E���̕`��
	/// </summary>
	void Draw()override;

private:
	// �萔
	const int MAllnum;        // �摜�̕�������
	const int MNumX, MNumY;   // �摜�̏c�A��������
	const int MSizeX, MSizeY; // �������ꂽ�摜��̑傫��
	const int Mdigit;         // ����
	const int MOneSecond;     // ��b�~���P��

	// �ϐ�
	int mDivisionImage[NUM]; // ��������̉摜��ۊǂ���ꏊ
	VECTOR mNumeraPos;       // ���� �`����W

	int mStartTime;         // ��b�̌v�����n�߂鎞��
	int mNowTime;           // ���݂̃^�C��
	int mSubTime;           // �b���̌��Z�l

};
