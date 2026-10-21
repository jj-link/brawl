#pragma force_active on
struct fnS {
    float f[18];
    float arr[4];
};

extern "C" float fn_801BC460(fnS* p1, unsigned int p2) {
    return p1->arr[p2];
}
