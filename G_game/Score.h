#pragma once
// saito

#include "DxLib.h"
#include <math.h>
#include "BackGround.h"
#include "Speedometer.h"

#define NUM 10  // �����̎�ނ̐��i0�`9�j�܂��� ���鐔

/* �X�R�A�̏��� */
class Score
{
public:
	// �R���X�g���N�^
	Score();
	// �f�X�g���N�^
	~Score();

	// �C���X�^���X�𐶐�����
	static void CreateInstance();
	// �C���X�^���X���폜����
	static void DeleteInstance();

	/// <summary>
	/// �X�R�A�̍X�V����
	/// </summary>
	/// <param name="_deltaTime">�Ō�̃t���[������������̂ɗv��������</param>
	static void Update(float _deltaTime);

	/// <summary>
	/// �X�R�A�̕`��
	/// </summary>
	static void Draw();
private:
	// Score�̎��́i�A�v�����ɗB�ꑶ�݁j
	static Score* mScore;

	// �萔
	const int MAllnum;        // �摜�̕�������
	const int MNumX, MNumY;   // �摜�̏c�A��������
	const int MSizeX, MSizeY; // �������ꂽ�摜��̑傫��
	const int Mdigit;         // ����
	const int MMaxScore;      // �X�R�A�̍ō����_
	const int MSubScore;      // �X�R�A�̌��_��

	// �ϐ�
	int mImage;              // �X�R�A�����摜
	int mDivisionImage[NUM]; // ��������̉摜��ۊǂ���ꏊ
	VECTOR mPos;        // �X�R�A�����`����W
	VECTOR mNumeraPos;  // ���� �`����W

	int mNowScore;      // ���݂̃X�R�A
	int mTopScore;      // ���܂ł̃X�R�A�ň�Ԃ����_��
	bool mChangeScore;  // �ō��X�R�A�̕ύX���s�������ǂ���

	// �֐�
	void mSubtract();   // �X�R�A�̓_������
};

