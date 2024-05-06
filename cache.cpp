#include "cache.h"

#include <sstream>

// Cache Ŭ������ ������
Cache::Cache() : head(nullptr) {
    // �����ڿ��� �ʿ��� �ʱ�ȭ �۾��� �����մϴ�.
}

// Cache Ŭ������ �Ҹ���
Cache::~Cache() {
    // �������� �Ҵ�� �޸� �� �ڿ��� �����մϴ�.
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// int ���� Cache�� �߰��ϴ� �Լ�
void Cache::add(std::string key, int value) {
    // Cache�� int ���� �߰��ϴ� �ڵ带 �ۼ��մϴ�.
    Node* newNode = new Node(key, value, 0); // double_value�� ������ �����Ƿ� 0���� �ʱ�ȭ�մϴ�.

    // ���� head�� ����ִٸ� ���ο� ��带 head�� �����մϴ�.
    if (!head) {
        head = newNode;
        return;
    }

    // ���ο� ��带 ����Ʈ�� �� �ڿ� �߰��մϴ�.
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// double ���� Cache�� �߰��ϴ� �Լ�
void Cache::add(std::string key, double value) {
    // Cache�� double ���� �߰��ϴ� �ڵ带 �ۼ��մϴ�.
    Node* newNode = new Node(key, 0, value); // int_value�� ������ �����Ƿ� 0���� �ʱ�ȭ�մϴ�.

    // ���� head�� ����ִٸ� ���ο� ��带 head�� �����մϴ�.
    if (!head) {
        head = newNode;
        return;
    }

    // ���ο� ��带 ����Ʈ�� �� �ڿ� �߰��մϴ�.
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// key�� �ش��ϴ� int ���� �������� �Լ�
bool Cache::get(std::string key, int &value) {
    // key�� �ش��ϴ� int ���� �������� �ڵ带 �ۼ��մϴ�.
    Node* current = head;
    while (current) {
        if (current->key == key) {
            value = current->int_value;
            return true; // key�� �ش��ϴ� ���� �����ϹǷ� true�� ��ȯ�մϴ�.
        }
        current = current->next;
    }
    return false; // key�� �ش��ϴ� ���� �������� �����Ƿ� false�� ��ȯ�մϴ�.
}

// key�� �ش��ϴ� double ���� �������� �Լ�
bool Cache::get(std::string key, double &value) {
    // key�� �ش��ϴ� double ���� �������� �ڵ带 �ۼ��մϴ�.
    Node* current = head;
    while (current) {
        if (current->key == key) {
            value = current->double_value;
            return true; // key�� �ش��ϴ� ���� �����ϹǷ� true�� ��ȯ�մϴ�.
        }
        current = current->next;
    }
    return false; // key�� �ش��ϴ� ���� �������� �����Ƿ� false�� ��ȯ�մϴ�.
}

// ���� ����Ʈ�� ���ڿ��� ��ȯ�ϴ� �Լ�
std::string Cache::toString() {
    // ���� ����Ʈ�� ���ڿ��� ��ȯ�ϴ� �ڵ带 �ۼ��մϴ�.
    std::stringstream ss;
    Node* current = head;
    while (current) {
        ss << "[" << current->key << ": ";
        if (current->int_value != 0) {
            ss << current->int_value;
        } else {
            ss << current->double_value;
        }
        ss << "] -> ";
        current = current->next;
    }
    ss << "nullptr"; // ����Ʈ�� ���� ��Ÿ���� nullptr�� �߰��մϴ�.
    return ss.str();
}