#pragma force_active on
extern "C" {
extern int lbl_804877E8[];

struct FnObj {
    void* unk0;
    short unk4;
    short unk6;
};

void fn_802D5D88(FnObj* arg0) {
    if (arg0 != 0) {
        arg0->unk6 = 1;
        arg0->unk0 = lbl_804877E8;
    }
}
}
