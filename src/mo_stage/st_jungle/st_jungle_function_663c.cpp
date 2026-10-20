#pragma force_active on
struct Outer {
    int a;
    int b;
    struct { int x : 2; int y : 2; int z : 28; } f;
};

extern "C" int fn_51_663C(struct Outer *obj) {
    return obj->f.y;
}
