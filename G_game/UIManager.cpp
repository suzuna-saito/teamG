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
	// UIの格納
	mManager->mUI.emplace_back(_ui);
}

void UIManager::DeleteUI()
{
	// 全てのUIをmPendingActorsに一時的に保管
	mManager->mPendingActors = mManager->mUI;

	// UIを格納するコンテナを空にする
	mManager->mUI.clear();

	// 格納するUIを判別
	for (auto UI : mManager->mPendingActors)
	{
		// このUIが生成されたシーンと現在のシーンが一緒だったら
		if (UI->GetDirthplaceScene() == SceneBase::mIsScene)
		{
			// このUIを格納
			mManager->mUI.emplace_back(UI);
		}
	}

	mManager->mPendingActors.clear();
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
