#pragma force_active on
struct S {
    int a;
    int b;
    int c : 4;
    int d : 2;
    int e : 26;
};

extern "C" int fn_78_570C(S* s) {
    return s->d;
}
