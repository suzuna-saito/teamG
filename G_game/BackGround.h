#pragma once
// saito

/* �w�i���� */
class Background
{
public:
	// �R���X�g���N�^
	Background();
	// �f�X�g���N�^
	~Background();

	/// <summary>
	/// �w�i�̍X�V����
	/// </summary>
	/// <param name="_deltaTime"></param>
	void Update(float _deltaTime);

	/// <summary>
	/// �w�i�̕`��
	/// </summary>
	void Draw();

private:
	// �萔
	const float MHeight;         // ��ʃT�C�Y(�c)

	// �ϐ�
	int mBackgroundImage;       // �w�i�̃C���[�W�摜
	float mBackgroundPosY;      // �w�i�|�W�V����Y
	float mMoveSpeed;           // �w�i�̈ړ��X�s�[�h
};

