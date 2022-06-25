// �C���N���[�h
#include "TitleScene.h"
#include "LoadScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
	: SceneBase(SceneBase::Scene::eTitle)
	, MCollisionLeftX(50)
	, MCollisionRightX(600)
	, MCollisionLeftY(60)
	, MCollisionRightY(190)
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
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Button.png"));    // ���ʂ̃{�^��
	mImages.emplace_back(LoadGraph("data/assets/TitleScene/Button2.png"));   // �J�[�\���������Ă鎞�̃{�^��

	// �|�W�V�����̐ݒ�
	mPos.emplace_back(VGet(0.0f, 0.0f, 0.0f));     // �w�i
	mPos.emplace_back(VGet(0.0f, 0.0f, 0.0f));     // ����
	mPos.emplace_back(VGet(450.0f, -50.0f, 0.0f)); // ��
	mPos.emplace_back(VGet(0.0f, 580.0f, 0.0f));   // start�{�^��
	mPos.emplace_back(VGet(0.0f, 810.0f, 0.0f));   // score�{�^��
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
	// �}�E�X�J�[�\����start�ɂ����Ă邩�A�N���b�N�{�^���������ꂽ��
	if (mNowCursorPos == CursorPos::eStart && 
		(GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		// �u�����h���[�h���m�[�u�����h�ɖ߂�
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// �����𖞂����Ă�����v���C�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new LoadScene(Scene::ePlay);
	}

	// �}�E�X�J�[�\�����{�^���ɂ����Ă��邩
	GetMousePoint(&mMousePosX, &mMousePosY);  // �}�E�X�̈ʒu���擾
	// Start�{�^���̘g���Ƀ}�E�X�J�[�\���������
	if (mMousePosX > mPos[eButton].x + MCollisionLeftX && mMousePosX < mPos[eButton].x + MCollisionRightX &&
		mMousePosY > mPos[eButton].y + MCollisionLeftY && mMousePosY < mPos[eButton].y + MCollisionRightY)
	{
		mNowCursorPos = CursorPos::eStart;    // �^�C�v��eStart�ɕύX
	}
	// Score�{�^���̘g���Ƀ}�E�X�J�[�\���������
	else if (mMousePosX > mPos[eButton2].x + MCollisionLeftX && mMousePosX < mPos[eButton2].x + MCollisionRightX &&
		mMousePosY > mPos[eButton2].y + MCollisionLeftY && mMousePosY < mPos[eButton2].y + MCollisionRightY)
	{
		mNowCursorPos = CursorPos::eScore;    // �^�C�v��eScore�ɕύX 
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

	DrawButton();                                                                                         // �{�^��

	DrawGraph((int)mPos[Image::eChar].x, (int)mPos[Image::eChar].y, mImages[Image::eChar], TRUE);         // ����

	// �u�����h���[�h�����u�����h�ɂ���i�����x��ς���j
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,mAlpha);
	DrawGraph((int)mPos[Image::eSmoke].x, (int)mPos[Image::eSmoke].y, mImages[Image::eSmoke], TRUE);      // ��
}

void TitleScene::DrawButton()
{
	// �}�E�X�J�[�\����Start�ɂ����Ă�����
	if (mNowCursorPos == CursorPos::eStart)
	{
		DrawGraph((int)mPos[Image::eButton].x, (int)mPos[Image::eButton].y, mImages[Image::eButton2], TRUE);   // start�{�^��(���邭�`��)
		DrawGraph((int)mPos[Image::eButton2].x, (int)mPos[Image::eButton2].y, mImages[Image::eButton], TRUE);  // score�{�^��
	}
	// �}�E�X�J�[�\����Score�ɂ����Ă�����
	else if (mNowCursorPos == CursorPos::eScore)
	{
		DrawGraph((int)mPos[Image::eButton].x, (int)mPos[Image::eButton].y, mImages[Image::eButton], TRUE);   // start�{�^��
		DrawGraph((int)mPos[Image::eButton2].x, (int)mPos[Image::eButton2].y, mImages[Image::eButton2], TRUE);  // score�{�^��(���邭�`��)
	}
	else
	{
		DrawGraph((int)mPos[Image::eButton].x, (int)mPos[Image::eButton].y, mImages[Image::eButton], TRUE);    // start�{�^��
		DrawGraph((int)mPos[Image::eButton2].x, (int)mPos[Image::eButton2].y, mImages[Image::eButton], TRUE);  // score�{�^��
	}
}
