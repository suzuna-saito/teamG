#pragma once
// saito

#include "UIBase.h"

/* �c�@�̏��� */
class Heart :public UIBase
{
public:
	// �R���X�g���N�^
	Heart();
	// �f�X�g���N�^
	~Heart();

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
	const float MMaxHpSize;   // HP�摜�̍ő�̑傫��
	const float MMinHpSize;   // HP�摜�̍ŏ��̑傫��
	const float MIncrease;    // �g�嗦�̑�����
	// �ϐ�
	int mHP;        // HP

	int test;
};