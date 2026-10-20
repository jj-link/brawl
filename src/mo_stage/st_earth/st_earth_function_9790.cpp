#pragma force_active on
struct Foo {
    int x;
    int y;
    int pad : 2;
    int state : 2;
};

extern "C" int fn_66_9790(Foo *p) {
    return p->state;
}
