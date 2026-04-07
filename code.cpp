#include <iostream>
#include <climits>
using namespace std;

int n, cost[10][10], visited[10], minCost = INT_MAX;

void tsp(int city, int count, int currCost) {
    if (count == n && cost[city][0]) {
        minCost = min(minCost, currCost + cost[city][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i]) {
            visited[i] = 1;
            tsp(i, count + 1, currCost + cost[city][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    visited[0] = 1;
    tsp(0, 1, 0);

    cout << "Minimum travelling cost: " << minCost;
    return 0;
}