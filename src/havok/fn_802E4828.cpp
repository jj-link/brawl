#pragma force_active on
extern char lbl_80488020[];

struct Fn828Obj {
    void* unk0;
    unsigned short unk4;
    short unk6;
};

extern "C" {
void fn_802E4828(Fn828Obj* arg0) {
    if (arg0 != 0) {
        arg0->unk6 = 1;
        arg0->unk0 = lbl_80488020;
    }
}
}
