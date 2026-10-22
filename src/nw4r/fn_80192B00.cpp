#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern "C" int __cntlzw(unsigned int);

struct Obj {
    char pad0[0x10];
    s32 unk10;
    char pad1[4];
    u32 flags18;
    u16 unk1C;
    u16 unk1E;
    s32 unk20;
    s32 unk24;
    f32 unk28;
    f32 unk2C;
};

extern "C" s32 fn_80192B00(Obj** a0, void** a1, u16* a2, u16* a3, s32* a4, f32* a5, f32* a6, u8* a7) {
    Obj* o = *a0;
    if (!(o->flags18 & 1)) {
        return 0;
    }
    if (a1 != 0) {
        *a1 = o->unk10 ? (void*)((char*)o + o->unk10) : 0;
    }
    if (a2 != 0) {
        *a2 = (*a0)->unk1C;
    }
    if (a3 != 0) {
        *a3 = (*a0)->unk1E;
    }
    if (a4 != 0) {
        *a4 = o->unk20;
    }
    if (a5 != 0) {
        *a5 = o->unk28;
    }
    if (a6 != 0) {
        *a6 = o->unk2C;
    }
    if (a7 != 0) {
        u32 t = o->unk24;
        *a7 = (u8)((t << __cntlzw(t ^ 1)) >> 31);
    }
    return 1;
}
