#pragma force_active on
struct S {
    int _0;
    int _4;
    unsigned int a : 9;
    unsigned int y : 1;
};

extern "C" int fn_27_19D6BC(const S *p) {
    return p->y;
}
