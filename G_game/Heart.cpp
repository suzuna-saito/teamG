#include "Heart.h"

Heart::Heart()
	: UIBase(SceneBase::mIsScene)
	, MMaxHpSize(55.0f)
	, MMinHpSize(50.0f)
	, MIncrease(0.2f)
	, mHP(3)
{
	// �摜�̓ǂݍ���
	mImage = LoadGraph("data/assets/UI/Heart.png");       // �n�[�g

	// �|�W�V�����̐ݒ�
	mPos.x = 20.0f;
	mPos.y = 20.0f;

	// UI�̃T�C�Y
	mUISizeX = 50.0f;
	mUISizeY = 50.0f;

	// �g�嗦
	mEnlargement = 0.15f;

	// �f�o�b�N�p
	test = 0;
}

Heart::~Heart()
{
	DeleteGraph(mImage);
}

void Heart::Update(float _deltaTime)
{
	// @@@ �f�o�b�O
	// B�������Ƒ̗͌���
	if (CheckHitKey(KEY_INPUT_B) && test == 0)
	{
		--mHP;

		if (mEnlargement < 0.0f)          // �摜���k������������
		{
			mEnlargement -= MIncrease;
		}
		else                              // �摜���g�咆��������
		{
			mEnlargement += MIncrease;
		}
		
		test = 1;
	}
	if (!CheckHitKey(KEY_INPUT_B))
	{
		test = 0;
	}

	// Hp�̑傫�����g��A�k��
	mUISizeY += mEnlargement;
	mUISizeX += mEnlargement;

	if (mUISizeY > MMaxHpSize || mUISizeY < MMinHpSize)
	{
		mEnlargement *= -1.0f;
	}
}

void Heart::Draw()
{
	// HP�̕`��
	if (mHP != 0)
	{
		for (int i = 0; i < mHP; ++i)   // HP����������\���������炷
		{
			// ������W�̌v�Z
			int leftPosX = (int)mPos.x + (int)mUISizeX * i;

			DrawExtendGraph(leftPosX, (int)mPos.y,                       // ������W
				leftPosX + (int)mUISizeX, (int)mPos.y + (int)mUISizeY,  // �E�����W
				mImage, TRUE);
		}
	}
}
