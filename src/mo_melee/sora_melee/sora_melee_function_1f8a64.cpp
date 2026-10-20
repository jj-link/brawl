#pragma force_active on
struct fn27Pair {
    unsigned int hi;
    unsigned int lo;
};

struct fn27Struct {
    char pad[0x10];
    fn27Pair pair;
};

extern "C" {
fn27Pair fn_27_1F8A64(fn27Struct* p) {
    return p->pair;
}
}
