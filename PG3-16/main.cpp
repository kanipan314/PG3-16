#include <stdio.h>
#include <iostream>
#include <chrono>

int main() {
	
    // 100,000������std::string���쐬
    std::string original(1000000000, 'a');

    // �R�s�[�ɂ����鎞�Ԃ��v��
    auto startCopy = std::chrono::high_resolution_clock::now();
    std::string copy = original;
    auto endCopy = std::chrono::high_resolution_clock::now();
    auto duration_copy = std::chrono::duration_cast<std::chrono::microseconds>(endCopy - startCopy).count();

    // ���ʂ�\��
    std::cout << "�R�s�[�ɂ�����������: " << duration_copy << " �}�C�N���b" << std::endl;

    // ���[�u�R���X�g���N�^�ɂ����鎞�Ԃ��v��
    std::string original_for_move_constructor(1000000000, 'a');

    auto startMove = std::chrono::high_resolution_clock::now();
    std::string movedConstructor(std::move(original_for_move_constructor));
    auto endMove = std::chrono::high_resolution_clock::now();
    auto duration_move_constructor = std::chrono::duration_cast<std::chrono::microseconds>(endMove - startMove).count();

    std::cout << "���[�u�R���X�g���N�^�ɂ�����������: " << duration_move_constructor << " �}�C�N���b" << std::endl;

	return 0;
}