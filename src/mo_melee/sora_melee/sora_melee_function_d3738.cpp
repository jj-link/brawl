#pragma force_active on
struct Foo {
    int a;
    int b;
    unsigned int p : 5;
    int v : 5;
    unsigned int r : 22;
};

extern "C" int fn_27_D3738(Foo *obj) {
    return obj->v;
}
