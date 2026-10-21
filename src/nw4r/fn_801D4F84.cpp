#pragma force_active on
struct Fn801Obj {
    char pad[0x8d];
    unsigned char flag;
};

extern "C" {
unsigned int fn_801D4F84(Fn801Obj* o) {
    unsigned int v = o->flag;
    return (unsigned int)(-v | v) >> 31;
}
}
