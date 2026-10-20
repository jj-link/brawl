#pragma force_active on
struct X {
    int a;
    int b;
    unsigned f : 9;
    unsigned g : 1;
};

extern "C" int fn_27_295C90(X* p) {
    return p->g;
}
