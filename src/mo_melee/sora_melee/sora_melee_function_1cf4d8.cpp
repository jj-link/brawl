#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef short s16;

struct FnData {
    u32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unka;
};

extern "C" {
void fn_27_1CF4D8(FnData* dst, const u32* src, s32 val, const s16* half, s16 half2) {
    dst->unk0 = *src;
    dst->unk4 = val;
    dst->unk8 = *half;
    dst->unka = half2;
}
}
