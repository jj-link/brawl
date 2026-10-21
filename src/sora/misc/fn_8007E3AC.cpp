extern int *lbl_805A0208;

#pragma force_active on
extern "C" {
void fn_8007E3AC(int *p) {
    if (lbl_805A0208 == 0) {
        lbl_805A0208 = p;
        *p = 0;
    }
}
}
#pragma force_active reset
