#pragma force_active on
struct fn27_S {
    int pad[2];
    unsigned int hi : 6;
    int f : 6;
    unsigned int lo : 20;
};

extern "C" {
int fn_27_AC2E0(fn27_S* p) {
    return p->f;
}
}
