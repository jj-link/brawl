#pragma force_active on
extern "C" {
struct Foo {
    int a;
    int b;
    int x : 7;
    int y : 7;
};
int fn_27_1D0C6C(Foo* p) {
    return p->y;
}
}
