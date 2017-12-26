#include <iostream>
#include <vector>

using namespace std;

vector<int> subarraySumClosest(vector<int> nums){
    vector<int> result;
    if (nums.empty()) {
        return result;
    }

    const int num_size = nums.size();
    vector<pair<int, int> > sum_index(num_size + 1);

    for (int i = 0; i < num_size; ++i) {
        sum_index[i + 1].first = sum_index[i].first + nums[i];
        sum_index[i + 1].second = i + 1;
    }

    sort(sum_index.begin(), sum_index.end());

    int min_diff = INT32_MAX;
    int closest_index = 1;
    for (int i = 1; i < num_size + 1; ++i) {
        int sum_diff = abs(sum_index[i].first - sum_index[i - 1].first);
        if (min_diff > sum_diff) {
            min_diff = sum_diff;
            closest_index = i;
        }
    }

    int left_index = min(sum_index[closest_index - 1].second,\
                            sum_index[closest_index].second);
    int right_index = -1 + max(sum_index[closest_index - 1].second,\
                                sum_index[closest_index].second);
    result.push_back(left_index);
    result.push_back(right_index);
    return result;
}

int main(int argc, char *argv[])
{
    vector<int> n = { -3, 1, 1, -3, 5};
    subarraySumClosest(n);
    return 0;
}
