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

	//着地の速度を背景速度から取ってくる
	void PlayerLandingPreparation(float _deltaTime);

	//着地
	void PlayerLanding();

private:
	int mMouseX;			//マウスのX座標
	int mMouseY;			//マウスのY座標
	int pImage;				//プレイヤーの画像
	int mPlayerX;			//プレイヤーのX座標
	int mPlayerY;			//プレイヤーのY座標
	int mLandDis;			//地面までの距離
	float mLandingSpeed;		//着地速度
	bool mMouseClick;		//マウスで左クリックされたか
	bool mClickLog;			//マウスが前フレームで押されているか
	bool mClickTmpLog;		//マウスが今フレームで押されているか

	class Background* mBackground;   // 背景クラス

	//プレイヤーの初期位置
	const int FIRSTPOSX = 275;
	const int FIRSTPOSY = 250;
	
	//プレイヤーの移動位置
	const int LEFTPOSX = 62;
	const int MIDDLEPOSX = 275;
	const int RIGHTPOSX = 457;

	const int BEFORELANDING = 1;//着陸1m前
};