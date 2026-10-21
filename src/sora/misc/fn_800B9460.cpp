#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct MuMsg {
    char pad0[0xC];
    void *unkC;
};

struct MuMsgEntry {
    char pad0[0x18];
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    char pad1C[4];
    float unk20;
};

extern "C" void FUN_800b9460__5MuMsgFUlUcUcUcf(MuMsg *self, u32 arg0, u8 arg1, u8 arg2, u8 arg3, float arg4)
{
    MuMsgEntry *e = (MuMsgEntry *)((char *)self->unkC + arg0 * 0x48);
    e->unk20 = arg4;
    e->unk18 = arg1;
    e->unk19 = arg2;
    e->unk1A = arg3;
    e->unk1B = 0xFF;
}
