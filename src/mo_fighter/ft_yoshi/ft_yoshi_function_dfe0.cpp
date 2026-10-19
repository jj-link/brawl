#pragma force_active on
typedef unsigned int u32;

struct Pair {
    u32 a;
    u32 b;
};

struct Holder {
    u32 pad[2];
    Pair pair;
};

extern "C" Pair fn_95_DFE0(Holder* p) {
    return p->pair;
}
