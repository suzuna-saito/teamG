#include "DxLib.h"
#include "Enemy.h"
#include <time.h>
//#include <conio.h>

Enemy::Enemy()
{
	//“G‚ÌÀ•Wİ’u
	mEnemyPosiX[0] = 0;   mEnemyPosiY[0] = 1200;
	mEnemyPosiX[1] = 200; mEnemyPosiY[1] = 1000;
	mEnemyPosiX[2] = 0;   mEnemyPosiY[2] = 1500;
	mEnemyPosiX[3] = 420; mEnemyPosiY[3] = 500;
	mEnemyPosiX[4] = 200; mEnemyPosiY[4] = 2000;

	//“G‰æ‘œ‚Ì“Ç‚İ‚İ
	mEnemy1Image = LoadGraph("data/assets/Enemy/Enemy1.png");     //“G1
	mEnemy2Image = LoadGraph("data/assets/Enemy/Enemy2.png");     //“G2
	mEnemy3Image = LoadGraph("data/assets/Enemy/Enemy3.png");     //“G3
	mEnemy4Image = LoadGraph("data/assets/Enemy/Enemy4.png");     //“G4
	mEnemy5Image = LoadGraph("data/assets/Enemy/Enemy5.png");     //“G5


	cnt = 0; //cnt‚Ì‰Šú‰»
	startTime = clock() / CLOCKS_PER_SEC; //startTime‚Ì’è‹`
	endTime = clock() / CLOCKS_PER_SEC; //endTime‚Ì’è‹`
	totalTime = endTime - startTime; //totalTime‚Ì’è‹`
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
	//ƒ‰ƒ“ƒ_ƒ€‚È’l‚ğÀ•W‚Éİ’è‚·‚é
	mEnemyPosiY[0] = mEnemyPosiY[0] + GetRand(200) - GetRand(100);
	mEnemyPosiY[1] = mEnemyPosiY[1] + GetRand(300) - GetRand(200);
	mEnemyPosiY[2] = mEnemyPosiY[2] + GetRand(500) - GetRand(400);
	mEnemyPosiY[3] = mEnemyPosiY[3] + GetRand(200) - GetRand(200);
	mEnemyPosiY[4] = mEnemyPosiY[4] + GetRand(600) - GetRand(200);


	for (cnt = 1080; ProcessMessage() == 0 && cnt > -3500; cnt--) { //cnt‚ª1080‚æ‚è¬‚³‚¢‚Æ‚«ŒJ‚è•Ô‚·
		ClearDrawScreen(); // — ‰æ–Ê‚ğíœ

		DrawGraph(mEnemyPosiX[0], cnt + mEnemyPosiY[0], mEnemy1Image, TRUE); // À•W‚É“G1‚ğ•`‰æ
		DrawGraph(mEnemyPosiX[1], cnt + mEnemyPosiY[1], mEnemy2Image, TRUE); // À•W‚É“G2‚ğ•`‰æ
		DrawGraph(mEnemyPosiX[2], cnt + mEnemyPosiY[2], mEnemy3Image, TRUE); // À•W‚É“G3‚ğ•`‰æ
		DrawGraph(mEnemyPosiX[3], cnt + mEnemyPosiY[3], mEnemy4Image, TRUE); // À•W‚É“G4‚ğ•`‰æ
		DrawGraph(mEnemyPosiX[4], cnt + mEnemyPosiY[4], mEnemy5Image, TRUE); // À•W‚É“G5‚ğ•`‰æ
		cnt = cnt - 5; //ˆÚ“®‘¬“x

		ScreenFlip();// •`‰æŒ‹‰Ê‚ğ•\¦
	}
}

void Enemy::Draw()
{
	//// “G‚P‚Ì•`‰æ
	//DrawGraph((int)mEnemyPosX, (int)mEnemyPosY, mEnemy1Image, TRUE);

	//// “G‚Q‚Ì•`‰æ
	//DrawGraph((int)mEnemyPosX, (int)mEnemyPosY, mEnemy2Image, TRUE);

	//// “G‚R‚Ì•`‰æ
	//DrawGraph((int)mEnemyPosX, (int)mEnemyPosY, mEnemy3Image, TRUE);

	//// “G‚S‚Ì•`‰æ
	//DrawGraph((int)mEnemyPosX, (int)mEnemyPosY, mEnemy4Image, TRUE);

	//// “G‚T‚Ì•`‰æ
	//DrawGraph((int)mEnemyPosX, (int)mEnemyPosY, mEnemy5Image, TRUE);
}

//‰æ‘œ‚Éx,y‚ğƒZƒbƒg‚·‚é
void Enemy::SetPosition(int x, int y)
{
	/*mEnemyPosX = x;
	mEnemyPosY = y;*/
}

//ƒtƒ@ƒCƒ‹‚É‰æ‘œ‚ğƒ[ƒh
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