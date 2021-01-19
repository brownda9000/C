#include <cassert>
#include <vector>

int dot( const std::vector<int> &a,
         const std::vector<int> &b) {
    int sum;
    assert(a.size() == b.size());

    for (int i=0; i < a.size(); ++i) {
        sum += a[i] * b[i];
    }

    return sum;
}

int main() {

    return 0;
}