#include "UIManager.h"
#include "SceneBase.h"

// ���g�̃C���X�^���X�̏�����
UIManager* UIManager::mManager = nullptr;

UIManager::UIManager()
{
}

void UIManager::CreateInstance()
{
	if (mManager == nullptr)
	{
		// �C���X�^���X�𐶐�
		mManager = new UIManager();
	}
}

void UIManager::DeleteInstance()
{
	// �c���Ă���UI�����ׂč폜����
	for (auto UI : mManager->mUI)
	{
		delete UI;
	}

	if (mManager != nullptr)
	{
		// �폜
		delete mManager;
	}
}

void UIManager::AddUI(UIBase* _ui)
{
	// UI�̒ǉ�
	mManager->mUI.emplace_back(_ui);
}

void UIManager::DeleteUI()
{
	// ����UI�𔻕�
	std::vector<UIBase*> deleteUI;
	for (auto UI : mManager->mUI)
	{
		// ����UI���������ꂽ�V�[���ƌ��݂̃V�[�����قȂ��
		if (UI->GetScene() != SceneBase::mIsScene)
		{
			deleteUI.emplace_back(UI);
		}
	}
	// UI������(mUI����폜�����)
	for (auto UI : deleteUI)
	{
		delete UI;
	}
}

void UIManager::UpdateUI(float _deltaTime)
{
	for (auto UI : mManager->mUI)
	{
		// �eUI���X�V
		UI->Update(_deltaTime);
	}
}

void UIManager::DrawUI()
{
	for (auto UI : mManager->mUI)
	{
		// �eUI��`��
		UI->Draw();
	}
}
