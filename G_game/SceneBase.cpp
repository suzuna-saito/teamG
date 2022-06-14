// インクルード
#include "SceneBase.h"

// 現在のシーンの初期化
SceneBase::Scene SceneBase::mIsScene = Scene::eInit;

SceneBase::SceneBase(Scene _nowScene)
	: mImage(0)
{
	mIsScene = _nowScene;
}

SceneBase::~SceneBase()
{
	// 処理なし
}