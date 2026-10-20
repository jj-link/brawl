#pragma force_active on
struct S {
    int a;
    int b;
    unsigned pad : 9;
    unsigned flag : 1;
    unsigned rest : 22;
};

extern "C" unsigned fn_72_BED0(S* s) {
    return s->flag;
}
