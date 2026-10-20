#pragma force_active on
struct S {
    int a;
    int b;
    unsigned : 4;
    signed c : 2;
};

extern "C" int fn_74_6B18(struct S *p) {
    return p->c;
}
