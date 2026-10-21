#pragma force_active on
extern "C" {
extern int lbl_80408488[];
int fn_800C9B00(unsigned int idx) {
    return lbl_80408488[idx << 1];
}
}
