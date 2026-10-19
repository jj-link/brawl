#pragma force_active on
extern "C" int fn_41_44194(float f1) {
    int ret = 1;
    unsigned int bits = *(unsigned int*)&f1;
    if ((bits >> 23 & 0xFF) == 0xFF) {
        ret = 0;
    }
    return ret;
}
