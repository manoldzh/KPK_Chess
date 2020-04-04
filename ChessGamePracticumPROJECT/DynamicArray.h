#pragma once

template<typename T>
const int INITIAL_SIZE = 0;
const int INITIAL_CAPACITY = 20;
class DynamicArray {
private:
	T * array;
	unsigned size;
	unsigned capacity;

	void resizeArray() {
		capacity *= 2;
		T* temp = new T[capacity];
		for (unsigned i = 0; i < size; i++) {
			temp[i] = array[i];
		}
		delete[] array;
		array = temp;
	}

	void copy(const DynamicArray<T>& otherDynamicArray) {
		size = otherDynamicArray.size;
		capacity = otherDynamicArray.capacity;
		array = new T[capacity];
		for (unsigned i = 0; i < size; i++) {
			array[i] = otherDynamicArray.arr[i];
		}
	}
public:
	DynamicArray() {
		size = INITIAL_SIZE;
		capacity = INITIAL_CAPACITY;
		array = new T[capacity];
	}
	DynamicArray(const DynamicArray<T>& otherDynamicArray) {
		copy(otherDynamicArray);
	}
	DynamicArray& operator = (const DynamicArray<T>& otherDynamicArray) {
		if (this != &otherDynamicArray) {
			delete[] array;
			copy(otherDynamicArray);
		}
		return *this;
	}
	~DynamicArray() {
		for (unsigned int i = 0; i < size; i++){
			delete array[i];
		}
	}
	void unionWith(const DynamicArray<T>& otherDynamicArray) {
		for (int i = 0; i < otherDynamicArray.get_size(); i++){
			this->push_back(otherDynamicArray.get_ElementAtIndex(i));
		}

	}

	void push_back(const T& new_element) {
		if (size == capacity) {
			resizeArray();
		}
		array[size] = new_element;
		size++;
	}

	T& operator[](unsigned index) {
		return array[index];
	}
	T operator[](unsigned index) const {
		return array[index];
	}

	unsigned get_size() const {
		return size;
	}
	T get_ElementAtIndex(unsigned index) const {
		return array[index];
	}
	void remove_by_index(unsigned index) {
		for (unsigned i = index; i <= this->size - 1; i++) {
			array[i] = array[i + 1];
		}
		size--;
	}
};