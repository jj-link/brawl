#pragma force_active on
int fn_803AA56C(int arg0) {
    int val = __cntlzw(arg0);
    return -((val >> 5) & 1) & 0xA;
}
