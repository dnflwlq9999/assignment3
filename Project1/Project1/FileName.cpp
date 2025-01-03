#include <iostream>
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;              // ���� �迭
    int currentSize;      // ���� ���� ����
    int currentCapacity;  // �迭�� �뷮

    // �迭 ũ�⸦ �� ��� �ø��� ���� �Լ�
    void resize() {
        int newCapacity = currentCapacity * 2;
        T* newData = new T[newCapacity];
        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        currentCapacity = newCapacity;
    }

public:
    // �⺻ ������ (ũ�� 10�� �迭 ����)
    SimpleVector() : currentSize(0), currentCapacity(10) {
        data = new T[currentCapacity];
    }

    // ũ�⸦ �����ϴ� ������
    SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
        data = new T[currentCapacity];
    }

    // �Ҹ��� (���� �޸� ����)
    ~SimpleVector() {
        delete[] data;
    }

    // ���Ҹ� �� �ڿ� �߰�
    void push_back(const T& value) {
        if (currentSize == currentCapacity) {
            // �뷮 �ʰ� �� �ƹ� ���۵� ���� ����
            return;
        }
        data[currentSize++] = value;
    }

    // ������ ���� ����
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
        }
    }

    // ���� ������ ���� ��ȯ
    int size() const {
        return currentSize;
    }

    // ���� �迭�� �뷮 ��ȯ
    int capacity() const {
        return currentCapacity;
    }
};

int main() {
    SimpleVector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    cout << "Size: " << vec.size() << endl;       // 3
    cout << "Capacity: " << vec.capacity() << endl; // 10

    vec.pop_back();
    cout << "Size after pop_back: " << vec.size() << endl; // 2

    return 0;
}
