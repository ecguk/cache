#ifndef CACHED_RUNNER_H
#define CACHED_RUNNER_H

#include "cache.h"
#include <string>

class CachedRunner {
private:
  Cache &cache;
  int hitCount;
  int missCount;

  // ���Ͽ��� ���ڸ� �о�� ���ϴ� �Լ�
  double multiplyFromFile(std::string filename);

  // ���Ͽ��� ���� �� �Ӹ������ ã�� �ε����� ��ȯ�ϴ� �Լ�
  int findLongestPalindromeIndex(std::string filename);

public:
  CachedRunner(Cache &cache);

  // ������ ���ڸ� ���� ���Ͽ� ��ȯ�Ѵ�
  double multiply(std::string filename);

  // ���Ͽ��� ���� �� �Ӹ������ ã�� �ε����� ��ȯ�Ѵ�
  int palindrome(std::string filename);

  // ĳ�ÿ� ��Ʈ�� Ƚ���� ��ȯ�Ѵ�
  int hits();

  // ĳ�ÿ� �̽��� Ƚ���� ��ȯ�Ѵ�
  int misses();
};

#endif