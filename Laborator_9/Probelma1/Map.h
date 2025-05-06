#pragma once
#include <cstdio>
#include <tuple>
using namespace std;

template <typename T, typename V> class Map {
private:
	struct element {
		T key;
		V value;
	};

	element* entries;
	int size, max_size;

	void Resize() {
		int new_max_size = max_size * 2;
		element* new_entries = new element[new_max_size];
		for (int i = 0;i < size;i++) {
			new_entries[i] = entries[i];
		}
		delete[] entries;
		entries = new_entries;
		max_size = new_max_size;
	}

public:
	Map() : size(0), max_size(1) {
		entries = new element[max_size];
	}

	~Map() {
		delete[] entries;
	}

	V& operator[](const T& key) {
		for (int i = 0;i < size;i++) {
			if (entries[i].key == key) {
				return entries[i].value;
			}
		}

		if (size >= max_size) Resize();

		entries[size].key = key;
		entries[size].value = V();
		++size;
		return entries[size - 1].value;
	}

	void Set(const T& key, const V& value) {
		(*this)[key] = value;
	}

	bool Get(const T& key, V& value) {
		for (int i = 0;i < size;i++) {
			if (entries[i].key == key) {
				value = entries[i].value;
				return true;
			}
		}
		return false;
	}

	int Count() {
		return size;
	}

	void Clear() {
		delete[] entries;
		size = 0;
		max_size = 1;
		entries = new element[max_size];
	}

	bool Delete(const T& key) {
		for (int i = 0;i < size;i++) {
			if (entries[i].key == key) {
				for (int j = i; j < size - 1;j++) {
					entries[j] = entries[j + 1];
				}
				size--;
				return true;
			}
		}
		return false;
	}

	bool Include(const Map<T, V>& other) {
		for (int i = 0;i < other.size;i++) {
			int found = 0;
			for (int j = 0;j < size;j++) {
				if (entries[j].key == other.entries[i].key) {
					found = 1;
					break;
				}
			}
			if (found == 0) return false;
		}
		return true;
	}

	struct Iterator {
		element* entries;
		int index;

		Iterator(element* e, int ind) : entries(e), index(ind) {}

		tuple<T, V, int> operator*() const {
			return tuple<T, V, int>(entries[index].key, entries[index].value, index);
		}


		Iterator& operator++() {
			index++;
			return *this;
		}

		bool operator != (const Iterator& other) {
			return index != other.index;
		}
	};

	Iterator begin() {
		return Iterator(entries, 0);
	}

	Iterator end() {
		return Iterator(entries, size);
	}
};