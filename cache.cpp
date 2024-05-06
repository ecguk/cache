#include "cache.h"

#include <sstream>

// Cache 클래스의 생성자
Cache::Cache() : head(nullptr) {
    // 생성자에서 필요한 초기화 작업을 수행합니다.
}

// Cache 클래스의 소멸자
Cache::~Cache() {
    // 동적으로 할당된 메모리 등 자원을 해제합니다.
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// int 값을 Cache에 추가하는 함수
void Cache::add(std::string key, int value) {
    // Cache에 int 값을 추가하는 코드를 작성합니다.
    Node* newNode = new Node(key, value, 0); // double_value는 사용되지 않으므로 0으로 초기화합니다.

    // 만약 head가 비어있다면 새로운 노드를 head로 설정합니다.
    if (!head) {
        head = newNode;
        return;
    }

    // 새로운 노드를 리스트의 맨 뒤에 추가합니다.
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// double 값을 Cache에 추가하는 함수
void Cache::add(std::string key, double value) {
    // Cache에 double 값을 추가하는 코드를 작성합니다.
    Node* newNode = new Node(key, 0, value); // int_value는 사용되지 않으므로 0으로 초기화합니다.

    // 만약 head가 비어있다면 새로운 노드를 head로 설정합니다.
    if (!head) {
        head = newNode;
        return;
    }

    // 새로운 노드를 리스트의 맨 뒤에 추가합니다.
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// key에 해당하는 int 값을 가져오는 함수
bool Cache::get(std::string key, int &value) {
    // key에 해당하는 int 값을 가져오는 코드를 작성합니다.
    Node* current = head;
    while (current) {
        if (current->key == key) {
            value = current->int_value;
            return true; // key에 해당하는 값이 존재하므로 true를 반환합니다.
        }
        current = current->next;
    }
    return false; // key에 해당하는 값이 존재하지 않으므로 false를 반환합니다.
}

// key에 해당하는 double 값을 가져오는 함수
bool Cache::get(std::string key, double &value) {
    // key에 해당하는 double 값을 가져오는 코드를 작성합니다.
    Node* current = head;
    while (current) {
        if (current->key == key) {
            value = current->double_value;
            return true; // key에 해당하는 값이 존재하므로 true를 반환합니다.
        }
        current = current->next;
    }
    return false; // key에 해당하는 값이 존재하지 않으므로 false를 반환합니다.
}

// 연결 리스트를 문자열로 변환하는 함수
std::string Cache::toString() {
    // 연결 리스트를 문자열로 변환하는 코드를 작성합니다.
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
    ss << "nullptr"; // 리스트의 끝을 나타내는 nullptr을 추가합니다.
    return ss.str();
}