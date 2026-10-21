#pragma force_active on
extern "C" {
extern unsigned char lbl_805A024C;
extern unsigned char lbl_8049DDF0[0xD8];
int DVDGetCommandBlockStatus(void*);

int fn_8007EDA0(void) {
    if (lbl_805A024C != 0 && DVDGetCommandBlockStatus(&lbl_8049DDF0) == 0) {
        return 1;
    }
    return 0;
}
}
