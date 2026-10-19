#pragma force_active on
struct S {
    int a, b;
    int f0 : 3;
    int f1 : 3;
    int rest : 26;
};
extern "C" int fn_54_5A2C(S* s) {
    return s->f1;
}
