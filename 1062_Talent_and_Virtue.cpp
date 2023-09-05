#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct person {
    int id;
    int virtue;
    int talent;
};

int main() {
    int n, l, h;
    scanf("%d%d%d", &n, &l, &h);

    vector<person> sages;
    vector<person> noblemen;
    vector<person> foolmen;
    vector<person> smallmen;

    for(int i = 0; i < n; i++) {
        person p;
        scanf("%d%d%d", &p.id, &p.virtue, &p.talent);

        if(p.virtue < l || p.talent < l) {
            continue;
        }

        if(p.virtue >= h && p.talent >= h) {
            sages.push_back(p);
        } else if(p.virtue >= h && p.talent < h) {
            noblemen.push_back(p);
        } else if(p.virtue < h && p.virtue >= p.talent) {
            foolmen.push_back(p);
        } else if(p.virtue < p.talent) {
            smallmen.push_back(p);
        }
    }

    auto cmp = [] (person const& a, person const& b) {
        int tot_a = a.talent + a.virtue;
        int tot_b = b.talent + b.virtue;

        if(tot_a == tot_b) {
            if(a.virtue == b.virtue) {
                return a.id < b.id;
            } else {
                return a.virtue > b.virtue;
            }
        } else {
            return tot_a > tot_b;
        }
    };

    sort(sages.begin(), sages.end(), cmp);
    sort(noblemen.begin(), noblemen.end(), cmp);
    sort(foolmen.begin(), foolmen.end(), cmp);
    sort(smallmen.begin(), smallmen.end(), cmp);

    printf("%lu\n", sages.size() + noblemen.size() + foolmen.size() + smallmen.size());
    
    auto print_p = [] (person const& p) {
        printf("%08d %d %d\n", p.id, p.virtue, p.talent);
    };

    for(auto& p : sages) {
        print_p(p);
    }

    for(auto& p : noblemen) {
        print_p(p);
    }

    for(auto& p : foolmen) {
        print_p(p);
    }

    for(auto& p : smallmen) {
        print_p(p);
    }

    return 0;
}