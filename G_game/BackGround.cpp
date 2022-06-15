#include "Background.h"
#include "Speedometer.h"
#include "Dxlib.h"


// ����
// �X�s�[�h���}�C�i�X�ɂȂ�قǑ����B(Y���̏オ�}�C�i�X�Ȃ̂�)

// �ÓI�����o�ϐ��̏�����
Background::Speed Background::mNowSpeed = Speed::eAcceleration;
float Background::mMoveSpeed = -100.0f;

Background::Background()
	: MHeight(-1920.0f)
	, MAcceleration(-6.0f)
	, MDeceleration(-7.0f)
	, MMaxSpeed(-1300.0f)
	, MMinSpeed(-300.0f)
	, mBackgroundPosY(0.0f)
{
	// �w�i�摜�̓ǂݍ���
	mBackgroundImage = LoadGraph("data/assets/Background.png");
}

Background::~Background()
{
}

void Background::Update(float _deltaTime)
{
	// �{�^����������Ă����� ���A�X�N���[�����x���ŏ����x����Ȃ�������
	if (CheckHitKey(KEY_INPUT_A) && mMoveSpeed < MMinSpeed)
	{
		mMoveSpeed -= MDeceleration;        // �X�N���[�����x��x������
		mNowSpeed = Speed::eDeceleration;   // �^�O���������ɂ���
	}
	// �{�^����������Ă��Ȃ������� ���A�X�N���[�����x���ő呬�x����Ȃ�������
	else if(!CheckHitKey(KEY_INPUT_A) && mMoveSpeed > MMaxSpeed)
	{
		mMoveSpeed += MAcceleration;       // �X�N���[�����x�𑁂�����
		mNowSpeed = Speed::eAcceleration;  // �^�O���������ɂ�
	}

	// �w�i�|�W�V�����̍X�V
	mBackgroundPosY += mMoveSpeed * _deltaTime;
}

void Background::Draw()
{
	// �w�i�̕`��
	DrawGraph(0, (int)mBackgroundPosY, mBackgroundImage, true);
	DrawGraph(0, (int)mBackgroundPosY - MHeight, mBackgroundImage, true);

	// �ꖇ�ڂ̉摜����ʊO�ɍs�����珉���l�ɖ߂�
	if (mBackgroundPosY <= MHeight)
	{
		mBackgroundPosY = 0.0f;
	}
}
