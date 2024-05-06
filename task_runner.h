#ifndef TASK_RUNNER_H
#define TASK_RUNNER_H

#include <fstream>
#include <iostream>
#include <string>

// �۾��� �����ϱ� ���� ����ϴ� Ŭ����
class TaskRunner {
private:
  // ���ڿ��� �Ӹ�������� �˻��Ѵ�
  static bool isPalindrome(std::string str) {
    for (int i = 0; i < str.size() / 2; i++) {
      if (str[i] != str[str.size() - i - 1]) {
        return false;
      }
    }
    return true;
  }

public:
  // ������ ���ڸ� ���� ���Ͽ� ��ȯ�Ѵ�
  static double multiply(std::string filename) {
    std::ifstream file(filename);
    double result = 1;
    double number;
    while (file >> number) {
      result *= number;
    }
    return result;
  }

  // ���Ͽ��� ���� �� �Ӹ������ ã�� �ε����� ��ȯ�Ѵ�
  static int palindrome(std::string filename) {
    std::ifstream file(filename);
    std::string fullText;
    std::string line;
    while (std::getline(file, line)) {
      fullText += line;
    }

    int maxLength = 0;
    int maxIndex = 0;
    std::string maxPalindrome;

    for (int i = 0; i < fullText.size(); i++) {
      for (int j = i + 1; j < fullText.size(); j++) {
        std::string sub = fullText.substr(i, j - i + 1);
        if (isPalindrome(sub) && sub.size() > maxLength) {
          maxLength = sub.size();
          maxIndex = i;
          maxPalindrome = sub;
        }
      }
    }

    return maxIndex;
  }
};

#endif