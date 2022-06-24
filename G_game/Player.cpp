// インクルード
#include "Dxlib.h"
#include "PlayScene.h"
#include "Player.h"
#include "BackGround.h"


Player::Player()
{

	//プレイヤーの初期位置の代入
	mPlayerX = FIRSTPOSX;
	mPlayerY = FIRSTPOSY;
	//プレイヤー画像の読み込み
	pImage = LoadGraph("data/assets/Player.png");
	//マウスクリックの初期化
	mMouseClick = FALSE;
	LongPress = FALSE;
}

Player::~Player()
{
}

/// <summary>
/// プレイヤーの描画
/// </summary>
void Player::PlayerDraw()
{
	int StringCr, BoxCr = 0;
	// 画面左上の領域に黒い四角を描き前に描いてあった文字列を消す
	DrawBox(0, 0, 640, 32, BoxCr, TRUE);

	// 白色の値を取得
	StringCr = GetColor(255, 255, 255);
	// 黒の値を取得
	BoxCr = GetColor(0, 0, 0);
	// 座標文字列を描く
	DrawFormatString(0, 0, StringCr, "座標Ｘ %d　　座標Ｙ %d", mMouseX, mMouseY);
	//長押し状態の確認
	DrawFormatString(300, 0, StringCr, "%d　　%d", ClickLog, ClickTmpLog);
	DrawFormatString(500, 0, StringCr, "%d", LongPress);


	DrawGraph(mPlayerX, mPlayerY, pImage, TRUE);
}

void Player::BesidePlayerMove()
{
	/// マウスの座標をとる
	GetMousePoint(&mMouseX, &mMouseY);
	
	/// 画面の左側にカーソルがあり、クリックした場合LeftPosに移動する
	if (mMouseX <= ScreenBeside / 3 && MouseLeftClick())
		mPlayerX = LEFTPOSX;


	/// 画面の真ん中にカーソルがあり、クリックした場合MiddlePosに移動する
	else if ((ScreenBeside / 3 < mMouseX) && (mMouseX <= ScreenBeside * 2 / 3) && MouseLeftClick())
		mPlayerX = MIDDLEPOSX;


	/// 画面の右側にカーソルがあり、クリックした場合LeftPosに移動する
	else if (mMouseX > ScreenBeside * 2/ 3 && MouseLeftClick())
		mPlayerX = RIGHTPOSX;
}

int Player::MouseLeftClick()
{
	//左クリックされたら
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		ClickTmpLog = 1;
		return TRUE;
	}
	//左クリックされなかったら
	else
	{
		ClickTmpLog = 0;
		return FALSE;
	}
}

int  Player::MouseLongPress()
{
	//前フレームと比較する
	if (ClickTmpLog == ClickLog)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Player::PlayerSpeed()
{
	if (MouseLongPress())
	{
		Background::mMoveSpeed;
	}
	ClickLog = ClickTmpLog;
}

void Player::PlayerLandingPreparation()
{
	Background * mBackground = new Background();         // 背景
	if (Background GetTotalLength <= 50&&
		Background * GetTotalLength() > 0)
	{

	}
}

void Player::PlayerLanding()
{
	if (Background::mMoveSpeed == 0)
	{
		mPlayerY += 10;
	}
}

