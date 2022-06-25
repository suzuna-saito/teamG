#include "DxLib.h"
#include "Enemy.h"
#include <time.h>
//#include <conio.h>

Enemy::Enemy()
{
	//“G‚ÌÀ•Wİ’u
	mEnemyPosiX[0] = 0;   mEnemyPosiY[0] = 1500;
	mEnemyPosiX[1] = 200; mEnemyPosiY[1] = 1800;
	mEnemyPosiX[2] = 0;   mEnemyPosiY[2] = 2500;
	mEnemyPosiX[3] = 420; mEnemyPosiY[3] = 4000;
	mEnemyPosiX[4] = 200; mEnemyPosiY[4] = 2000;

	//“G‰æ‘œ‚Ì“Ç‚İ‚İ
	mEnemy1Image = LoadGraph("data/assets/Enemy/Enemy1.png");     //“G1
	mEnemy2Image = LoadGraph("data/assets/Enemy/Enemy2.png");     //“G2
	mEnemy3Image = LoadGraph("data/assets/Enemy/Enemy3.png");     //“G3
	mEnemy4Image = LoadGraph("data/assets/Enemy/Enemy4.png");     //“G4
	mEnemy5Image = LoadGraph("data/assets/Enemy/Enemy5.png");     //“G5


	cnt[0] = 0; //cnt[0]‚Ì‰Šú‰»
	cnt[1] = 0; //cnt[1]‚Ì‰Šú‰»
	cnt[2] = 0; //cnt[2]‚Ì‰Šú‰»
	cnt[3] = 0; //cnt[3]‚Ì‰Šú‰»
	cnt[4] = 0; //cnt[4]‚Ì‰Šú‰»
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

	if (cnt[0] + mEnemyPosiY[0] < -200) //“G‚P‚ª‰æ–ÊŠO‚És‚Á‚½‚ç
	{
		mEnemyPosiY[0] = 1500; //V‚½‚ÈÀ•W‚ğİ’è
		//mEnemyPosiY[0] = mEnemyPosiY[0] + GetRand(200) - GetRand(100);
		cnt[0] = 0; //cnt‚Ì‰Šú‰»
		cnt[0] = cnt[0] - 5; //ˆÚ“®‘¬“x
	}

	if (cnt[1] + mEnemyPosiY[1] < -200) //“G2‚ª‰æ–ÊŠO‚És‚Á‚½‚ç
	{
		mEnemyPosiY[1] = 1800; //V‚½‚ÈÀ•W‚ğİ’è
		//mEnemyPosiY[1] = mEnemyPosiY[1] + GetRand(300) - GetRand(200);
		cnt[1] = 0; //cnt‚Ì‰Šú‰»
		cnt[1] = cnt[1] - 5; //ˆÚ“®‘¬“x
	}

	if (cnt[2] + mEnemyPosiY[2] < -200) //“G3‚ª‰æ–ÊŠO‚És‚Á‚½‚ç
	{
		mEnemyPosiY[2] = 1500; //V‚½‚ÈÀ•W‚ğİ’è
		//mEnemyPosiY[2] = mEnemyPosiY[2] + GetRand(500) - GetRand(400);
		cnt[2] = 0; //cnt‚Ì‰Šú‰»
		cnt[2] = cnt[2] - 5; //ˆÚ“®‘¬“x
	}

	if (cnt[3] + mEnemyPosiY[3] < -200) //“G4‚ª‰æ–ÊŠO‚És‚Á‚½‚ç
	{
		mEnemyPosiY[3] = 4000; //V‚½‚ÈÀ•W‚ğİ’è
		//mEnemyPosiY[3] = mEnemyPosiY[3] + GetRand(200) - GetRand(200);
		cnt[3] = 0; //cnt‚Ì‰Šú‰»
		cnt[3] = cnt[3] - 5; //ˆÚ“®‘¬“x
	}

	if (cnt[4] + mEnemyPosiY[4] < -200) //“G5‚ª‰æ–ÊŠO‚És‚Á‚½‚ç
	{
		mEnemyPosiY[4] = 2000; //V‚½‚ÈÀ•W‚ğİ’è
		//mEnemyPosiY[4] = mEnemyPosiY[4] + GetRand(600) - GetRand(200);
		cnt[4] = 0; //cnt‚Ì‰Šú‰»
		cnt[4] = cnt[4] - 5; //ˆÚ“®‘¬“x
	}

}

void Enemy::Draw()
{
	DrawGraph(mEnemyPosiX[0], cnt[0] + mEnemyPosiY[0], mEnemy1Image, TRUE); // À•W‚É“G1‚ğ•`‰æ
	DrawGraph(mEnemyPosiX[1], cnt[1] + mEnemyPosiY[1], mEnemy2Image, TRUE); // À•W‚É“G2‚ğ•`‰æ
	DrawGraph(mEnemyPosiX[2], cnt[2] + mEnemyPosiY[2], mEnemy3Image, TRUE); // À•W‚É“G3‚ğ•`‰æ
	DrawGraph(mEnemyPosiX[3], cnt[3] + mEnemyPosiY[3], mEnemy4Image, TRUE); // À•W‚É“G4‚ğ•`‰æ
	DrawGraph(mEnemyPosiX[4], cnt[4] + mEnemyPosiY[4], mEnemy5Image, TRUE); // À•W‚É“G5‚ğ•`‰æ

	//ˆÚ“®‘¬“x
	cnt[0] = cnt[0] - 5; //“G1
	cnt[1] = cnt[1] - 5; //“G2
	cnt[2] = cnt[2] - 5; //“G3
	cnt[3] = cnt[3] - 5; //“G4
	cnt[4] = cnt[4] - 5; //“G5

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