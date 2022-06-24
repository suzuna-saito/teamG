#pragma once

// �C���N���[�h
#include "DxLib.h"
#include "Background.h"

//�v���C���[�N���X
class Player
{
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();


	/// �v���C���[�̕`��
	void PlayerDraw();

	/// �v���C���[�̉��ړ�
	void BesidePlayerMove();
	///�v���C���[�̑��x�ύX
	
	//�}�E�X�̍��N���b�N�Ǘ�
	int MouseLeftClick();

	//�}�E�X�̒������Ǘ�
	int MouseLongPress();

	//���N���b�N����������
	void PlayerSpeed();

	void PlayerLandingPreparation();
	void PlayerLanding();

private:
	int mMouseX;			//�}�E�X��X���W
	int mMouseY;			//�}�E�X��Y���W
	int pImage;				//�v���C���[�̉摜
	int mPlayerX;			//�v���C���[��X���W
	int mPlayerY;			//�v���C���[��Y���W
	bool mMouseClick;		//�}�E�X�ō��N���b�N���ꂽ��
	bool ClickLog;
	bool ClickTmpLog;
	bool LongPress;
	class Background* mBackground;   // �w�i�N���X

	//�v���C���[�̏����ʒu
	const int FIRSTPOSX = 275;
	const int FIRSTPOSY = 250;
	
	//�v���C���[�̈ړ��ʒu
	const int LEFTPOSX = 62;
	const int MIDDLEPOSX = 275;
	const int RIGHTPOSX = 457;

};