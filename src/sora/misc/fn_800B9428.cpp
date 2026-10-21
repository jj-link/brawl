#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

struct Ent {
    u32 pad : 4;
    u32 mode : 2;
    u32 rest : 26;
};

extern "C" void fn_800B9428(u8* arg0, s32 arg1, f32 farg0) {
    Ent* p = (Ent*)(*(u8**)(arg0 + 0xC) + arg1 * 0x48);
    p->mode = 2;
    *(f32*)((u8*)p + 0x1C) = farg0;
}
