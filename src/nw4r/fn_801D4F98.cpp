#pragma force_active on
struct Obj { char pad[0x8c]; unsigned char flag; };
extern "C" unsigned int fn_801D4F98(Obj* o) {
    unsigned int v = o->flag;
    return (unsigned int)(-v | v) >> 31;
}
