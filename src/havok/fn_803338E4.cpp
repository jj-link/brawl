#pragma force_active on
extern "C" int fn_803338E4(int arg0) {
    int ret = 0;
    unsigned int idx = arg0 - 0x14;
    if (idx <= 9) {
        if ((1 << idx) & 0x3C5) {
            ret = 1;
        }
    }
    return ret;
}
