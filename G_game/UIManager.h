#pragma once
// saito

#include "UIBase.h"

/* ���ׂĂ�UI�̍X�V���s�� */
class UIManager
{
public:
	//	�R���X�g���N�^
	UIManager();
	// �f�X�g���N�^
	~UIManager() {};

	// �C���X�^���X�𐶐�����
	static void CreateInstance();
	// �C���X�^���X���폜����
	static void DeleteInstance();

	/// <summary>
	/// UI�̒ǉ�
	/// </summary>
	/// <param name="_ui">�ǉ�����UI�̃|�C���^</param>
	static void AddUI(class UIBase* _ui);
	/// <summary>
	/// ���ׂĂ�UI�̍폜
	/// </summary>
	static void DeleteUI();

	/// <summary>
	/// ���ׂĂ�UI�̍X�V����
	/// </summary>
	/// <param name="_deltaTime">�Ō�̃t���[������������̂ɗv��������</param>
	static void UpdateUI(float _deltaTime);

	/// <summary>
	/// UI�̕`��
	/// </summary>
	static void DrawUI();

private:
	// UIManager�̎��́i�A�v�����ɗB�ꑶ�݁j
	static UIManager* mManager;

	// ���ׂĂ�UI���i�[����R���e�i
	std::vector<UIBase*>mUI;
};

