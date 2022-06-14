//-----------------------------------------------------------------------------
// @brief  ���C������.
// 2022 Team G(�ύX��)
//-----------------------------------------------------------------------------

// �C���N���[�h
#include "DxLib.h"
#include "SceneBase.h"
#include "TitleScene.h"

//-----------------------------------------------------------------------------
// @brief  ���C���֐�.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(650, 1080, 16);
	ChangeWindowMode(TRUE);

	// DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		// �G���[���N�����璼���ɏI��
		return -1;
	}

	// �f���^�^�C���Ǘ��p�̕ϐ����Z�b�g
	LONGLONG nowTime;
	LONGLONG time;
	float deltaTime;

	// �V�X�e�����Ԃ��擾
	time = GetNowHiPerformanceCount();

	//	�ŏ��̌o�ߎ��Ԃ͉���0.0000001f�b�ɂ��Ă���
	deltaTime = 0.000001f;

	// ���݂̃V�[���𐶐�
	SceneBase* nowScene = new TitleScene();

	// Esc�L�[��������邩�A�E�B���h�E��������܂Ń��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �V�[���̍X�V����
		// Update�̖߂�l�Ŏ��̃V�[���̃|�C���^���Ԃ��Ă���
		// tmpScene�ɕԂ��Ă����V�[���̃|�C���^����
		SceneBase* tmpScene = nowScene->Update(deltaTime);

		// nowScene(����)��tmpScene���قȂ��Ă�����
		if (nowScene != tmpScene)
		{
			// ���݂̃V�[�������
			delete nowScene;
			// nowScene��tmpScene����
			nowScene = tmpScene;
		}

		// ��ʂ�����������
		ClearDrawScreen();

		// ���݂̃V�[����`��
		nowScene->Draw();

		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();

		// ���݂̃V�X�e�����Ԃ��擾
		nowTime = GetNowHiPerformanceCount();

		// �O��擾�������Ԃ���̌o�ߎ��Ԃ�b�ɕϊ����ăZ�b�g
		// ( GetNowHiPerformanceCount �Ŏ擾�ł���l�̓}�C�N���b�P�ʂȂ̂� 1000000 �Ŋ��邱�Ƃŕb�P�ʂɂȂ� )
		deltaTime = (nowTime - time) / 1000000.0f;

		// ����擾�������Ԃ�ۑ�
		time = nowTime;
	}

	// �V�[���̍폜
	delete nowScene;
	// DX���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}