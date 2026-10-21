#pragma force_active on
struct Inner {
    int pad[22];
    int target;
};

struct Outer {
    int a;
    Inner* b;
};

extern "C" int fn_80111E78(Outer *o) {
    return o->b->target;
}
