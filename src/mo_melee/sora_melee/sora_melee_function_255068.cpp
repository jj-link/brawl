#pragma force_active on
extern unsigned char lbl_8059E742;
extern unsigned char lbl_8059E745;

extern "C" {
int fn_27_255068() {
    int ret = 0;
    unsigned char a = lbl_8059E742;
    unsigned char b = lbl_8059E745;
    if (a == b) {
        if (a != 0xFF) {
            ret = 1;
        }
    }
    return ret;
}
}
