#pragma force_active on
struct S {
    int _0;
    int _4;
    unsigned int : 18;
    unsigned int v : 1;
};

extern "C" int fn_27_88D40(S* s) {
    return s->v;
}
