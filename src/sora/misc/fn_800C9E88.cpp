extern "C" unsigned char fn_800C851C(void);

#pragma force_active on
extern "C" int fn_800C9E88(unsigned char* self, int arg1) {
    unsigned char idx;
    unsigned char* p;
    int ret;

    if (arg1 < 0 || arg1 >= 4) {
        return 0;
    }
    idx = fn_800C851C();
    if (idx == 0xFF) {
        idx = 4;
    }
    p = self + arg1 * 8;
    ret = 0;
    if (p[0x4C] == idx && !((p[0x51] >> 7) & 1)) {
        ret = 1;
    }
    return ret;
}
