#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    u8 pad6[2];
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} Packet;

extern Packet* fn_8022EFF8(int);
extern void fn_80242908(void*);

s32 fn_80246540(u8 arg0) {
    Packet* p = fn_8022EFF8(2);

    if (p == 0) {
        return 0;
    }

    p->unk2 = 4;
    p->unk4 = 0;
    p->unk8 = 0x22;
    p->unk9 = 0xC;
    p->unkA = 1;
    p->unkB = arg0;
    fn_80242908(p);
    return 1;
}
