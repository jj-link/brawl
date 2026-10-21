#pragma force_active on
extern int fn_80210118(void*, void*, int);
extern int lbl_8059EC90;
extern int lbl_805A0BD0;

void* fn_80210308(void) {
    if (fn_80210118(&lbl_8059EC90, &lbl_805A0BD0, 6)) {
        return &lbl_805A0BD0;
    }
    return 0;
}
