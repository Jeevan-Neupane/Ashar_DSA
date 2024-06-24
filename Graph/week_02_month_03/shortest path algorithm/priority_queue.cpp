#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // Define the priority queue with a custom comparator
    auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second; // Min-heap based on second value
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

    // Push some pairs into the priority queue
    pq.push({1, 5});
    pq.push({2, 1});
    pq.push({3, 3});
    pq.push({4, 4});

    // Print and pop elements based on the second value
    while (!pq.empty())
    {
        std::pair<int, int> top = pq.top();
        std::cout << "(" << top.first << ", " << top.second << ")\n";
        pq.pop();
    }

    return 0;
}
