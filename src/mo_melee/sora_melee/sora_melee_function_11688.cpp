#pragma force_active on
struct Inner {
    char pad[0x3c];
    float v;
};

struct Outer {
    char pad[0x28];
    Inner* inner;
};

extern "C" {
void fn_27_11688(Outer* self, float v) {
    Inner* p = self->inner;
    if (p) {
        p->v = v;
    }
}
}
