#pragma force_active on
typedef struct {
    int x;
    int y;
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} Foo;

extern "C" void fn_72_50C8(Foo *p, unsigned int v) {
    p->b = v;
}