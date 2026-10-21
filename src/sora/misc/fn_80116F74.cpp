#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

struct Obj {
    unsigned char pad[0x10];
    u16 unk10;
    u8 unk12;
    u8 unk13;
    unsigned char pad2[0x6];
    u16 unk1A;
};

extern "C" {
void fn_80116F74(struct Obj* arg0) {
    arg0->unk10 = 0;
    arg0->unk12 = 7;
    arg0->unk13 = arg0->unk13 | 0x80;
    arg0->unk1A = 0;
}
}
