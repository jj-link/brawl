#pragma force_active on
extern "C" {
extern int *lbl_805A01F8;

void fn_8007BCA0(int *arg0) {
    if (lbl_805A01F8 == 0) {
        lbl_805A01F8 = arg0;
        *arg0 = 0;
        *(int *)((char *)lbl_805A01F8 + 0x7F4) = 0;
        *(int *)((char *)lbl_805A01F8 + 0x7F8) = 0;
        *(int *)((char *)lbl_805A01F8 + 0x7FC) = 0;
        *(int *)((char *)lbl_805A01F8 + 0x800) = 0;
        *(int *)((char *)lbl_805A01F8 + 0x804) = 0;
    }
}
}
