#pragma force_active on
typedef struct Foo {
    int a;
    int b;
    int c : 2;
    int d : 2;
    int e : 28;
} Foo;

extern "C" int fn_74_6954(Foo *f) {
    return f->d;
}
