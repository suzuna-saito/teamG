// インクルード
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"

Player::Player() :m_PlayerX(0), m_PlayerY(0), m_MouseX(0), m_MouseY(0)
{

	//プレイヤーの初期位置の代入
	m_PlayerX = FirstPosX;
	m_PlayerY = FirstPosY;
	//プレイヤー画像の読み込み
	pImage = LoadGraph("data/assets/Player.png");
}

Player::~Player()
{
}

void Player::FirstPostion()
{
	m_PlayerX = FirstPosX;
	m_PlayerY = FirstPosY;
}

void Player::PlayerDraw()
{
	DrawGraph(m_PlayerX, m_PlayerY, pImage, TRUE);
}

void Player::PlayerMove()
{
	GetMousePoint(&m_MouseX, &m_MouseY);
	if (m_MouseX <= ScreenBeside / 3)
		m_PlayerX = LeftPosX;
	else if ((ScreenBeside / 3 < m_MouseX) && (m_MouseX <= ScreenBeside * 2 / 3))
		m_PlayerX = MiddlePosX;
	else
		m_PlayerX = RightPosX;
}
