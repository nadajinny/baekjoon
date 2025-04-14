#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int total[1001];
vector<pair<int, int>> dist[1001]; // {to, cost}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a].push_back({b, c});
    }

    int from, end;
    cin >> from >> end;

    for (int i = 1; i <= n; i++) {
        total[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, from});
    total[from] = 0;

    while (!pq.empty()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (cost > total[now]) continue; // 이미 더 짧은 경로가 있음

        for (auto [next, weight] : dist[now]) {
            if (total[next] > total[now] + weight) {
                total[next] = total[now] + weight;
                pq.push({total[next], next});
            }
        }
    }

    cout << total[end] << '\n';
    return 0;
}
