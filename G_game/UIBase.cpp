#include "UIBase.h"
#include "UIManager.h"

UIBase::UIBase(const SceneBase::Scene& _nowScene)
	: mDirthplaceScene(_nowScene)
	, mImage(0)
	, mPos()
{
	// UI��ǉ�����
	UIManager::AddUI(this);
}

UIBase::~UIBase()
{
}
