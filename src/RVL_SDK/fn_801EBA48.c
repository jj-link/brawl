#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 pad13;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
} Arg;

void fn_801EA098(int);
void fn_801EA4E4(int, unsigned char *, int);

void fn_801EBA48(Arg *arg0) {
    unsigned char buf[34];

    buf[0] = 0x10;
    buf[1] = (u8)((unsigned int)arg0->unk0 >> 8);
    buf[2] = (u8)arg0->unk0;
    buf[3] = (u8)((unsigned int)arg0->unk2 >> 8);
    buf[4] = (u8)arg0->unk2;
    buf[5] = (u8)((unsigned int)arg0->unk4 >> 8);
    buf[6] = (u8)arg0->unk4;
    buf[7] = (u8)((unsigned int)arg0->unk6 >> 8);
    buf[8] = (u8)arg0->unk6;
    buf[9] = (u8)((unsigned int)arg0->unk8 >> 8);
    buf[10] = (u8)arg0->unk8;
    buf[11] = (u8)((unsigned int)arg0->unkA >> 8);
    buf[12] = (u8)arg0->unkA;
    buf[13] = arg0->unkC;
    buf[14] = arg0->unkD;
    buf[15] = arg0->unkE;
    buf[16] = arg0->unkF;
    buf[17] = arg0->unk10;
    buf[18] = arg0->unk11;
    buf[19] = arg0->unk12;
    buf[20] = (u8)((unsigned int)arg0->unk14 >> 8);
    buf[21] = arg0->unk14 & 0xC0;
    buf[22] = (u8)((unsigned int)arg0->unk16 >> 8);
    buf[23] = arg0->unk16 & 0xC0;
    buf[24] = (u8)((unsigned int)arg0->unk18 >> 8);
    buf[25] = arg0->unk18 & 0xC0;
    buf[26] = (u8)((unsigned int)arg0->unk1A >> 8);
    buf[27] = arg0->unk1A & 0xC0;
    buf[28] = (u8)((unsigned int)arg0->unk1C >> 8);
    buf[29] = arg0->unk1C & 0xC0;
    buf[30] = (u8)((unsigned int)arg0->unk1E >> 8);
    buf[31] = arg0->unk1E & 0xC0;
    buf[32] = (u8)((unsigned int)arg0->unk20 >> 8);
    buf[33] = arg0->unk20 & 0xC0;

    fn_801EA4E4(0xE0, buf, 0x22);
    fn_801EA098(2);
}
