#include <stdio.h>
#include <iostream>
#include <chrono>

int main() {
	
    // 100,000文字のstd::stringを作成
    std::string original(1000000000, 'a');

    // コピーにかかる時間を計測
    auto startCopy = std::chrono::high_resolution_clock::now();
    std::string copy = original;
    auto endCopy = std::chrono::high_resolution_clock::now();
    auto duration_copy = std::chrono::duration_cast<std::chrono::microseconds>(endCopy - startCopy).count();

    // 結果を表示
    std::cout << "コピーにかかった時間: " << duration_copy << " マイクロ秒" << std::endl;

    // ムーブコンストラクタにかかる時間を計測
    std::string original_for_move_constructor(1000000000, 'a');

    auto startMove = std::chrono::high_resolution_clock::now();
    std::string movedConstructor(std::move(original_for_move_constructor));
    auto endMove = std::chrono::high_resolution_clock::now();
    auto duration_move_constructor = std::chrono::duration_cast<std::chrono::microseconds>(endMove - startMove).count();

    std::cout << "ムーブコンストラクタにかかった時間: " << duration_move_constructor << " マイクロ秒" << std::endl;

	return 0;
}