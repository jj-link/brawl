#pragma force_active on

extern "C" void fn_802872F4(void *out, const void *in);

extern "C" void fn_802FCC94(char *arg0, char *arg1) {
    *(int *)(arg1 + 0x0) = *(int *)(arg0 + 0x4);
    *(int *)(arg1 + 0x4) = *(int *)(arg0 + 0x0);
    *(int *)(arg1 + 0x8) = *(int *)(arg0 + 0x8);
    *(int *)(arg1 + 0xC) = *(int *)(arg0 + 0xC);
    *(float *)(arg1 + 0x60) = -*(float *)(arg0 + 0x60);
    *(float *)(arg1 + 0x64) = -*(float *)(arg0 + 0x64);
    *(float *)(arg1 + 0x68) = -*(float *)(arg0 + 0x68);
    *(float *)(arg1 + 0x6C) = *(float *)(arg0 + 0x6C);
    fn_802872F4(arg1 + 0x10, arg0 + 0x10);
}
