#pragma force_active on

typedef int s32;
typedef unsigned char u8;

struct UnkStruct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
};

extern "C" {
void fn_801C6AC0(UnkStruct* p) {
    p->unk0 = -1;
    p->unk4 = 0;
    p->unk8 = 1;
    p->unk9 = 0x80;
}
}
