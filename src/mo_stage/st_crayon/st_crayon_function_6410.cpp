#pragma force_active on
struct S {
    int pad0;
    int pad4;
    int a : 2;
    int b : 2;
    int c : 28;
};

extern "C" int fn_56_6410(S* s) {
    return s->b;
}
