#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        constexpr int dirs[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        vector<vector<int>> ans(m, vector<int>(n, -1));  
        int x = 0, y = 0, d = 0; 

        
        for (ListNode* curr = head; curr; curr = curr->next) {
            ans[x][y] = curr->val; 
            
            if (x + dirs[d][0] < 0 || x + dirs[d][0] == m || y + dirs[d][1] < 0 ||
                y + dirs[d][1] == n || ans[x + dirs[d][0]][y + dirs[d][1]] != -1) {
                d = (d + 1) % 4;
            }
            
            x += dirs[d][0];
            y += dirs[d][1];
        }

        return ans;
    }
};


void print_swirl(const vector<vector<int>>& ans) {
    cout << "[";
    for (const auto& row : ans) {
        cout << "[";
        for (auto it = row.begin(); it != row.end(); ++it) {
            cout << *it;
            if (it != row.end() - 1) cout << ",";
        }
        cout << "]";
        if (&row != &ans.back()) cout << ",";
    }
    cout << "]";
}

int main() {
    int m, n, num;
    cin >> m >> n >> num;

    
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < num; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
        }
        else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    Solution sol;
    vector<vector<int>> result = sol.spiralMatrix(m, n, head);

    print_swirl(result);

    return 0;
}
