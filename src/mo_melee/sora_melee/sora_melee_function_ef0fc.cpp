#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef short s16;

struct FnObj27 {
    u32 unk0;
    s32 unk4;
    u16 unk8;
    s16 unkA;
};

extern "C" void fn_27_EF0FC(FnObj27* p) {
    p->unk4 = -1;
    p->unk8 = 0;
    p->unkA = -1;
}
