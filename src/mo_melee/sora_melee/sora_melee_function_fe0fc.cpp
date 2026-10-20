#pragma force_active on
typedef unsigned int u32;
typedef signed short s16;

struct FE0FCOut {
    u32 unk0;
    u32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" void fn_27_FE0FC(FE0FCOut* out, u32* src, u32 val, s16* half, s16 half2) {
    src = (u32*)*src;
    s16 h = *half;
    out->unk0 = (u32)src;
    out->unk4 = val;
    out->unk8 = h;
    out->unkA = half2;
}
