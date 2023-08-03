/*
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

class thread_obj {
public:
	void operator()(std::vector<int>& vec) {
		std::random_device r;
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> uniform_dist(-100, 100);
		for (size_t i = 0; i < 50; ++i) {
			vec.push_back(uniform_dist(e1));
		}
	}
};

auto lambda = [](std::vector<int> vec) {int c = 0; for (auto i : vec) { c += i; } std::cout << "sum of elements in vec = " << c << std::endl;};

void foo(std::vector<int> vec) {
	int res = 0;
	for (auto i : vec) if (i < 0 && i % 3 == 0) res += 1;
	std::cout << "amount of negative divisors in vec = " << res << std::endl;
}

int main() {
	auto start = std::chrono::high_resolution_clock::now();

	std::vector<int> vec1;
	thread_obj obj_vec1;
	obj_vec1(vec1);
	std::cout << "-----------------------frist vector-----------------------" << std::endl;
	lambda(vec1);
	foo(vec1);

	std::vector<int> vec2;
	thread_obj obj_vec2;
	obj_vec2(vec2);
	std::cout << std::endl << "-----------------------second vector-----------------------" << std::endl;
	lambda(vec2);
	foo(vec2);

	std::vector<int> vec3;
	thread_obj obj_vec3;
	obj_vec3(vec3);
	std::cout << std::endl << "-----------------------third vector-----------------------" << std::endl;
	lambda(vec3);
	foo(vec3);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << std::endl << "execution time = " << duration.count() << " microseconds" << std::endl;
	return 0;
}
*/
