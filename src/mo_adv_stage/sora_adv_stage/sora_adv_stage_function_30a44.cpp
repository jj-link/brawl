#pragma force_active on
struct Fn40Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
int fn_40_30A44(Fn40Obj* p) {
    unsigned int v = (p->flags >> 21) & 0x3f;
    return ((int)(v << 26)) >> 27;
}
}
