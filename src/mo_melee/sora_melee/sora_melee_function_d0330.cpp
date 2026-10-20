#pragma force_active on
struct X {
    int a;
    int b;
    int c;
};

extern "C" int fn_27_D0330(X* p) {
    return p->c >> 25;
}
