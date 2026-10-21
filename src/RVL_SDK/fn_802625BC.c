#pragma force_active on
extern int fn_80262D98(void);

int fn_802625BC(void *arg0) {
    int result;
    unsigned char val;
    int t;
    result = fn_80262D98();
    if (result < 0) {
        return result;
    }
    val = *(unsigned char *)(((char *)arg0) + 0x1808);
    t = ~((val - 1) | (1 - val));
    return result & ~(t >> 31);
}
