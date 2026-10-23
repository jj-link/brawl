#pragma force_active on
int fn_8039B160(void *arg0, int *arg1) {
    unsigned char val = *(unsigned char *)((char *)arg0 + 0xC9);
    int ret = 0;
    *arg1 = (int)val;
    if (val > 2U)
        ret = -14;
    return ret;
}
