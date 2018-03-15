#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

int main()
{
	vector<int> unorderList{ 256, 12, 45, 5, -489, 569, 654, 1, 0, 33, 25 };
	// find,count effeciency comparation
	auto t1 = chrono::system_clock::now();
	for (int i = 0; i < 10000; ++i)
	{
		find(unorderList.cbegin(), unorderList.cend(), 0);
	}
	auto t2 = chrono::system_clock::now();
	cout << "find() cost time:" << (t2 - t1).count() << endl;

	t1 = chrono::system_clock::now();
	for (int i = 0; i < 10000; ++i)
	{
		count(unorderList.cbegin(), unorderList.cend(), 0);
	}
	t2 = chrono::system_clock::now();
	cout << "count() cost time:" << (t2 - t1).count() << endl;

	/// output:
	/// find() cost time : 528865
	/// count() cost time : 753925

	vector<int> orderList{ 0, 1, 2, 3, 4, 6, 7, 8, 9, 10 };
	// lower_bound 返回一个不小于value的值
	vector<int>::iterator itr;
	itr = lower_bound(orderList.begin(), orderList.end(), 5);
	cout << "lower_bound() search 5 position is:" << *itr << endl;
	itr = lower_bound(orderList.begin(), orderList.end(), 6);
	cout << "lower_bound() search 6 position is:" << *itr << endl;
	/// output:
	/// lower_bound() search 5 position is : 6
	/// lower_bound() search 6 position is : 6

	// upper_bound 返回指向第一个大于value的值
	itr = upper_bound(orderList.begin(), orderList.end(), 5);
	cout << "upper_bound() search 5 position is:" << *itr << endl;
	itr = upper_bound(orderList.begin(), orderList.end(), 6);
	cout << "upper_bound() search 6 position is:" << *itr << endl;
	/// output:
	/// upper_bound() search 5 position is : 6
	/// upper_bound() search 6 position is : 7

	// equal_range 返回一个pair，first是lower_bound()的返回值，second是upper_bound（）的返回值
	pair<vector<int>::iterator, vector<int>::iterator> p =
		equal_range(orderList.begin(), orderList.end(), 6);
	cout << "equal_range() search 6 position is:" << *(p.first)
		<< " " << *(p.second) << endl;
	/// output:
	/// equal_range() search 6 position is:6 7

	// binary_search
	bool isFound = binary_search(orderList.cbegin(), orderList.cend(), 5);
	cout << "binary_search() find 5, result:" << boolalpha << isFound << endl;/// false
	isFound = binary_search(orderList.cbegin(), orderList.cend(), 6);
	cout << "binary_search() find 5, result:" << boolalpha << isFound << endl;/// true

	return 0;
}