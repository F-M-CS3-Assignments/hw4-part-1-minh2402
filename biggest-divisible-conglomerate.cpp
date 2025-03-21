// Author: Minh Pham
// Date: 2025-03-21
#include "bdc.h"
#include <sstream>
#include <vector>

using namespace std;

// Converts a vector of integers to a string in the format: [x, y, z]
string vec_to_string(vector<int> v) {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); i++) {
        oss << v[i];
        if (i < v.size() - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}

// Helper function: checks whether adding newNum to the current subset
// preserves the divisibility requirement. For each number already in the subset,
// if newNum is larger, then newNum % number must be 0; if newNum is smaller,
// then number % newNum must be 0.
bool canAdd(const vector<int>& subset, int newNum) {
    for (int num : subset) {
        if (newNum > num) {
            if (newNum % num != 0)
                return false;
        } else if (num > newNum) {
            if (num % newNum != 0)
                return false;
        }
    }
    return true;
}

// Recursive backtracking function to find the largest valid conglomerate.
// 'index' represents the current position in the input vector to consider.
// 'current' holds the current subset being built, and 'best' tracks the largest valid subset found so far.
void findConglomerate(const vector<int>& input, int index, vector<int>& current, vector<int>& best) {
    // Update best if the current subset is larger than the best found so far.
    if (current.size() > best.size()) {
        best = current;
    }
    // Optional pruning: if the remaining elements cannot yield a larger subset, return early.
    if (current.size() + (input.size() - index) <= best.size()) {
        return;
    }
    // Try each element starting from index as a potential addition.
    for (int i = index; i < input.size(); i++) {
        if (canAdd(current, input[i])) {
            current.push_back(input[i]);
            findConglomerate(input, i + 1, current, best);
            current.pop_back(); // backtrack
        }
    }
}

// Main function to compute the largest divisible conglomerate from the input list.
vector<int> biggest_divisible_conglomerate(vector<int> input) {
    vector<int> current, best;
    // The recursive function explores all possible subsets.
    findConglomerate(input, 0, current, best);
    return best;
}
