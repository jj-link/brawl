#pragma force_active on
extern void fn_8035A4FC(void*);
extern void* lbl_805A10F0;

void fn_80385CC4(void) {
    if (lbl_805A10F0 != 0) {
        fn_8035A4FC(lbl_805A10F0);
        lbl_805A10F0 = 0;
    }
}
