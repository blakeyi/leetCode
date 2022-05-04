#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 层序遍历建树
/*
        1
     2     3
   nl nl  nl nl
nl 用INT_MAX代替
*/
TreeNode *CreatTree(vector<int> nums) {
    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> tQueue;
    tQueue.push(root);
    int n = nums.size(), i = 1;
    while (!tQueue.empty() && i < n) {
        TreeNode *p = tQueue.front();
        TreeNode *left, *right;
        tQueue.pop();
        if (nums[i] != INT_MAX) {
            left = new TreeNode(nums[i]);
        } else {
            left = nullptr;
        }
        i++;
        if (nums[i] != INT_MAX) {
            right = new TreeNode(nums[i]);
        } else {
            right = nullptr;
        }
        i++;
        if (p) {
            p->left = left;
            p->right = right;
            tQueue.push(left);
            tQueue.push(right);
        }
    }
    return root;
}

ListNode *CreatList(vector<int> nums) {
    ListNode *head = new ListNode(nums[0]);
    ListNode *phead = head;
    for (int i = 1; i < nums.size(); ++i) {
        ListNode *node = new ListNode(nums[i]);
        phead->next = node;
        phead = node;
    }
    return head;
}

class Solution695 {  // 695. 岛屿的最大面积
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        vector<int> direction = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    int areaSize = 1;
                    stack<pair<int, int>> area;
                    area.push({i, j});
                    grid[i][j] = 0;  // 需要清零，防止重复访问
                    while (!area.empty()) {
                        pair<int, int> temp = area.top();
                        area.pop();
                        for (int k = 0; k < 4; ++k) {
                            int x = temp.first + direction[k];
                            int y = temp.second + direction[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n &&
                                grid[x][y]) {
                                area.push({x, y});
                                ++areaSize;
                            }
                        }
                    }
                    maxArea = areaSize > maxArea ? areaSize : maxArea;
                }
            }
        }
        return maxArea;
    }
};
class Solution77 {
    /*
    利用递归，分别执行当前节点选与不选的状态，
    当temp数组的数量达到k，则存入答案
    */
   public:
    vector<int> temp;
    vector<vector<int>> ans;

   public:
    void dfs(int cur, int n, int k) {
        if (temp.size() + (n - cur + 1) < k) {
            return;
        }
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        dfs(cur + 1, n, k);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};
class Solution79 {
    /*
     */
   public:
    struct Point {
        int x;
        int y;
    };
    vector<int> direction = {-1, 0, 1, 0, -1};

   public:
    bool dfs(vector<vector<char>>& board, string word, Point cur, int k) {
        if (k == word.size()) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            Point temp = {cur.x + direction[i], cur.y + direction[i + 1]};
            if (temp.x >= 0 && temp.x < board.size() && temp.y >= 0 &&
                temp.y < board[0].size()) {
                if (board[cur.x + direction[i]][cur.y + direction[i + 1]] ==
                    word[k]) {
                    cout << temp.x << " , " << temp.y << " , "
                         << board[temp.x][temp.y] << endl;
                    char tempchar =
                        board[cur.x + direction[i]][cur.y + direction[i + 1]];
                    board[cur.x + direction[i]][cur.y + direction[i + 1]] = '0';
                    if (dfs(board, word, temp, k + 1) == true) {
                        return true;
                    }
                    board[cur.x + direction[i]][cur.y + direction[i + 1]] =
                        tempchar;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<char>> temp = board;
                    temp[i][j] = '0';
                    Point cur = {i, j};
                    if (dfs(temp, word, cur, 1) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

class Solution752 {
    // BSF 广度优先搜索
   public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadNum, visit;
        queue<pair<string, int>> strQ;
        for (auto str : deadends) {
            if (str == "0000") {
                return -1;
            }
            deadNum.insert(str);
        }
        if (target == "0000") {
            return 0;
        }
        strQ.push(make_pair("0000", 0));
        visit.insert("0000");
        string str;
        int step;
        while (!strQ.empty()) {
            pair<string, int> current = strQ.front();
            strQ.pop();
            for (uint32_t i = 0; i < 8; ++i) {  // 找出拨动一次可能出现的8中情况
                int temp = current.first[i / 2] - '0';
                string next = current.first;
                if (i % 2 != 0) {  //为奇数，则减
                    temp = (temp == 0) ? 9 : (temp - 1);
                } else {
                    temp = (temp == 9) ? 0 : (temp + 1);
                }
                next.replace(i / 2, 1, to_string(temp));
                if (deadNum.find(next) == deadNum.end() &&
                    visit.find(next) ==
                        visit.end()) {  // 没找到，修改次数入队列
                    int count = current.second;
                    if (next == target) {  //找到目标,不入队列继续查找
                        return ++count;
                    } else {  //未找到目标
                        strQ.push(make_pair(next, ++count));
                        visit.insert(next);
                    }
                }
            }
        }

        return -1;
    }
};

int Add(int a, int b) { return a + b; }

class Solution815 {  // 815. 公交路线
   public:
    bool IsFriends(vector<int> route1, vector<int> route2) {
        set<int> s1(route1.begin(), route1.end());
        set<int> s2(route2.begin(), route2.end());
        for (auto n : s1) {
            if (s2.find(n) != s2.end()) {
                return true;
            }
        }
        return false;
    }
    vector<int> FindRoute(vector<vector<int>>& routes, int target) {
        vector<int> vec;
        for (int i = 0; i < routes.size(); ++i) {
            if (find(routes[i].begin(), routes[i].end(), target) !=
                routes[i].end()) {
                vec.push_back(i);
            }
        }
        return vec;
    }
    int bsf(vector<vector<int>> routeMap, int source, int target) {
        if (source == target) {
            return 1;
        }
        queue<pair<int, int>> q;
        int routeNum = routeMap.size();
        vector<int> visit(routeNum, 0);
        q.push(make_pair(source, 1));
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            for (int i = 0; i < routeNum; ++i) {
                if (!visit[i] && i != current.first &&
                    routeMap[current.first][i]) {
                    if (i == target) {
                        return ++current.second;
                    } else {
                        int step = current.second;
                        q.push(make_pair(i, ++step));
                        visit[i] = 1;
                    }
                }
            }
        }
        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target) {
            return 0;
        }
        int num = routes.size();
        vector<vector<int>> routeMap(num, vector<int>(num, 0));
        vector<int> sourceRoute = FindRoute(routes, source);
        vector<int> targetRoute = FindRoute(routes, target);
        set<int> result;
        unordered_map<int, vector<int>> rec;
        for (int i = 0; i < num; i++) {
            for (auto& site : routes[i]) {
                for (auto& j : rec[site]) {
                    routeMap[i][j] = routeMap[j][i] = true;
                }
                rec[site].push_back(i);
            }
        }
        for (auto s : sourceRoute) {
            for (auto t : targetRoute) {
                int res = bsf(routeMap, s, t);
                if (res != -1) {
                    result.insert(res);
                }
            }
        }
        return result.size() != 0 ? *result.begin() : -1;
    }
};

class Solution8151 {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target) {
            return 0;
        }

        int n = routes.size();
        vector<vector<int>> edge(n, vector<int>(n));
        unordered_map<int, vector<int>> rec;
        for (int i = 0; i < n; i++) {
            for (auto& site : routes[i]) {
                for (auto& j : rec[site]) {
                    edge[i][j] = edge[j][i] = true;
                }
                rec[site].push_back(i);
            }
        }

        vector<int> dis(n, -1);
        queue<int> que;
        for (auto& site : rec[source]) {
            dis[site] = 1;
            que.push(site);
        }
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            for (int y = 0; y < n; y++) {
                if (edge[x][y] && dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    que.push(y);
                }
            }
        }

        int ret = INT_MAX;
        for (auto& site : rec[target]) {
            if (dis[site] != -1) {
                ret = min(ret, dis[site]);
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};

class Solution168 {  // 168. Excel表列名称
   public:
    string convertToTitle(int columnNumber) {
        vector<int> vec;
        string result;
        int dividend = columnNumber;
        if (dividend == 1) {
            return "A";
        }
        while (dividend > 1) {
            int temp = dividend % 26;
            if (temp == 0) {
                temp = 26;
            }
            vec.push_back(temp);
            dividend = dividend / 26;
        }
        for (int i = vec.size() - 1; i >= 0; --i) {
            result += (vec[i] + 'A' - 1);
        }
        return result;
    }
};

class Solution451 {  // 451. 根据字符出现频率排序
   public:
    static bool compare(const pair<char, int>& p1, const pair<char, int>& p2) {
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        map<char, int> sMap;
        string result;
        for (auto& c : s) {
            sMap[c]++;
        }
        vector<pair<char, int>> vec(sMap.begin(), sMap.end());
        sort(vec.begin(), vec.end(), compare);
        for (auto& i : vec) {
            while (i.second--) {
                result += i.first;
            }
        }
        return result;
    }
};

class Solution416 {  // 416. 分割等和子集
                     /*
                                    * 1.长度小于2，或者和为奇数，或者最大值大于
                        和的一半，返回false
                                    * 2.dp[i][j]表示选取若干个(i <
                                      nums.size())数，和为j，true代表存在，false代表不存在
                                    * 3.dp[i][0] = true;表示只要不选取元素，j必然为0，存在此情况
                                    * 4.dp[0][nums[0]] = true; 选取第一个就行
                                    * 5.对于任意的dp[i][j],分情况讨论,
                                        当 j >= nums[i]时，
                                            选取 nums[i],则
                                                dp[i][j] = dp[i - 1][j - nums[i]];
                                            不选取 nums[i],则
                                                dp[i][j] = dp[i - 1][j];
                                        当 j < nums[i]时，肯定不能选 nums[i],
                                            dp[i][j] = dp[i - 1][j];
                                        状态转移方程为：
                                            dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]] , j
                        >=                  nums[i]; = dp[i - 1][j] , j < nums[i]
                                    */
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int maxValue = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / 2;
        if (n < 2 || sum % 2 || maxValue > target) {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, false));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

class Solution645 {  // 645. 错误的集合
   public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n + 1, 0);
        int repeat, lack;
        for (auto& i : nums) {
            vec[i]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (vec[i] == 2) {
                repeat = i;
            } else if (vec[i] == 0) {
                lack = i;
            }
        }
        return {repeat, lack};
    }
};

class Solution1155 {  // 1155. 掷骰子的N种方法
                      /*
                                      1. dp[i][j] 表示i个筛子，总数和为j的方法数， i < d, j <
                         target
                                      2. dp[i][j] = dp[i - 1][j - n] + 1, n为第i个骰子的点数
                                      */
   public:
    int numRollsToTarget(int d, int f, int target) {
        int max = d * f > target ? d * f : target;
        static int MOD = 1000000007;
        vector<vector<int>> dp(d + 1, vector<int>(max + 1, 0));
        for (int i = 1; i <= f; ++i) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= d; ++i) {
            for (int j = i; j <= target; ++j) {
                for (int m = 1; m <= f; ++m) {
                    if (j - m >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - m]) % MOD;
                    }
                }
            }
        }
        return dp[d][target];
    }
};

class Solution23 {  // 23. 合并K个升序链表
   public:
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode *p, *p1, *p2, *result;
        if (l1->val < l2->val) {
            p = l1;
            p1 = l1->next;
            p2 = l2;
        } else {
            p = l2;
            p1 = l1;
            p2 = l2->next;
        }
        result = p;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1) {
            p->next = p1;
        } else if (p2) {
            p->next = p2;
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = lists[0];
        int n = lists.size();
        if (n == 1) {
            return lists[0];
        }
        for (int i = 1; i < n; ++i) {
            result = mergeLists(result, lists[i]);
        }
        return result;
    }
};

class Solution726 {  // 726. 原子的数量
   public:
    string countOfAtoms(string formula) {  //通过栈实现 右括号带来的倍乘问题
        vector<pair<string, int>> stk;  //原子以及数量 vector模拟栈
        int size = formula.size();
        for (int i = 0; i < size; ++i) {
            if (formula[i] == '(') {
                stk.emplace_back(make_pair("(", 0));
            } else if (isupper(formula[i])) {  //处理一个完整的带数字的
                string temp = "";
                temp += formula[i];
                while (i < size && islower(formula[i + 1])) {
                    i++;
                    temp += formula[i];
                }

                if (i < size && isdigit(formula[i + 1])) {  //有数字就是数字
                    int num = 0;
                    while (i < size - 1 && isdigit(formula[i + 1])) {
                        num *= 10;
                        i++;
                        num += formula[i] - '0';
                    }
                    stk.emplace_back(make_pair(temp, num));
                } else {  //没数字是1
                    stk.emplace_back(make_pair(temp, 1));
                }
            } else {  //右括号
                int num = 0;
                int tempIndex = stk.size();
                while (i < size - 1 && isdigit(formula[i + 1])) {
                    num *= 10;
                    i++;
                    num += formula[i] - '0';
                }
                if (num == 0) num = 1;  //仅仅是个括号，没有翻倍
                while (--tempIndex && stk[tempIndex].first != "(") {
                    stk[tempIndex].second *= num;  //翻倍
                }
                stk.erase(stk.begin() + tempIndex);  //擦去用过的左括号
            }
        }

        int s = stk.size();
        map<string, int> mMap;
        string res = "";
        for (int i = 0; i < s; ++i) {
            mMap[stk[i].first] += stk[i].second;
        }

        for (auto& m : mMap) {
            if (m.second > 1)
                res += m.first + to_string(m.second);
            else
                res += m.first;
        }

        return res;
    }
};

class Solution151 {  // 151. 翻转字符串里的单词
   public:
    string reverseWords(string s) {
        string result;
        // 先去多余空格
        while (s[0] == ' ') {
            s = s.substr(1, s.size() - 1);
        }
        while (s[s.size() - 1] == ' ') {
            s = s.substr(0, s.size() - 1);
        }
        int end = s.size() - 1;
        for (int i = s.size(); i >= 0; i--) {
            if (s[i] == ' ') {
                int start = i + 1;
                while (s[i - 1] == ' ') {
                    i--;
                }
                result += s.substr(start, end - start + 1);
                result += " ";
                end = i - 1;
            } else if (i == 0) {
                result += s.substr(i, end - i + 1);
            }
        }
        return result;
    }
};

class Solution1418 {  // 1418. 点菜展示表
   public:
    struct strCmp {
        bool operator()(const string& s1, const string& s2) const {
            if (atoi(s1.c_str()) < atoi(s2.c_str())) {
                return true;
            }
            return false;
        }
    };

    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string, map<string, int>> orderMap;
        vector<vector<string>> result;
        set<string> dishSet;
        set<string, strCmp> tableSet;
        for (auto& order : orders) {
            string table = order[1];
            string dish = order[2];
            dishSet.insert(dish);
            tableSet.insert(table);
            orderMap[table][dish]++;
        }
        vector<string> dish;
        dish.push_back("Table");
        for (auto& dishs : dishSet) {
            dish.push_back(dishs);
        }
        result.push_back(dish);
        for (auto& table : tableSet) {
            vector<string> res;
            res.push_back(table);
            for (auto& dish : dishSet) {
                if (orderMap[table].count(dish) == 0) {
                    res.push_back("0");
                } else {
                    res.push_back(to_string(orderMap[table][dish]));
                }
            }
            result.push_back(res);
        }
        return result;
    }
};

class Solution509 {  // 509. 斐波那契数
   public:
    int fib(int n) {
        vector<int> dp(n + 2, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution509_1 {  // 509. 斐波那契数
                       // 空间优化版本，只与前两个数相关
   public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        int cur, pre = 1, pre1 = 0;
        for (int i = 2; i <= n; ++i) {
            cur = pre + pre1;
            pre1 = pre, pre = cur;
        }
        return cur;
    }
};

class Solution1137 {  // 1137. 第 N 个泰波那契数
                      // 空间优化版本，只与前三个数相关
   public:
    int fib(int n) {
        if (n < 3) {
            return n == 0 ? 0 : 1;
        }
        int cur, pre = 1, pre1 = 1, pre2 = 0;
        for (int i = 3; i <= n; ++i) {
            cur = pre + pre1 + pre2;
            pre2 = pre1;
            pre1 = pre, pre = cur;
        }
        return cur;
    }
};

class Solution1171 {  // 1711. 大餐计数
   public:
    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size();
        int max = *max_element(deliciousness.begin(), deliciousness.end());
        vector<int> count(max + 1, 0);
        int sum;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            count[deliciousness[i]]++;
        }
        for (int i = 0; i <= max; ++i) {
            sum = i + i;
            if (sum != 0 && (sum & (sum - 1)) == 0) {
                result += count[i] * (count[i] - 1) / 2;
            }
            for (int j = i + 1; j <= max; ++j) {
                sum = i + j;
                if (sum != 0 && (sum & (sum - 1)) == 0) {
                    result += count[i] * count[j];
                }
            }
        }
        return result;
    }
};

class Solution605 {  // 605. 种花问题
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for (int i = 0; i < len; i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
                (i == len - 1 || flowerbed[i + 1] == 0)) {
                n--;
                if (n <= 0) return true;
                flowerbed[i] = 1;
            }
        }

        return n <= 0;
    }
};

class Solution452 {  // 452. 用最少数量的箭引爆气球
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 先按照右边界从小到大排序，第一只箭 第一个右边界
        // 设置为pos，射出，然后扫描挨个扫描，如果左边界小于pos，则可以当前的箭可以覆盖，
        // 如果当前左边界大于pos了，则需要另外一只箭
        if (points.empty()) {
            return 0;
        }
        int pos, ans = 1;
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        pos = points[0][1];
        for (auto& ballon : points) {
            if (ballon[0] > pos) {
                pos = ballon[1];
                ans++;
            }
        }
        return ans;
    }
};

class Solution930 {  // 930. 和相同的二元子数组
   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int, int> cnt;
        int ret = 0;
        for (auto& num : nums) {
            cnt[sum]++;
            sum += num;
            ret += cnt[sum - goal];
        }
        return ret;
    }
};

class Solution17_10 {  // 面试题 17.10. 主要元素
   public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (auto& i : nums) {
            if (count == 0) {
                candidate = i;
            }
            if (i == candidate) {
                count++;
            } else {
                count--;
            }
        }
        count = 0;
        for (auto& i : nums) {
            if (i == candidate) {
                count++;
            }
        }
        return count > nums.size() / 2 ? candidate : -1;
    }
};

class Solution763 {  // 763. 划分字母区间
                     /*
                                    * 贪心算法，
                                      由于同一个字母只能出现在同一个区间，因此需要遍历得到每一个字母最后出现的位置
                                    * 然后遍历，start 和end标记当前区间，
                        当访问到元素c时，重新计算end = max（end, endc),当 i =
                        end的时候，此时当前区间结束                   start = end + 1；
                                    */
   public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        vector<int> result;
        int n = s.size();
        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; ++i) {
            end = max(end, last[s[i] - 'a']);
            if (end == i) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};

class Solution406 {  // 406. 根据身高重建队列、
                     /*
                                    1.先根据身高进行排序
                                    2.如果身高最低的不是排在第一位，则根据他的排序，放到 第i位
                                    */
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](const vector<int>& u, const vector<int>& v) {
                 return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
             });
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const vector<int>& person : people) {
            int spaces = person[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

class TimeMap {  // 981. 基于时间的键值存储
   public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (timeMap.count(key) == 0) {
            map<int, string> temp;
            temp.insert(make_pair(timestamp, value));
            timeMap.insert(make_pair(key, temp));
            return;
        }
        timeMap[key].insert(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        if (timeMap.count(key) == 0) {
            return "";
        }
        if (timeMap[key].count(timestamp) == 0) {
            auto iter = timeMap[key].lower_bound(-timestamp);
            if (iter == timeMap[key].end()) {
                return "";
            }
            return iter->second;
        }
        return timeMap[key][timestamp];
    }

   private:
    map<string, map<int, string>> timeMap;
};

class Solution665 {  // 665. 非递减数列
   public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if (n < 2) {
            return true;
        }
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                count++;
                if (count > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution274 {  // 274. H 指数
   public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= (n - i)) {
                return n - i;
            }
        }
        return 0;
    }
};

class Solution274_1 {  // 274. H 指数2
   public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (right + left) / 2;
            if (citations[mid] >= (n - mid)) {
                return n - mid;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= (n - i)) {
                return n - i;
            }
        }
        return 0;
    }
};

class CxString  // 没有使用explicit关键字的类声明, 即默认为隐式声明
{
   public:
    char* _pstr;
    int _size;
    CxString(int size) {
        _size = size;                     // string的预设大小
        _pstr = (char*)malloc(size + 1);  // 分配string的内存
        memset(_pstr, 0, size + 1);
    }
    CxString(const char* p) {
        int size = strlen(p);
        _pstr = (char*)malloc(size + 1);  // 分配string的内存
        strcpy(_pstr, p);                 // 复制字符串
        _size = strlen(_pstr);
    }
};

class Sort {
   public:
    void BubbleSort(vector<int>& vec) {
        // 每一轮都把最大的元素移到最右边
        int n = vec.size();
        int temp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (vec[j] > vec[j + 1]) {
                    temp = vec[j + 1];
                    vec[j + 1] = vec[j];
                    vec[j] = temp;
                }
            }
        }
    }
    void InsertSort(vector<int>& vec) {
        // 插入同时后移
        int n = vec.size();
        int temp, j;
        for (int i = 1; i < n; ++i) {
            temp = vec[i];
            for (j = i - 1; j >= 0 && vec[j] > temp; j--) {
                vec[j + 1] = vec[j];
            }
            vec[j + 1] = temp;
        }
    }
};

char* getMemory(void) {
    char* p = (char*)malloc(10);
    return p;
}

class Solution_Offer53 {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, mid;
        int count = 0;
        while (left < right) {
            mid = (right + left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {  // 找到了相等的数,往两边扩展找相同的数
                int temp = mid + 1;
                count = 1;
                while (temp < n) {
                    if (nums[temp] == target) {
                        count++;
                        temp++;
                    } else {
                        break;
                    }
                }
                temp = mid - 1;
                while (temp >= 0) {
                    if (nums[temp] == target) {
                        count++;
                        temp--;
                    } else {
                        break;
                    }
                }
                break;
            }
        }
        return count;
    }
};

class Solution_Offer42 {  // 剑指 Offer 42. 连续子数组的最大和
                          // dp[i] 表示以第i个元素为结尾的最大和
   public:
    int maxSubArray(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};

class Solution_Offer1002 {  // 面试题 10.02. 变位词组
                            // 存在不同的字母组合值相同的情况，需要处理hash碰撞
   public:
    int calcSum(string str) {
        int sum = 0;
        for (auto& c : str) {
            sum += c - 'a';
        }
        return sum;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

class Solution1838 {  // 1838. 最高频元素的频数
   public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long total = 0;
        int l = 0, res = 1;
        for (int r = 1; r < n; ++r) {
            total += (long long)(nums[r] - nums[r - 1]) * (r - l);
            while (total > k) {
                total -= nums[r] - nums[l];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

class Solution1784 {  // 1784. 检查二进制字符串字段
   public:
    bool checkOnesSegment(string s) {
        bool hasOne = false, hasZero = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1' && hasOne == false) {  // 第一次出现1
                hasOne = true;
            } else if (s[i] == '0' && hasOne == true) {  // 出现过1后又出现0
                hasZero = true;
            } else if (s[i] == '1' && hasZero == true) {  // 再次出现1
                return false;
            }
        }
        return true;
    }
};

class Solution1736 {  // 1736. 替换隐藏数字得到的最晚时间
   public:
    string maximumTime(string time) {
        string res;
        for (int i = 0; i < 5; ++i) {
            if (time[i] == '?') {
                if (i == 0) {
                    if (time[i + 1] < '4') {
                        res += string(1, '2');
                    } else {
                        res += string(1, '1');
                    }
                } else if (i == 1) {
                    if (time[i - 1] < '2') {
                        res += string(1, '9');
                    } else {
                        res += string(1, '3');
                    }
                } else if (i == 3) {
                    res += string(1, '5');
                } else if (i == 4) {
                    res += string(1, '9');
                }
            } else {
                res += string(1, time[i]);
            }
        }
        return res;
    }
};
void* my_memcpy_byte(void* dst, const void* src, int n) {
    if (dst == NULL || src == NULL || n <= 0) return NULL;

    char* pdst = (char*)dst;
    char* psrc = (char*)src;

    if (pdst > psrc && pdst < psrc + n) {
        pdst = pdst + n - 1;
        psrc = psrc + n - 1;
        while (n--) *pdst-- = *psrc--;
    } else {
        while (n--) *pdst++ = *psrc++;
    }
    return dst;
}

void* memcpy(void* dest, const void* src, int count) {
    if (dest == NULL || src == NULL || count < 0) {
        return NULL;
    }
    char* pdest = static_cast<char*>(dest);
    const char* psrc = static_cast<const char*>(src);
    if (pdest > psrc && pdest < psrc + count) {
        pdest = pdest + count - 1;
        psrc = psrc + count - 1;
        while (count--) {
            *pdest-- = *psrc--;
        }
    } else {
        while (count--) {
            *pdest++ = *psrc++;
        }
    }
    return pdest;
}
void* mymemcpy(void* dest, const void* src, size_t count) {
    if (dest == NULL || src == NULL) return NULL;
    char* pdest = static_cast<char*>(dest);
    const char* psrc = static_cast<const char*>(psrc);
    int n = count;

    if (pdest > psrc && pdest < psrc + count) {
        for (size_t i = n - 1; i != -1; --i) {
            pdest[i] = psrc[i];
        }
    } else {
        for (size_t i = 0; i < n; i++) {
            pdest[i] = psrc[i];
        }
    }

    return dest;
}

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* tail = head;
        while (head->next != nullptr) {
            head->next->next = head;
            head = head->next;
        }
        tail->next = nullptr;
        return head;
    }
};

class Solution1646 {  // 1646. 获取生成数组中的最大值
   public:
    int getMaximumGenerated(int n) { }
};

class Solution31 {
   public:
    void nextPermutation(vector<int>& nums) {
        // 1.从后往前找 a[i] < a[j]的i,这样从j到n就是下降序列
        // 2.然后在 区间[j,n]之间,从后往前找第一个大于a[i]的数,位置记为m,
        // 交换a[i]和a[m], 然后重排[j,n]
        int left = -1, right = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                left = i;
                break;
            }
        }
        if (left >= 0) {
            for (int i = n - 1; i > left; i--) {
                if (nums[i] > nums[left]) {
                    right = i;
                    std::swap(nums[left], nums[right]);
                    break;
                }
            }  
        }
        std::reverse(nums.begin() + left + 1, nums.end());
    }
};

class Solution94 {  // 94. 二叉树的中序遍历
   public:
    void inorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

class Solution19 {  // 19. 删除链表的倒数第 N 个结点
    // 双指针，l指向第一个节点，r指向第n个节点，当n指向最后一个节点的时候，r真好指向倒数第n和节点
   public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *left, *right, *pre;
        left = head;
        right = head;
        pre = left;
        while (--n) {
            if (right == nullptr) {
                return nullptr;
            }
            right = right->next;
        }
        while (right->next != nullptr) {
            pre = left;
            left = left->next;
            right = right->next;
        }
        if (pre == left) {
            return left->next;
        }
        pre->next = left->next;
        return head;
    }
};

class Solution22 {  // 22. 括号生成
   private:
    vector<string> res;

   public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return res;
        }
        getParenthesis("", n, n);
        return res;
    }

    void getParenthesis(string str, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }
        if (left == right) {
            //剩余左右括号数相等，下一个只能用左括号
            getParenthesis(str + "(", left - 1, right);
        } else if (left < right) {
            //剩余左括号小于右括号，下一个可以用左括号也可以用右括号
            if (left > 0) {
                getParenthesis(str + "(", left - 1, right);
            }
            getParenthesis(str + ")", left, right - 1);
        }
    }
};
class Solution33 {  // 33. 搜索旋转排序数组
   public:
    int binarySearch(vector<int> &nums, int left, int right, int target) {
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target) {
        int seg = 0, pre = nums[0];
        int leftArea, rightArea;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < pre) {
                seg = i;
                break;
            }
            pre = nums[i];
        }
        leftArea = binarySearch(nums, 0, seg - 1, target);
        rightArea = binarySearch(nums, seg, nums.size() - 1, target);
        if (leftArea != -1) {
            return leftArea;
        } else if (rightArea != -1) {
            return rightArea;
        }
        return -1;
    }
};

class Solution39 {  // 39. 组合总和
   public:
    void dfs(vector<int> &candidates, int target, vector<vector<int>> &ans,
             vector<int> &combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};
class Solution39_1 {
   public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ret;
        vector<int> now;
        int sum = 0, n = candidates.size();
        function<void(int)> dfs = [&](int back) {
            if (sum == target) {
                ret.emplace_back(begin(now), end(now));
            } else if (sum > target)
                return;
            else {
                for (int i = back; i != n; ++i) {
                    now.push_back(candidates[i]);
                    sum += candidates[i];
                    dfs(i);
                    sum -= candidates[i];
                    now.pop_back();
                }
            }
        };
        dfs(0);
        return ret;
    }
};

class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        stack[topIdx] = val;
        topIdx++;
        if (val < min) {
            min = val;
        }
    }

    void pop() {
        if (stack[topIdx - 1] == min) {
            min = INT_MAX;
            for (int i = 0; i < topIdx - 1; ++i) {
                if (stack[i] < min) {
                    min = stack[i];
                }
            }
        }
        topIdx--;
    }

    int top() { return stack[--topIdx]; }

    int getMin() { return min; }

   private:
    int stack[100];
    int max = INT_MIN;
    int min = INT_MAX;
    int topIdx = 0;
    int bottom = 0;
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != nullptr) {
            while (pb != nullptr) {
                if (pa == pb) {
                    return pa;
                }
                pb = pb->next;
            }
            pa = pa->next;
        }
        return nullptr;
    }
};

class Solution56 {  // 56. 合并区间
   public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        int left = intervals[0][0];
        for (int i = 1; i < intervals.size(); ++i) {
            while (i < intervals.size() &&
                   intervals[i][0] < intervals[i - 1][1]) {
                i++;
            }
            res.push_back({left, intervals[--i][1]});
            if (i < intervals.size() - 1) {
                left = intervals[i + 1][0];
            }
        }
        return res;
    }
};

class Solution987 {  // 987. 二叉树的垂序遍历
    // 先层序遍历
   public:
    struct Tnode {
        int row;
        int col;
        TreeNode *node;
        Tnode(int row, int col, TreeNode *node)
            : row(row), col(col), node(node){};
    };

    struct Point {
        int row;
        int val;
        Point(int row, int val) : row(row), val(val){};
    };

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        queue<Tnode> tQueue;
        map<int, vector<Point>> tMap;
        tQueue.push(Tnode(0, 0, root));
        vector<vector<int>> res;
        tMap[0].push_back(Point(0, root->val));
        while (!tQueue.empty()) {
            Tnode p = tQueue.front();
            tQueue.pop();
            if (p.node->left) {
                tMap[p.col - 1].push_back(Point(p.row + 1, p.node->left->val));
                tQueue.push(Tnode(p.row + 1, p.col - 1, p.node->left));
            }
            if (p.node->right) {
                tMap[p.col + 1].push_back(Point(p.row + 1, p.node->right->val));
                tQueue.push(Tnode(p.row + 1, p.col + 1, p.node->right));
            }
        }
        for (auto it = tMap.begin(); it != tMap.end(); ++it) {
            vector<Point> &vec = it->second;
            vector<int> temp;
            sort(vec.begin(), vec.end(), [](const Point &p1, const Point &p2) {
                if (p1.row == p2.row) {
                    return p1.val < p2.val;
                }
                return p1.row < p2.row;
            });
            for (auto &i : vec) {
                temp.push_back(i.val);
            }
            res.push_back(temp);
        }
        return res;
    }
};

class Solution987_1 {  // 987. 二叉树的垂序遍历
    // 前序遍历
   public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<tuple<int, int, int>> nodes;  // col ,row, val
        vector<vector<int>> res;
        function<void(TreeNode *, int, int)> dfs = [&](TreeNode *root, int row,
                                                       int col) {
            if (!root) {
                return;
            }
            nodes.emplace_back(col, row, root->val);
            dfs(root->left, row + 1, col - 1);
            dfs(root->right, row + 1, col + 1);
        };
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        int lastCol = INT_MAX;
        for (const auto &[col, row, val] : nodes) {
            if (lastCol != col) {
                lastCol = col;
                res.emplace_back();
            }
            res.back().push_back(val);
        }
        //    for (const auto &node : nodes) {
        //        if (lastCol != get<0>(node)) {
        //            lastCol = get<0>(node);
        //            res.emplace_back();
        //        }
        //        res.back().push_back(get<2>(node));
        //    }
        return res;
    }
};

class Solution1337 {  // 1337. 矩阵中战斗力最弱的 K 行
   public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        vector<tuple<int, int>> vec;  // 军人数, 行号
        vector<int> res;
        int row = mat.size();
        int col = mat[0].size();
        int sum, j = 0;
        for (int i = 0; i < row; ++i) {
            sum = j = 0;
            while (j < col && mat[i][j++] == 1) {
                sum++;
            }
            vec.emplace_back(sum, i);
        }
        sort(vec.begin(), vec.end());
        for (const auto &[i, row] : vec) {
            res.emplace_back(row);
        }
        return res;
    }
};

class Solution46 {  // 46. 全排列
   public:
    void backtrack(vector<vector<int>> &res, vector<int> &output, int first,
                   int len) {
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        int len = nums.size();
        function<void(vector<int> & output, int first)> backtrack =
            [&](vector<int> &output, int first) {
                if (first == len) {
                    res.emplace_back(output);
                    return;
                }
                for (int i = first; i < len; ++i) {
                    // 动态维护数组
                    swap(output[i], output[first]);
                    // 继续递归填下一个数
                    backtrack(output, first + 1);
                    // 撤销操作
                    swap(output[i], output[first]);
                }
            }; 
        backtrack(nums, 0);
        return res;
    }
};

class Solution581 { // 581. 最短无序连续子数组
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxn = INT_MIN;
        int minn = INT_MAX;
        int left = -1, right = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (maxn > nums[i]) { // 乱序位置
                right = i;
            } else {
                maxn = nums[i];
            }
            if (minn < nums[n - i - 1]) {
                left = n - i - 1;
            } else {
                minn = nums[n - i - 1];
            }

        }
        return left == -1 ? 0 : right - left + 1;
    }
};

class Solution169 { // 169. 多数元素
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (count == 0) {
                major = nums[i];

            }
            if (major == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        count = 0;
        for (const auto &i : nums) {
            if (major == i) {
                count++;
            }
        }
        return major;
    }
};

class Solution226 { // 226. 翻转二叉树
public:
    void invert(TreeNode* root) {
        if (!root) {
            return;
        }
        invert(root->left);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return nullptr;
        }
        invert(root->left);
        return root;
    }
};
int main() {
    Solution226 so;
    TreeNode *root = CreatTree({1, 2, 3});
    so.invert(root);
    return 0;
}