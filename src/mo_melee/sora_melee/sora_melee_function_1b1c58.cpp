#pragma force_active on
struct A {
    int a;
    int b;
    unsigned : 10;
    int v : 5;
};

extern "C" int fn_27_1B1C58(A* p) {
    return p->v;
}
