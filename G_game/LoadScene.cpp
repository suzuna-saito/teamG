// �C���N���[�h
#include "LoadScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "PlayScene.h"

LoadScene::LoadScene(Scene _nextScene)
	: SceneBase(SceneBase::Scene::eLoad)
	, MSecond(5000)
	, MHalfSecond(500)
	, mStartTime(GetNowCount())
	, MInitWidthSize(220)
	, MDrawExpansion(35)
	, MMaxWidthSize(MInitWidthSize + MDrawExpansion * 3)
	, MDrawHeight(190)
	, MRightPosX(150)
	, MRightPosY(250)
	, MMaxKoyakeSizeY(20)
	, MMinKoyakeSizeY(0)
	, mDrawWidth(MInitWidthSize)
	, mSize(MMinKoyakeSizeY)
	, mChangeSize(1)
	, mWeitTime(500)
{
	// ���[�h�摜�̓ǂݍ���(��)
	mImages.emplace_back(LoadGraph("data/assets/LoadScene/Load.png"));      // ����
	mImages.emplace_back(LoadGraph("data/assets/LoadScene/Koyake.png"));    // �L�����N�^�[

	// �|�W�V�����̐ݒ�
	mPos.emplace_back(VGet(280.0f, 850.0f, 0.0f)); // ����
	mPos.emplace_back(VGet(450.0f, 550.0f, 0.0f)); // �L�����N�^�[

	// ���̃V�[���̃^�C�v
	mNextSceneType = _nextScene;
}

LoadScene::~LoadScene()
{
	// �x�N�^�[�^�ɕۑ����Ă���摜��S�ď���
	for (auto image : mImages)
	{
		DeleteGraph(image);
	}
}

SceneBase* LoadScene::Update(float _deltaTime)
{
	// ���[�h��ʂɓ����Ďw��̕b����������
	if (GetNowCount() - mStartTime >= MSecond)
	{
		// mNextSceneType�ɂ���āA���̃V�[���𐶐�
		if (mNextSceneType == Scene::eTitle)
		{
			return new TitleScene();
		}
		else if (mNextSceneType == Scene::ePlay)
		{
			return new PlayScene();
		}
		else if (mNextSceneType == Scene::eResult)
		{
			return new ResultScene();
		}
	}

	// �`�悷���`�T�C�Y�̕ύX(loading)
	if (mDrawWidth <= MMaxWidthSize)  // �`�悷���`�T�C�Y���ő�܂ł����ĂȂ�������
	{
		if (GetNowCount() - mStartTime >= mWeitTime) // 0.5�b��������
		{
			mDrawWidth += MDrawExpansion;  // �`��T�C�Y��傫������

			mWeitTime += MHalfSecond;      // �X�V��҂��Ԃ�0.5�b���₷ 
		}
	}
	else
	{
		mDrawWidth = MInitWidthSize;   // �����T�C�Y�ɖ߂�
	}

	// �L�����N�^�[�̃T�C�Y��ς���(koyake)
	if (mSize > MMaxKoyakeSizeY ||    // ���̃T�C�Y���ő����ɂȂ����� �܂���
		mSize < MMinKoyakeSizeY)      // ���̃T�C�Y���ŏ������ɂȂ�����
	{
		mChangeSize *= -1;            // �T�C�Y�ω��l�̕�����ς���
	}

	// �T�C�Y��ς���
	mSize += mChangeSize;
	
	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return this;
}

void LoadScene::Draw()
{
	// �w���`�����̂ݕ`��iloading�j
	DrawRectGraph((int)mPos[loadImage::eChar].x, (int)mPos[loadImage::eChar].y,0, 0,
		mDrawWidth, MDrawHeight,mImages[loadImage::eChar], TRUE, FALSE);
	// �g��k���`��(koyake)
	DrawExtendGraph(
		(int)mPos[loadImage::eKoyake].x, (int)mPos[loadImage::eKoyake].y - mSize,                    // ����
		(int)mPos[loadImage::eKoyake].x + MRightPosX, (int)mPos[loadImage::eKoyake].y + MRightPosY,  // �E��
		mImages[loadImage::eKoyake], TRUE);

}
