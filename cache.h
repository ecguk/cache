#ifndef CACHE_H
#define CACHE_H

#include <string>

#define CACHE_SIZE 10

class Cache {
private:
    struct Node {
        std::string key;
        int int_value;
        double double_value;
        Node* next;

        Node(std::string k, int iv, double dv) : key(k), int_value(iv), double_value(dv), next(nullptr) {}
    };

    Node* head;

public:
  Cache();
  ~Cache();
  // int�� cache�� �߰��Ѵ�
  void add(std::string key, int value);
  // double�� cache�� �߰��Ѵ�
  void add(std::string key, double value);
  // key�� �ش��ϴ� value�� cache���� �����´�
  // Ÿ�԰� key�� ������ ���Ұ� ���ٸ� false�� ��ȯ�Ѵ�.
  bool get(std::string key, int &value);
  // key�� �ش��ϴ� value�� cache���� �����´�.
  // Ÿ�԰� key�� ������ ���Ұ� ���ٸ� false�� ��ȯ�Ѵ�.
  bool get(std::string key, double &value);

  // ����� �� ä�� ��: ���� ����Ʈ�� ���ڿ��� ǥ���Ͽ� ��ȯ�Ѵ�
  // ������ ���� ǥ���� ���ڿ��� ��ȯ�Ѵ�
  // [key1: value1] -> [key2: value2] -> ... -> [keyN: valueN]
  std::string toString();
};

#endif