#ifndef TASK_H
#define TASK_H

#include <fstream>
#include <string>

// �½�ũ�� ����
enum TaskType { MULTIPLY, PALINDROME };

// �½�ũ�� ���� ������ ��� ����ü
struct Task {
  TaskType type;
  std::string filename;
};

// �½�ũ�� �о���� ���� Ŭ����
class TaskSet {
private:
  std::ifstream file_;

public:
  TaskSet(std::string filename) { file_.open(filename); }
  ~TaskSet() { file_.close(); }

  // ���� �½�ũ�� �о� task ��ü�� �����ϰ� true�� ��ȯ�Ѵ�
  // �½�ũ�� ���� ��� false�� ��ȯ�Ѵ�
  bool getNext(Task &task) {
    if (file_.eof())
      return false;

    std::string typeText;
    file_ >> typeText;

    if (typeText == "multiply") {
      task.type = MULTIPLY;
    } else if (typeText == "palindrome") {
      task.type = PALINDROME;
    } else {
      return getNext(task);
    }

    file_ >> task.filename;
    return true;
  }
};

#endif