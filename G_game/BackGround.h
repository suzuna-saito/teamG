#pragma once
// saito

/* �w�i���� */
class Background
{
public:

	// �X�s�[�h�̃^�O
	enum class Speed :unsigned char
	{
		eAcceleration,  // ������
		eDeceleration,  // ������
	};

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

	// �ÓI�����o�ϐ�
	static Speed mNowSpeed;      // ���݂̃X�s�[�h��
	static float mMoveSpeed;     // �w�i�̈ړ��X�s�[�h

private:
	// �萔
	const float MHeight;         // ��ʃT�C�Y(�c)
	const float MAcceleration;   // �w�i�̉����X�s�[�h
	const float MDeceleration;   // �w�i�̌����X�s�[�h
	const float MMaxSpeed;       // �ő�X�s�[�h
	const float MMinSpeed;       // �ŏ��X�s�[�h

	// �ϐ�
	int mBackgroundImage;       // �w�i�̃C���[�W�摜
	float mBackgroundPosY;      // �w�i�|�W�V����Y
};

