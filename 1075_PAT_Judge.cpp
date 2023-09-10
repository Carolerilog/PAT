#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct stu {
    vector<int> scores;
    unordered_set<int> compile_failure_problems;
    int id;
    int total_score{0};
    int num_perfect_problems{0};
};

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    
    vector<int> full_score(k);
    for(int& score : full_score) {
        scanf("%d", &score);
    }

    vector<stu> status_list(n);

    for(int i = 0; i < m; i++) {
        int id, p, s;
        scanf("%d%d%d", &id, &p, &s);
        id--;
        p--;

        if(status_list[id].scores.size() == 0) {
            status_list[id].id = id;
            status_list[id].scores = vector<int>(k, -1);
        }

        if(s == -1) {
            status_list[id].compile_failure_problems.insert(p);
        }

        status_list[id].scores[p] = max(status_list[id].scores[p], s);
    }

    int size = status_list.size();
    for(int i = 0; i < size; i++) {
        auto& stu = status_list[i];
        bool flag = false;

        for(int i = 0; i < stu.scores.size(); i++) {
            if(stu.scores[i] > -1) {
                flag = true;
                stu.total_score += stu.scores[i];
                stu.num_perfect_problems += stu.scores[i] == full_score[i] ? 1 : 0;
            }
        }

        if(!flag) {
            swap(stu, status_list.back());
            status_list.pop_back();
            size--;
            i--;
        } else {
            for(int p : stu.compile_failure_problems) {
                if(stu.scores[p] == -1) {
                    stu.scores[p] = 0;
                }
            }
        }
    }

    sort(status_list.begin(), status_list.end(), [](stu const& a, stu const& b) {
        if(a.total_score > b.total_score) {
            return true;
        } else if(a.total_score == b.total_score) {
            if(a.num_perfect_problems > b.num_perfect_problems) {
                return true;
            } else if(a.num_perfect_problems == b.num_perfect_problems) {
                return a.id < b.id;
            }
        }

        return false;
    });

    int rank = 1;
    int score = status_list[0].total_score;
    int count = 0;

    for(auto& stu : status_list) {
        if(stu.total_score != score) {
            rank += count;
            count = 0;
            score = stu.total_score;
        }

        count++;
        printf("%d %05d %d", rank, stu.id + 1, stu.total_score);

        for(int score : stu.scores) {
            if(score == -1) {
                printf(" -");
            } else {
                printf(" %d", score);
            }
        }

        printf("\n");
    }

    return 0;
}