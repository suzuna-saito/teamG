#include "UIManager.h"
#include "SceneBase.h"

// 自身のインスタンスの初期化
UIManager* UIManager::mManager = nullptr;

UIManager::UIManager()
{
}

void UIManager::CreateInstance()
{
	if (mManager == nullptr)
	{
		// インスタンスを生成
		mManager = new UIManager();
	}
}

void UIManager::DeleteInstance()
{
	// 残っているUIをすべて削除する
	for (auto UI : mManager->mUI)
	{
		delete UI;
	}

	if (mManager != nullptr)
	{
		// 削除
		delete mManager;
	}
}

void UIManager::AddUI(UIBase* _ui)
{
	// UIの追加
	mManager->mUI.emplace_back(_ui);
}

void UIManager::DeleteUI()
{
	// 消すUIを判別
	std::vector<UIBase*> deleteUI;
	for (auto UI : mManager->mUI)
	{
		// このUIが生成されたシーンと現在のシーンが異なれば
		if (UI->GetScene() != SceneBase::mIsScene)
		{
			deleteUI.emplace_back(UI);
		}
	}
	// UIを消す(mUIから削除される)
	for (auto UI : deleteUI)
	{
		delete UI;
	}
}

void UIManager::UpdateUI(float _deltaTime)
{
	for (auto UI : mManager->mUI)
	{
		// 各UIを更新
		UI->Update(_deltaTime);
	}
}

void UIManager::DrawUI()
{
	for (auto UI : mManager->mUI)
	{
		// 各UIを描画
		UI->Draw();
	}
}
