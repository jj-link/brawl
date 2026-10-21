#pragma force_active on
struct UnkObj {
    int filler[8];
};
extern UnkObj lbl_80487F30;

struct S {
    UnkObj* unk0;
    short unk4;
    short unk6;
};

extern "C" void fn_802E37E0(S* arg0) {
    if (arg0 != 0) {
        arg0->unk6 = 1;
        arg0->unk0 = &lbl_80487F30;
    }
}
