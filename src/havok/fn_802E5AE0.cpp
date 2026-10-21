#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

struct UnkObj {
    void* unk0;
    u16 unk4;
    u16 unk6;
};

extern "C" {
extern u8 lbl_80488170[];

void fn_802E5AE0(UnkObj* arg0) {
    if (arg0 != 0) {
        arg0->unk6 = 1;
        arg0->unk0 = lbl_80488170;
    }
}
}
