#pragma force_active on

extern "C" {
int fn_80297A9C(void *arg0, int arg1) {
    int temp_r3 = *(int *)((char *)arg0 + 4);
    return arg1 + ((((temp_r3 << 2) - temp_r3)) * 0x30);
}
}
