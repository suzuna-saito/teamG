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

/// <summary>
/// プレイヤーの描画
/// </summary>
void Player::PlayerDraw()
{
	char StrBuf[128], StrBuf2[32];
	int StringCr, BoxCr = 0;
	// 画面左上の領域に黒い四角を描き前に描いてあった文字列を消す
	DrawBox(0, 0, 640, 32, BoxCr, TRUE);

	// 白色の値を取得
	StringCr = GetColor(255, 255, 255);
	// 黒の値を取得
	BoxCr = GetColor(0, 0, 0);
	// 座標文字列を描く
	DrawFormatString(0, 0, StringCr, "座標Ｘ %d　　座標Ｙ %d", m_MouseX, m_MouseY);


	DrawGraph(m_PlayerX, m_PlayerY, pImage, TRUE);
}

void Player::PlayerMove()
{
	/// <summary>
	/// マウスの座標をとる
	/// </summary>
	GetMousePoint(&m_MouseX, &m_MouseY);
	
	/// <summary>
	/// 画面の左側にカーソルがあり、クリックした場合LeftPosに移動する
	/// </summary>
	if (m_MouseX <= ScreenBeside / 3 && GetMouseInput()&MOUSE_INPUT_LEFT) 
		m_PlayerX = LeftPosX;

	/// <summary>
	/// 画面の真ん中にカーソルがあり、クリックした場合MiddlePosに移動する
	/// </summary>
	else if ((ScreenBeside / 3 < m_MouseX) && (m_MouseX <= ScreenBeside * 2 / 3) && GetMouseInput() & MOUSE_INPUT_LEFT)
		m_PlayerX = MiddlePosX;

	/// <summary>
	/// 画面の右側にカーソルがあり、クリックした場合LeftPosに移動する
	/// </summary>
	else if (m_MouseX > ScreenBeside * 2/ 3 && GetMouseInput() & MOUSE_INPUT_LEFT)
		m_PlayerX = RightPosX;
}
