#pragma force_active on
extern "C" {
extern int lbl_8042BDC0[];

int fn_8004F964(unsigned int index) {
    return lbl_8042BDC0[index];
}
}
