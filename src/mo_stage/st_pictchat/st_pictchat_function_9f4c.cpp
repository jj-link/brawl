#pragma force_active on
struct S {
    int a;
    int b;
    int : 3;
    int c : 3;
    int : 26;
};

extern "C" int fn_73_9F4C(struct S *p) {
    return p->c;
}
