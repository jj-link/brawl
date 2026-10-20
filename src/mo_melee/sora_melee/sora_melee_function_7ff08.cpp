#pragma force_active on
struct Obj {
    int a;
    int b;
    int c;
};

extern "C" {
Obj* fn_27_7FF08() {
    Obj o;
    o.a = -1;
    o.b = -1;
    o.c = 0;
    return &o;
}
}
