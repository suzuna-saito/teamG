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
		eLanding,       // ���n
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
	static Speed mNowSpeedType;  // ���݂̃X�s�[�h��
	static float mMoveSpeed;     // �w�i�̈ړ��X�s�[�h

private:
	// �萔
	const int MAdjustmentLength; // �����̔������l
	const int MHeight;           // ��ʃT�C�Y(�c)
	const float MAcceleration;   // �w�i�̉����X�s�[�h
	const float MDeceleration;   // �w�i�̌����X�s�[�h
	const float MMaxSpeed;       // �ő�X�s�[�h
	const float MMinSpeed;       // �ŏ��X�s�[�h

	const int MScrollNum;       // �X�N���[�����~�߂�^�C�~���O��

	// �ϐ�
	int mTotalLength;           // ���v�̒���
	int mBackgroundImage;       // �w�i�̃C���[�W�摜
	int mEndBackgroundImage;    // ��ԉ��̔w�i�̃C���[�W�摜
	float mBackgroundPosY;      // �w�i�|�W�V����Y

	int mScrollCount;           // �X�N���[�����J��Ԃ����񐔃J�E���g
	bool mEndFlag;              // ���n�n�_�܂Ŕw�i��`�悵�����ǂ���

public:  // �Q�b�^�[�A�Z�b�^�[
	// ���v�̒������擾
	int GetTotalLength() { return mTotalLength; }
};

