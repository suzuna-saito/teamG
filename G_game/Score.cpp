#include "Score.h"

// ���g�̃C���X�^���X�̏�����
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
		// �C���X�^���X�𐶐�
		mScore = new Score();
	}
}

void Score::DeleteInstance()
{
	if (mScore != nullptr)
	{
		// �폜
		delete mScore;
	}
}

void Score::Update(float _deltaTime)
{

}

void Score::Draw()
{
}
