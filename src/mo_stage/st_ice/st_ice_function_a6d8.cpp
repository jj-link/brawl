#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int pad : 12;
    unsigned int flag : 1;
};

extern "C" unsigned int fn_62_A6D8(S* s) {
    return s->flag;
}
