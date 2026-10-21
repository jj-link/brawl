#pragma force_active on
extern "C" {
extern const unsigned int lbl_80423640[];

unsigned int fn_8003A224(int unused, int idx) {
    return lbl_80423640[unused + idx];
}
}
