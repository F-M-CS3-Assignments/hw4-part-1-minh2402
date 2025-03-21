
#include "bdc.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>


int main() {

	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);


	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	// write your own tests here!
	// Test 3: Empty input list
    values = {};
    ans = biggest_divisible_conglomerate(values);
    cout << "Test 3 - Empty input:" << endl;
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    assert(ans.size() == 0);

    // Test 4: Single element list
    values = {42};
    ans = biggest_divisible_conglomerate(values);
    cout << "Test 4 - Single element:" << endl;
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    assert(ans.size() == 1 && ans[0] == 42);

    // Test 5: Input with no valid divisible pairs
    // For example, none of the pairs in [7, 11, 17, 3] satisfy the divisibility requirement.
    values = {7, 11, 17, 3};
    ans = biggest_divisible_conglomerate(values);
    cout << "Test 5 - No valid divisible pairs:" << endl;
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    // Acceptable output is any single element
    assert(ans.size() == 1);

    // Test 6: Mixed divisible numbers with two potential valid conglomerates
    // For instance, [3, 6, 12, 24, 5, 10, 20, 40] could produce {3,6,12,24} or {5,10,20,40}.
    values = {3, 6, 12, 24, 5, 10, 20, 40};
    ans = biggest_divisible_conglomerate(values);
    cout << "Test 6 - Mixed divisible numbers:" << endl;
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    set<int> ansSet(ans.begin(), ans.end());
    set<int> valid1 = {3, 6, 12, 24};
    set<int> valid2 = {5, 10, 20, 40};
    // Since both valid subsets are of maximum size, the algorithm should return one of them.
    assert(ans.size() == 4 && (ansSet == valid1 || ansSet == valid2));

	return 0;
}
