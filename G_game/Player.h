#pragma once

// インクルード
#include "DxLib.h"
#include "Background.h"

//プレイヤークラス
class Player
{
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();


	/// プレイヤーの描画
	void PlayerDraw();

	/// プレイヤーの横移動
	void BesidePlayerMove();
	///プレイヤーの速度変更
	
	//マウスの左クリック管理
	int MouseLeftClick();

	//マウスの長押し管理
	int MouseLongPress();

	//左クリック長押し処理
	void PlayerSpeed();

	void PlayerLandingPreparation();
	void PlayerLanding();

private:
	int mMouseX;			//マウスのX座標
	int mMouseY;			//マウスのY座標
	int pImage;				//プレイヤーの画像
	int mPlayerX;			//プレイヤーのX座標
	int mPlayerY;			//プレイヤーのY座標
	bool mMouseClick;		//マウスで左クリックされたか
	bool ClickLog;
	bool ClickTmpLog;
	bool LongPress;
	class Background* mBackground;   // 背景クラス

	//プレイヤーの初期位置
	const int FIRSTPOSX = 275;
	const int FIRSTPOSY = 250;
	
	//プレイヤーの移動位置
	const int LEFTPOSX = 62;
	const int MIDDLEPOSX = 275;
	const int RIGHTPOSX = 457;

};