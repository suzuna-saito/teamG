#pragma once
// saito

#include <vector>
#include "SceneBase.h"

/* UI�̊��N���X */
class UIBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_UI">UIBase�̃|�C���^</param>
	UIBase(UIBase* _ui);
	// �f�X�g���N�^
	~UIBase();

	/// <summary>
	/// UI�̍X�V����
	/// </summary>
	virtual void Update(float _deltaTime) = 0;

	/// <summary>
	/// UI�̕`��
	/// </summary>
	virtual void Draw() = 0;

private:
	// �e����UI�𐶐������V�[��
	SceneBase::Scene mDirthplaceScene;
};

