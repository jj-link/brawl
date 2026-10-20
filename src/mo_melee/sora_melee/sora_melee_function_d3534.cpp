#pragma force_active on
struct FooObj {
    char pad[8];
    unsigned int a : 6;
    unsigned int b : 3;
    unsigned int c : 23;
};

extern "C" {
void fn_27_D3534(FooObj* p, unsigned int v) {
    p->b = v;
}
}
