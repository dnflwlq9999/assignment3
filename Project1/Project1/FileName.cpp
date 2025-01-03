#include <iostream>
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;              // 동적 배열
    int currentSize;      // 현재 원소 개수
    int currentCapacity;  // 배열의 용량

    // 배열 크기를 두 배로 늘리는 내부 함수
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
    // 기본 생성자 (크기 10의 배열 생성)
    SimpleVector() : currentSize(0), currentCapacity(10) {
        data = new T[currentCapacity];
    }

    // 크기를 지정하는 생성자
    SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
        data = new T[currentCapacity];
    }

    // 소멸자 (동적 메모리 해제)
    ~SimpleVector() {
        delete[] data;
    }

    // 원소를 맨 뒤에 추가
    void push_back(const T& value) {
        if (currentSize == currentCapacity) {
            // 용량 초과 시 아무 동작도 하지 않음
            return;
        }
        data[currentSize++] = value;
    }

    // 마지막 원소 제거
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
        }
    }

    // 현재 원소의 개수 반환
    int size() const {
        return currentSize;
    }

    // 현재 배열의 용량 반환
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
