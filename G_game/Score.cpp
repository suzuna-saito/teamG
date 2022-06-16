#include "Score.h"

// 自身のインスタンスの初期化
Score* Score::mScore = nullptr;

Score::Score()
{
}

Score::~Score()
{
}

void Score::CreateInstance()
{
	if (mScore == nullptr)
	{
		// インスタンスを生成
		mScore = new Score();
	}
}

void Score::DeleteInstance()
{
	if (mScore != nullptr)
	{
		// 削除
		delete mScore;
	}
}

void Score::Update(float _deltaTime)
{

}

void Score::Draw()
{
}
