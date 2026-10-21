#pragma force_active on
struct Obj {
    unsigned char pad[0x24];
    unsigned char* base;
};

extern "C" {
unsigned int fn_8004DA94(Obj* o, int idx) {
    unsigned int v = (o->base + idx)[0x820];
    return (unsigned int)(-v | v) >> 31;
}
}
