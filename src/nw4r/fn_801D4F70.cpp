#pragma force_active on
struct Obj {
    unsigned char pad[0x8e];
    unsigned char flag;
};

extern "C" {
unsigned int fn_801D4F70(Obj* o) {
    unsigned int v = o->flag;
    return (unsigned int)(-v | v) >> 31;
}
}
