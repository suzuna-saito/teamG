#include "UIBase.h"
#include "UIManager.h"

UIBase::UIBase(const SceneBase::Scene& _nowScene)
	: mDirthplaceScene(_nowScene)
	, mPos()
	, mImage(0)
	, mUIHeight(0.0f)
	, mUIWidth(0.0f)
	, mEnlargement(0.0f)
{
	// UI‚ð’Ç‰Á‚·‚é
	UIManager::AddUI(this);
}

UIBase::~UIBase()
{
}
