#include "cached_runner.h"
#include <fstream>
#include <sstream>

CachedRunner::CachedRunner(Cache &cache) : cache(cache), hitCount(0), missCount(0) {}

double CachedRunner::multiply(std::string filename) {
    // ���Ͽ��� ���ڸ� �о�� ���ϱ�
    double result = multiplyFromFile(filename);
    return result;
}

int CachedRunner::palindrome(std::string filename) {
    // ���Ͽ��� ���� �� �Ӹ������ ã�� �ε����� ��ȯ
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
        return -1.0; // ���� ���� ���� �� ���� ��ȯ
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
        return -1; // ���� ���� ���� �� ���� ��ȯ
    }

    std::string line;
    int longestIndex = -1;
    int currentIndex = 0;

    while (std::getline(file, line)) {
        // ���� ������ ���̰� ������� ã�� ���� �� �Ӹ���Һ��� ���� �Ѵ�.
        if (line.length() > longestIndex) {
            // ���� ������ �Ӹ�������� Ȯ��
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

            // ���� ������ �Ӹ�����̸� �ε��� ������Ʈ
            if (isPalindrome) {
                longestIndex = currentIndex;
            }
        }

        currentIndex++;
    }

    file.close();
    return longestIndex;
}