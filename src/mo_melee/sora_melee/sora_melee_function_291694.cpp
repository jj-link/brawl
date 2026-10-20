#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} Obj;

extern "C" s32 fn_27_291694(Obj* p) {
    return (s32)(((p->unk8 >> 23) & 0x1F) << 27) >> 28;
}
