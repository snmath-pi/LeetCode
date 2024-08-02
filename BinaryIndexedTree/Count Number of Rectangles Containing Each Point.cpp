class BIT {
public:
    BIT(int size) : size(size) {
        tree = std::vector<std::vector<int>>(101, std::vector<int>(size + 1, 0));
    }

    void update(int x, int height, int delta) {
        while (x <= size) {
            tree[height][x] += delta;
            x += x & (-x);
        }
    }

    int query(int height, int x) {
        int tot = 0;
        while (x > 0) {
            tot += tree[height][x];
            x -= x & (-x);
        }
        return tot;
    }

private:
    int size;
    std::vector<std::vector<int>> tree;
};
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        std::unordered_map<int, int> c;
        int num = 1;
        std::set<int> s;

        for (const auto& x : rectangles) {
            s.insert(x[0]);
        }
        for (const auto& y : points) {
            s.insert(y[0]);
        }

        std::vector<int> li(s.begin(), s.end());
        for (const auto& x : li) {
            c[x] = num++;
        }

        BIT fenwick(num);
        for (const auto& x : rectangles) {
            fenwick.update(c[x[0]], x[1], 1);
        }
        std::vector<int> ans;
        for (const auto& y : points) {
            int result = 0;
            for (int height = y[1]; height < 101; ++height) {
                result += fenwick.query(height,num)-fenwick.query(height, c[y[0]]-1);
            }
            ans.push_back(result);
        }

        return ans;
    }
};
