#pragma force_active on
extern "C" const float lbl_71_rodata_188;

struct Obj {
    char pad[0x60];
    float a;
    float b;
    float c;
    char pad2[8];
    unsigned int flags;
};

extern "C" void fn_71_9E24(Obj* o) {
    unsigned int v = o->flags;
    float z = lbl_71_rodata_188;
    v = v & ~0x1Fu;
    o->a = z;
    o->b = z;
    o->c = z;
    o->flags = v;
}
