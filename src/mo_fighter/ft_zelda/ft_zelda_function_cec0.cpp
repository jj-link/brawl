#pragma force_active on
typedef struct Pair {
    void* first;
    void* second;
} Pair;

typedef struct Holder {
    unsigned char pad[8];
    Pair pair;
} Holder;

extern "C" Pair fn_104_CEC0(const Holder* p) {
    return p->pair;
}
