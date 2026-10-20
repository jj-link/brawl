#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct ftSample {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_CD874(ftSample* p) {
    return (s32)((p->unk8 >> 25 & 7) << 29) >> 30;
}
