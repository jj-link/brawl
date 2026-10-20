#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct AiFighterState {
    u8 pad0[0x54];
    u32 unk54;
    u8 pad58[0x162];
    u8 unk1BA;
};

extern "C" int fn_27_20B63C(AiFighterState* self) {
    if (self->unk1BA == 1)
        return 1;
    return (self->unk54 & 0x99) == 0x99;
}
