#pragma force_active on
struct Entry {
    int value;
    unsigned int key;
};

extern "C" int fn_2_1E6E8(void*, Entry* p, int n, int target) {
    if (target > 0) {
        int count = 1;
        int i = 0;
        unsigned int key = p->key;
        for (; i < n; ++i, ++p) {
            if (key != p->key) ++count;
            if (count == target) break;
        }
        if (i >= n) return 35;
        if (i < n - 1 && p->key == p[1].key) return 35;
        return p->value;
    } else {
        int goal = -target;
        int count = 1;
        int i = n - 1;
        Entry* q = p + n - 1;
        unsigned int key = q->key;
        for (; i >= 0; --i, --q) {
            if (key != q->key) ++count;
            if (count == goal) break;
        }
        if (i < 0) return 35;
        if (i > 0 && q->key == q[-1].key) return 35;
        return q->value;
    }
}
