#pragma force_active on
struct Inner {
    char pad[0x498];
    float f;
};
struct Outer {
    Inner* p;
};

extern "C" {
void fn_27_1125EC(Outer* o, float val) {
    o->p->f = val;
}
}
