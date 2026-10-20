#pragma force_active on
struct Triple {
    int a;
    int b;
    int c;
};

struct Outer {
    int h0;
    int h1;
    Triple t;
};

extern "C" void fn_27_2B4AB4(Triple* dst, const Outer* src) {
    *dst = src->t;
}
