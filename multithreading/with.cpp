/*
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

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
	std::thread th1_1(thread_obj(), vec1);
	std::cout << "-----------------------frist vector-----------------------" << std::endl;
	std::thread th1_2(lambda, vec1);
	std::thread th1_3(foo, vec1);

	th1_1.join();
	th1_2.join();
	th1_3.join();


	std::vector<int> vec2;
	std::thread th2_1(thread_obj(), vec2);
	std::cout << "-----------------------second vector-----------------------" << std::endl;
	std::thread th2_2(lambda, vec2);
	std::thread th2_3(foo, vec2);

	th2_1.join();
	th2_2.join();
	th2_3.join();

	std::vector<int> vec3;
	std::thread th3_1(thread_obj(), vec3);
	std::cout << "-----------------------third vector-----------------------" << std::endl;
	std::thread th3_2(lambda, vec3);
	std::thread th3_3(foo, vec3);

	th3_1.join();
	th3_2.join();
	th3_3.join();

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << std::endl << "execution time = " << duration.count() << " microseconds" << std::endl;
	return 0;
}
*/
