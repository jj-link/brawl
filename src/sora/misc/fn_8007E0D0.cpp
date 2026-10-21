#pragma force_active on
struct BigStruct {
    char pad[0x7F8];
    int unk7F8;
    int unk7FC;
};

extern "C" {

extern struct BigStruct *lbl_805A01F8;

void fn_8007E0D0(int *arg0, int *arg1) {
    *arg0 = lbl_805A01F8->unk7F8;
    *arg1 = lbl_805A01F8->unk7FC;
}

}
