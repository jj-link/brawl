#pragma force_active on
struct fn27Obj {
    int pad[4];
    void* f10;
    void* f14;
};

struct fn27Pair {
    void* a;
    void* b;
};

extern "C" {
fn27Pair fn_27_B75E4(fn27Obj* p) {
    fn27Pair r = *(fn27Pair*)&p->f10;
    return r;
}
}
