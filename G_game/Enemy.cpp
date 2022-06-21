#include "DxLib.h"
#include "Enemy.h"
#include <time.h>
//#include <conio.h>

Enemy::Enemy()
{
	//敵の座標設置
	mEnemyPosiX[0] = 0;   mEnemyPosiY[0] = 1200;
	mEnemyPosiX[1] = 200; mEnemyPosiY[1] = 1000;
	mEnemyPosiX[2] = 0;   mEnemyPosiY[2] = 1500;
	mEnemyPosiX[3] = 420; mEnemyPosiY[3] = 500;
	mEnemyPosiX[4] = 200; mEnemyPosiY[4] = 2000;

	//敵画像の読み込み
	mEnemy1Image = LoadGraph("data/assets/Enemy/Enemy1.png");     //敵1
	mEnemy2Image = LoadGraph("data/assets/Enemy/Enemy2.png");     //敵2
	mEnemy3Image = LoadGraph("data/assets/Enemy/Enemy3.png");     //敵3
	mEnemy4Image = LoadGraph("data/assets/Enemy/Enemy4.png");     //敵4
	mEnemy5Image = LoadGraph("data/assets/Enemy/Enemy5.png");     //敵5


	cnt = 0; //cntの初期化
	startTime = clock() / CLOCKS_PER_SEC; //startTimeの定義
	endTime = clock() / CLOCKS_PER_SEC; //endTimeの定義
	totalTime = endTime - startTime; //totalTimeの定義
}

Enemy::~Enemy()
{

	if (mEnemy1Image != -1)
	{
		DeleteGraph(mEnemy1Image);
	}
	mEnemy1Image = -1;

	if (mEnemy2Image != -1)
	{
		DeleteGraph(mEnemy2Image);
	}
	mEnemy2Image = -1;

	if (mEnemy3Image != -1)
	{
		DeleteGraph(mEnemy3Image);
	}
	mEnemy3Image = -1;

	if (mEnemy4Image != -1)
	{
		DeleteGraph(mEnemy4Image);
	}
	mEnemy4Image = -1;

	if (mEnemy5Image != -1)
	{
		DeleteGraph(mEnemy5Image);
	}
	mEnemy5Image = -1;
}

//void Enemy::Update(float _deltaTime)
void Enemy::Update()
{
	//ランダムな値を座標に設定する
	mEnemyPosiY[0] = mEnemyPosiY[0] + GetRand(200) - GetRand(100);
	mEnemyPosiY[1] = mEnemyPosiY[1] + GetRand(300) - GetRand(200);
	mEnemyPosiY[2] = mEnemyPosiY[2] + GetRand(500) - GetRand(400);
	mEnemyPosiY[3] = mEnemyPosiY[3] + GetRand(200) - GetRand(200);
	mEnemyPosiY[4] = mEnemyPosiY[4] + GetRand(600) - GetRand(200);


	for (cnt = 1080; ProcessMessage() == 0 && cnt > -3500; cnt--) { //cntが1080より小さいとき繰り返す
		ClearDrawScreen(); // 裏画面を削除

		DrawGraph(mEnemyPosiX[0], cnt + mEnemyPosiY[0], mEnemy1Image, TRUE); // 座標に敵1を描画
		DrawGraph(mEnemyPosiX[1], cnt + mEnemyPosiY[1], mEnemy2Image, TRUE); // 座標に敵2を描画
		DrawGraph(mEnemyPosiX[2], cnt + mEnemyPosiY[2], mEnemy3Image, TRUE); // 座標に敵3を描画
		DrawGraph(mEnemyPosiX[3], cnt + mEnemyPosiY[3], mEnemy4Image, TRUE); // 座標に敵4を描画
		DrawGraph(mEnemyPosiX[4], cnt + mEnemyPosiY[4], mEnemy5Image, TRUE); // 座標に敵5を描画
		cnt = cnt - 5; //移動速度

		ScreenFlip();// 描画結果を表示
	}
}

void Enemy::Draw()
{
	//// 敵１の描画
	//DrawGraph((int)mEnemyPosX, (int)mEnemyPosY, mEnemy1Image, TRUE);

	//// 敵２の描画
	//DrawGraph((int)mEnemyPosX, (int)mEnemyPosY, mEnemy2Image, TRUE);

	//// 敵３の描画
	//DrawGraph((int)mEnemyPosX, (int)mEnemyPosY, mEnemy3Image, TRUE);

	//// 敵４の描画
	//DrawGraph((int)mEnemyPosX, (int)mEnemyPosY, mEnemy4Image, TRUE);

	//// 敵５の描画
	//DrawGraph((int)mEnemyPosX, (int)mEnemyPosY, mEnemy5Image, TRUE);
}

//画像にx,yをセットする
void Enemy::SetPosition(int x, int y)
{
	/*mEnemyPosX = x;
	mEnemyPosY = y;*/
}

//ファイルに画像をロード
void Enemy::Set1Image(const char* fileName)
{
	mEnemy1Image = LoadGraph(fileName);
}
void Enemy::Set2Image(const char* fileName)
{
	mEnemy2Image = LoadGraph(fileName);
}
void Enemy::Set3Image(const char* fileName)
{
	mEnemy3Image = LoadGraph(fileName);
}
void Enemy::Set4Image(const char* fileName)
{
	mEnemy4Image = LoadGraph(fileName);
}
void Enemy::Set5Image(const char* fileName)
{
	mEnemy5Image = LoadGraph(fileName);
}