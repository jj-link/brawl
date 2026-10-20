#pragma force_active on
struct X {
    int a;
    int b;
    int f0 : 4;
    int f1 : 4;
    int f2 : 24;
};
extern "C" int fn_73_A04C(struct X* s) { return s->f1; }
