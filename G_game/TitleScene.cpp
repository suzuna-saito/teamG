// �C���N���[�h
#include "TitleScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
	: SceneBase(SceneBase::Scene::eTitle)
	, MMinAlpha(120)
	, MMaxAlpha(225)
	, mAlpha(MMinAlpha)
	, mChangeSpeed(1)
{
	// �^�C�g���摜�̓ǂݍ���(��)
	mImage = LoadGraph("data/assets/TitleScene/Back.png");  // ��
	mOtherImage.emplace_back(LoadGraph("data/assets/TitleScene/TitleChar.png")); // �^�C�g������
	mOtherImage.emplace_back(LoadGraph("data/assets/TitleScene/Smoke.png"));     // ��

	// �|�W�V�����̐ݒ�
	mPos.emplace_back(VGet(0.0f, 60.0f, 0.0f));    // �^�C�g������
	mPos.emplace_back(VGet(450.0f, -50.0f, 0.0f)); // ��
}

TitleScene::~TitleScene()
{
	DeleteGraph(mImage);

	// �x�N�^�[�^�ɕۑ����Ă���摜��S�ď���
	for (auto image : mOtherImage)
	{
		DeleteGraph(image);
	}
}

SceneBase* TitleScene::Update(float _deltaTime)
{
	// �V�[���J�ڏ���(�G���^�[�������ƑJ�ځi���j)
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		// �u�����h���[�h���m�[�u�����h�ɖ߂��Ď��̃V�[���ɍs��
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// �����𖞂����Ă�����v���C�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new PlayScene();
	}

	// ���̓����x��ς���
	if (mAlpha > MMaxAlpha ||    // ���̓����x���ő����ɂȂ����� �܂���
		mAlpha < MMinAlpha)      // ���̓����x���ŏ������ɂȂ�����
	{
		mChangeSpeed *= -1;      // �����x�̕ω��l�̕�����ς���
	}

	// �����x��ς���
	mAlpha += mChangeSpeed;


	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void TitleScene::Draw()
{
	// �^�C�g���̕`��
	// �u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph(0, 0, mImage, TRUE);                                    // ��
	DrawGraph(0, (int)mPos[0].y, mOtherImage[0], TRUE);               // �^�C�g������

	// �u�����h���[�h�����u�����h�ɂ���i�����x��ς���j
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,mAlpha);
	DrawGraph((int)mPos[1].x, (int)mPos[1].y, mOtherImage[1], TRUE);  // ��
}
