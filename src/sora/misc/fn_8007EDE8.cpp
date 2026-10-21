#pragma force_active on
extern "C" {
int fn_801F6524(void*);
extern char lbl_8049DDF0[];
extern unsigned char lbl_805A024C;

void fn_8007EDE8(void) {
    if (lbl_805A024C != 0) {
        fn_801F6524(lbl_8049DDF0);
        lbl_805A024C = 0;
    }
}
}
