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
};