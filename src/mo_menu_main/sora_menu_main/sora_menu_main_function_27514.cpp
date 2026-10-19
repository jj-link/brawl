#pragma force_active on
struct Entry {
    int pad0;
    int key;
    unsigned char flag;
};

extern "C" int fn_2_27514(Entry* a, Entry* b) {
    int d = a->key;
    d = b->key - d;
    if (d != 0) {
        return d;
    }
    return a->flag - b->flag;
}
