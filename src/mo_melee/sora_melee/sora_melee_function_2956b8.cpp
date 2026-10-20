#pragma force_active on
struct X {
    unsigned a;
    unsigned b;
    unsigned lo : 15;
    unsigned f : 1;
    unsigned rest : 16;
};
extern "C" unsigned fn_27_2956B8(const X *p) {
    return p->f;
}
