#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
void print(T val) { cout.width(20); cout.setf(ios::left); cout << val; }

size_t selection_sort(vector<int> &numbers, int size) {
	size_t w = 0;
	int i, j, min_index;
	if (size == 1) return 0;
	
	for (i = 0; i < size - 1; i++) {
		min_index = i;
		for (j = i + 1; j < size; j++) {
			if (numbers[j] < numbers[min_index]) {
				min_index = j;
			}
			w++;
		}	
		if (min_index != i) {
			swap(numbers[min_index], numbers[i]);
			w += 2;
		}
	}
	return w;
}

size_t insertion_sort(vector<int> &numbers, int size) {
	size_t w = 0;
	int i, j, k;
	if (size == 1) return 0;
	
	for (i = 1; i < size; i++) {
		for (j = 0; j < i; j++) {
			w++;
			if (numbers[i] < numbers[j]) {
				for (k = i - 1; k >= j; k--) {
					swap(numbers[k + 1], numbers[k]);
					w += 2;
				}
				break;
			}
		}
	}
	return w;
}

enum {
	GENERATE_INCREASING,
	GENERATE_DECREASING,
	GENERATE_RANDOM
};

void generate_numbers(vector<int> &v, int type, int size) {
	int i, j;	
	switch (type) {
	case GENERATE_INCREASING:
		for (i = 0; i < size; i++) {
			v[i] = i;
		}
		break;
	case GENERATE_DECREASING:
		j = size;
		for (i = 0; i < size; i++) {
			v[i] = j--;
		}
		break;
	case GENERATE_RANDOM:
		srand(time(0));
		for (i = 0; i < size; i++) {
			v[i] = rand();
		}
	}
}

void test_algorithm(
	size_t (*algo)(vector<int>&, int),
	int data_set,
	vector<int> &v,
	int size
) {
	size_t result;
	double c;

	generate_numbers(v, data_set, size);

	c = clock();
	result = algo(v, size);
	c = clock() - c;

	print(size);
	if (algo == &selection_sort)
		print("selection_sort");
	else if (algo == &insertion_sort)
		print("insertion_sort");
	
	switch (data_set) {
	case GENERATE_INCREASING: print("increasing"); break;
	case GENERATE_DECREASING: print("decreasing"); break;
	case GENERATE_RANDOM: print("random");
	}

	print(result);
	print(c / CLOCKS_PER_SEC * 1000);
	cout << endl;
}

int main() {
	int i, j;
	vector<int> v1(5000), v2(10000), v3(15000), v4(20000);

	typedef struct {
		vector<int> &p;
		int size;
	} test;

	test tests[] = {
		{ v1, 5000 },
		{ v2, 10000 },
		{ v3, 15000 },
		{ v4, 20000 }
	};

	print("Size");
	print("Sort-Type");
	print("Data-Set");
	print("Work");
	print("Time");
	cout << endl << endl;

	for (i = 0; i < 4; i++) {
		test_algorithm(selection_sort, GENERATE_INCREASING, tests[i].p, tests[i].size);
		test_algorithm(selection_sort, GENERATE_DECREASING, tests[i].p, tests[i].size);
		test_algorithm(selection_sort, GENERATE_RANDOM, tests[i].p, tests[i].size);
		test_algorithm(insertion_sort, GENERATE_INCREASING, tests[i].p, tests[i].size);
		test_algorithm(insertion_sort, GENERATE_DECREASING, tests[i].p, tests[i].size);
		test_algorithm(insertion_sort, GENERATE_RANDOM, tests[i].p, tests[i].size);
	}

}
