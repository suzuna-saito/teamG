#pragma once
// saito

#include <vector>
#include <DxLib.h>
#include "SceneBase.h"

/* UI�̊��N���X */
class UIBase
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_nowScene">�������ꂽ���̃V�[��</param>
	UIBase(const SceneBase::Scene& _nowScene);
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

protected:
	// �ϐ�
	VECTOR mPos;         // �|�W�V����
	int mImage;          // UI�摜
	float mEnlargement;  // �g�嗦

private:
	// �e����UI�𐶐������V�[��
	SceneBase::Scene mDirthplaceScene;

public: // �Q�b�^�[�A�Z�b�^�[
	// �eUI���������ꂽ���̃V�[����Ԃ�
	SceneBase::Scene GetDirthplaceScene() { return mDirthplaceScene; }
};

