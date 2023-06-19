// Скопировал решение из гитхаба, чтобы проверить его на тесте 2, на котором у меня все ломается

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>
#include <unordered_map>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 10 * 1000 + 227;
const int MAX_LEN = 35;

struct ig_info {
    ll cost = 0;
    ll cnt = 0;
    ll buy_cnt = 0;
    ll eg_cnt = 0;
    ld arr[4] = {0.0, 0.0, 0.0, 0.0};
};

struct rs {
    string name;
    ll mult = 0;
    vector<pair<string, ll>> igs;
    ld arr[4] = {0.0, 0.0, 0.0, 0.0};
};

int n, k, m;
char buf[MAX_LEN];
char buf_cnt[MAX_LEN];
rs arr[MAX_N];
unordered_map<string, ig_info> info;

ll get_cnt() {
    ll cnt;
    scanf("%lld %s", &cnt, buf_cnt);
    if (!strcmp(buf_cnt, "kg") || !strcmp(buf_cnt, "l")) {
        return 1000 * cnt;
    }
    if (!strcmp(buf_cnt, "tens")) {
        return 10 * cnt;
    }
    return cnt;
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int sz;
        scanf("%s%lld%d", buf, &arr[i].mult, &sz);
        arr[i].name = buf;
        arr[i].igs.resize(sz);
        for (int j = 0; j < sz; ++j) {
            scanf("%s", buf);
            arr[i].igs[j].first = buf;
            arr[i].igs[j].second = get_cnt();
        }
    }

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        ll cost;
        scanf("%s%lld", buf, &cost);
        ig_info& cur_info = info[buf];
        cur_info.cost = cost;
        cur_info.cnt = get_cnt();
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%s", buf);
        ig_info& cur_info = info[buf];
        cur_info.eg_cnt = get_cnt();
        for (int j = 0; j < 4; ++j) {
            double x;
            scanf("%lf", &x);
            cur_info.arr[j] = x;
        }
        if (cur_info.cnt == 0) {
            info.erase(buf);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)arr[i].igs.size(); ++j) {
            ig_info& cur_info = info[arr[i].igs[j].first];
            cur_info.buy_cnt += arr[i].mult * arr[i].igs[j].second;
            for (int k = 0; k < 4; ++k) {
                arr[i].arr[k] += ((double)arr[i].igs[j].second / (double)cur_info.eg_cnt) * cur_info.arr[k];
            }
        }
    }

    ll ans = 0;
    for (auto& cur_info : info) {
        cur_info.second.buy_cnt = (cur_info.second.buy_cnt + cur_info.second.cnt - 1) / cur_info.second.cnt;
        ans += cur_info.second.buy_cnt * cur_info.second.cost;
    }

    printf("%lld\n", ans);

    for (const auto& cur_info : info) {
        printf("%s %lld\n", cur_info.first.c_str(), cur_info.second.buy_cnt);
    }

    for (int i = 0; i < n; ++i) {
        printf("%s ", arr[i].name.c_str());
        for (int j = 0; j < 4; ++j) {
            printf("%.20lf%c", (double)arr[i].arr[j], " \n"[j == 3]);
        }
    }

    return 0;
}