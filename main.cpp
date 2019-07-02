#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool sameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val &&
               sameTree(s->left, t->left) &&
               sameTree(s->right, t->right);
    }

    bool DFS(TreeNode* s, TreeNode* t) {
        if (sameTree (s, t)) return true;
        bool found = s->left ? DFS(s->left, t) : false;
        if (found) return true;
        return s->right ? DFS(s->right, t) : false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!t) return true;
        return DFS(s, t);
    }
};

void test1() {
    vector<int> v1{3, 4, 5, 1, 2};
    vector<int> v2{4, 1, 2};
    auto *t1 = new TreeNode(v1);
    auto *t2 = new TreeNode(v2);
    cout << "1 ? " << Solution().isSubtree(t1, t2) << endl;

}

void test2() {

}

void test3() {

}