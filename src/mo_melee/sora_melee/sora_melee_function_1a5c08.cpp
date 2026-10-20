#pragma force_active on
struct S {
    int a;
    int b;
    signed int c : 10;
};

extern "C" int fn_27_1A5C08(S* s) {
    return s->c;
}
