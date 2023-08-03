#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <thread>

//list
class thread_obj {
public:
	void operator()(std::list<int> mylist) {
		size_t c = 0;
		while (!mylist.empty()) {
			mylist.pop_front();
			mylist.pop_front();
			if (!mylist.empty()) mylist.push_back(mylist.front()); 
			//for (auto i : mylist) c++;
			c++;
		}
		std::cout << "list done" << std::endl;
	}
};

//vector
auto lambda = [](std::vector<int> vec) {int arr[100]; for (size_t i = 0; i < 100; ++i) arr[i] = 0; for (auto i : vec) { for (size_t j = 2; j < abs(i); ++j) { if (i % j == 0) { arr[j] += 1; } } } for (size_t i = 0; i < 100; ++i) { if (arr[i] != 0) continue; } std::cout << "vector done" << std::endl;};

//unordered map
void foo(std::unordered_map<double, double> umap) {
	size_t c = 0;
	for (unsigned i = 0; i < umap.bucket_count(); ++i) {
		for (auto local_it = umap.begin(i); local_it != umap.end(i); ++local_it) {
			if (local_it->first == local_it->second) c++;
		}
	}
	if (c > 0) std::cout << "";
	else std::cout << "";

	std::cout << "umap done" << std::endl;
}

int main() {
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(-100, 100);

	std::vector<int> vec;
	std::unordered_map<double, double> umap;
	std::list<int> mylist;

	for (size_t i = 0; i < 500000; ++i) {
		vec.push_back(uniform_dist(e1));
		umap.insert(std::make_pair(uniform_dist(e1), uniform_dist(e1)));
		mylist.push_back(uniform_dist(e1));
	}
	
	//vector
	//for (auto i : vec) std::cout << i << " ";

	//unordered map
	//for (unsigned i = 0; i < umap.bucket_count(); ++i) {
	//	std::cout << "bucket #" << i << " contains:";
	//	for (auto local_it = umap.begin(i); local_it != umap.end(i); ++local_it)
	//		std::cout << " " << local_it->first << ":" << local_it->second;
	//	std::cout << std::endl;
	//}

	//list
	//for (auto i : mylist) std::cout << i << " ";

	//----------------------------------------

	auto start = std::chrono::high_resolution_clock::now();

	//vector
	//lambda(vec);

	std::thread th1(lambda, vec);

	//unordered map
	//foo(umap);

	std::thread th2(foo, umap);

	//list
	//thread_obj obj1;
	//obj1(mylist);

	std::thread th3(thread_obj(), mylist);
	
	th1.join();
	th2.join(); 
	th3.join();

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << std::endl << "execution time = " << duration.count() << " microseconds" << std::endl;
	return 0;
}

//without ~655k
//with ~475k
