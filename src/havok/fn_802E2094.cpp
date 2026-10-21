#pragma force_active on
extern char lbl_80487E98[];

struct Obj {
    void* unk0;
    unsigned char pad4[2];
    unsigned short unk6;
};

extern "C" {
void fn_802E2094(Obj* arg0) {
    if (arg0 != 0) {
        arg0->unk6 = 1;
        arg0->unk0 = lbl_80487E98;
    }
}
}
