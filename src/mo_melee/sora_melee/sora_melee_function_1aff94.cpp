#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_Obj {
    u32 unk0;
    u32 unk4;
    s32 unk8;
};

extern "C" {
void* fn_27_1AFF94(fn_27_Obj* p, s32 n) {
    s32 i = (p->unk8 >> 28) + n;
    if (i >= 4) {
        i -= 4;
    }
    return (char*)p + i * 12 + 12;
}
}
