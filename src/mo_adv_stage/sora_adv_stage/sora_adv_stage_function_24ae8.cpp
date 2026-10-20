#pragma force_active on
typedef unsigned int u32;

struct SoraObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_40_24AE8(SoraObj* obj) {
    obj->flags &= ~0x02000000;
}
}
