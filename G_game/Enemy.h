#pragma once
//yoshihara

class Enemy
{
public:
	// �R���X�g���N�^
	Enemy();
	// �f�X�g���N�^
	~Enemy();

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	/// <param name="_deltaTime"></param>
	//void Update(float _deltaTime);
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �Z�b�g����|�W�V����
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void SetPosition(int x, int y);

	/// <summary>
	/// �摜�P
	/// </summary>
	/// <param name="fileName"></param>
	void Set1Image(const char* fileName);

	/// <summary>
	/// �摜�Q
	/// </summary>
	/// <param name="fileName"></param>
	void Set2Image(const char* fileName);

	/// <summary>
	/// �摜�R
	/// </summary>
	/// <param name="fileName"></param>
	void Set3Image(const char* fileName);

	/// <summary>
	/// �摜�S
	/// </summary>
	/// <param name="fileName"></param>
	void Set4Image(const char* fileName);

	/// <summary>
	/// �摜�T
	/// </summary>
	/// <param name="fileName"></param>
	void Set5Image(const char* fileName);

private:
	//�萔
	int cnt; //�`��ړ�
	//�ϐ�
	float mEnemyPosiX[5];      // �G�|�W�V����X
	float mEnemyPosiY[5];      // �G�|�W�V����Y


protected:
	int mEnemy1Image;       // �G�P�̃C���[�W�摜
	int mEnemy2Image;       // �G�Q�̃C���[�W�摜
	int mEnemy3Image;       // �G�R�̃C���[�W�摜
	int mEnemy4Image;       // �G�S�̃C���[�W�摜
	int mEnemy5Image;       // �G�T�̃C���[�W�摜

	double startTime, endTime; //start���Ԃ�end����
	double totalTime = 0.0, setTime = 40.0; //total���Ԃ�set����
};
