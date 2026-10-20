#pragma force_active on
struct S {
    int a;
    int b;
    int c;
};

extern "C" int fn_27_19A37C(S *p) {
    return p->c >> 30;
}
