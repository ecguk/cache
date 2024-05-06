#include "cached_runner.h"
#include <fstream>
#include <sstream>

CachedRunner::CachedRunner(Cache &cache) : cache(cache), hitCount(0), missCount(0) {}

double CachedRunner::multiply(std::string filename) {
    // 파일에서 숫자를 읽어와 곱하기
    double result = multiplyFromFile(filename);
    return result;
}

int CachedRunner::palindrome(std::string filename) {
    // 파일에서 가장 긴 팰린드롬을 찾아 인덱스를 반환
    int index = findLongestPalindromeIndex(filename);
    return index;
}

int CachedRunner::hits() {
    return hitCount;
}

int CachedRunner::misses() {
    return missCount;
}

double CachedRunner::multiplyFromFile(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1.0; // 파일 열기 실패 시 음수 반환
    }

    double result = 1.0;
    std::string numberStr;
    while (file >> numberStr) {
        double number = std::stod(numberStr);
        result *= number;
    }

    file.close();
    return result;
}

int CachedRunner::findLongestPalindromeIndex(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1; // 파일 열기 실패 시 음수 반환
    }

    std::string line;
    int longestIndex = -1;
    int currentIndex = 0;

    while (std::getline(file, line)) {
        // 현재 라인의 길이가 현재까지 찾은 가장 긴 팰린드롬보다 길어야 한다.
        if (line.length() > longestIndex) {
            // 현재 라인이 팰린드롬인지 확인
            bool isPalindrome = true;
            int left = 0;
            int right = line.length() - 1;
            while (left < right) {
                if (line[left] != line[right]) {
                    isPalindrome = false;
                    break;
                }
                left++;
                right--;
            }

            // 현재 라인이 팰린드롬이면 인덱스 업데이트
            if (isPalindrome) {
                longestIndex = currentIndex;
            }
        }

        currentIndex++;
    }

    file.close();
    return longestIndex;
}