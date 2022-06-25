// �C���N���[�h
#include "TitleScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
	: SceneBase(SceneBase::Scene::eTitle)
	, MMinAlpha(100)
	, MMaxAlpha(225)
	, mMousePosX(0)
	, mMousePosY(0)
	, mNowCursorPos(CursorPos::eNone)
	, mAlpha(MMinAlpha)
	, mChangeSpeed(2)
{
	// �^�C�g���摜�̓ǂݍ���(��)
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Back.png"));      // �w�i
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Char.png"));      // ����
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Smoke.png"));     // ��
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Button.png"));    // �{�^��
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Button2.png"));   // �J�[�\���������Ă鎞�̃{�^��

	// �|�W�V�����̐ݒ�
	mPos.emplace_back(VGet(0.0f, 0.0f, 0.0f));     // �w�i
	mPos.emplace_back(VGet(0.0f, 0.0f, 0.0f));     // ����
	mPos.emplace_back(VGet(450.0f, -50.0f, 0.0f)); // ��
	mPos.emplace_back(VGet(0.0f, 580.0f, 0.0f));   // �{�^��
	mPos.emplace_back(VGet(0.0f, 810.0f, 0.0f));   // �{�^��2
}

TitleScene::~TitleScene()
{
	// �x�N�^�[�^�ɕۑ����Ă���摜��S�ď���
	for (auto image : mImages)
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

	// �}�E�X�J�[�\�����{�^���ɂ����Ă��邩
	GetMousePoint(&mMousePosX, &mMousePosY);  // �}�E�X�̈ʒu���擾
	if (mMousePosX > mPos[eButton].x + 50 && mMousePosX < mPos[eButton].x + 600 &&
		mMousePosY > mPos[eButton].y + 60 && mMousePosY < mPos[eButton].y + 190)
	{
		mNowCursorPos = CursorPos::eStart;
	}
	else
	{
		mNowCursorPos = CursorPos::eNone;
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
	DrawGraph((int)mPos[Image::eBack].x, (int)mPos[Image::eBack].y, mImages[Image::eBack], TRUE);         // �w�i

	if (mNowCursorPos == CursorPos::eStart)
	{
		DrawGraph((int)mPos[Image::eButton].x, (int)mPos[Image::eButton].y, mImages[Image::eButton2], TRUE);   // �{�^��
	}
	else
	{
		DrawGraph((int)mPos[Image::eButton].x, (int)mPos[Image::eButton].y, mImages[Image::eButton], TRUE);   // �{�^��
	}

	//DrawGraph((int)mPos[Image::eButton2].x, (int)mPos[Image::eButton2].y, mImages[Image::eButton], TRUE); // �{�^��2

	DrawGraph((int)mPos[Image::eChar].x, (int)mPos[Image::eChar].y, mImages[Image::eChar], TRUE);         // ����

	// �u�����h���[�h�����u�����h�ɂ���i�����x��ς���j
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,mAlpha);
	DrawGraph((int)mPos[Image::eSmoke].x, (int)mPos[Image::eSmoke].y, mImages[Image::eSmoke], TRUE);  // ��



	////////////// �f�o�b�O
	unsigned int Cr;

	Cr = GetColor(0, 0, 0);    // ���F�̒l���擾

	DrawLine(mPos[eButton].x+50, 640, mPos[eButton].x + 600, 770, Cr);    // ����`��
}
