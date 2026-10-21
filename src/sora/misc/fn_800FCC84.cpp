#pragma force_active on
struct Inner {
    int a;
    int b;
    int c;
    int d;
};

struct Outer {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    Inner* g;
};

extern "C" int fn_800FCC84(Outer* o) {
    return o->g->d;
}
