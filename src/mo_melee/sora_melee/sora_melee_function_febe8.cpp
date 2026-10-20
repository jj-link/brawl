#pragma force_active on
struct S {
    int _0;
    int _4;
    unsigned int x : 6;
    unsigned int y : 1;
};
extern "C" int fn_27_FEBE8(const S *p) {
    return p->y;
}
