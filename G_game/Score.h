#pragma once
// saito

/* �X�R�A�̏��� */
class Score
{
public:
	// �R���X�g���N�^
	Score();
	// �f�X�g���N�^
	~Score();

	// �C���X�^���X�𐶐�����
	static void CreateInstance();
	// �C���X�^���X���폜����
	static void DeleteInstance();

	/// <summary>
	/// �X�R�A�̍X�V����
	/// </summary>
	/// <param name="_deltaTime">�Ō�̃t���[������������̂ɗv��������</param>
	static void Update(float _deltaTime);

	/// <summary>
	/// �X�R�A�̕`��
	/// </summary>
	static void Draw();
private:
	// Score�̎��́i�A�v�����ɗB�ꑶ�݁j
	static Score* mScore;
};

