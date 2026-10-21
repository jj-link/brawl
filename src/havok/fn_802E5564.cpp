#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern char lbl_80488100[];

struct FnObj {
    void* unk0;
    u8 pad[2];
    u16 unk6;
};

extern "C" {
void fn_802E5564(FnObj* arg0) {
    if (arg0 != 0) {
        arg0->unk6 = 1;
        arg0->unk0 = lbl_80488100;
    }
}
}
