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
	// UI�̊i�[
	mManager->mUI.emplace_back(_ui);
}

void UIManager::DeleteUI()
{
	// �S�Ă�UI��mPendingActors�Ɉꎞ�I�ɕۊ�
	mManager->mPendingActors = mManager->mUI;

	// UI���i�[����R���e�i����ɂ���
	mManager->mUI.clear();

	// �i�[����UI�𔻕�
	for (auto UI : mManager->mPendingActors)
	{
		// ����UI���������ꂽ�V�[���ƌ��݂̃V�[�����ꏏ��������
		if (UI->GetDirthplaceScene() == SceneBase::mIsScene)
		{
			// ����UI���i�[
			mManager->mUI.emplace_back(UI);
		}
	}

	mManager->mPendingActors.clear();
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
