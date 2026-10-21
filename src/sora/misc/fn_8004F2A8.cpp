#pragma force_active on
extern "C" {
extern int lbl_8042BC18[];

int fn_8004F2A8(unsigned int idx) {
    return lbl_8042BC18[idx];
}
}
