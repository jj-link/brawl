#pragma force_active on
extern "C" void fn_801B5E8C(char** self, int* out0, float* out1, float* out2, float* out3, float* out4, char* out5) {
    char* p = *self;
    if (p != 0) {
        if (out0 != 0) {
            *out0 = *(int*)(p + 0x0);
        }
        if (out1 != 0) {
            *out1 = *(float*)(p + 0x4);
        }
        if (out2 != 0) {
            *out2 = *(float*)(p + 0x8);
        }
        if (out3 != 0) {
            *out3 = *(float*)(p + 0xc);
        }
        if (out4 != 0) {
            *out4 = *(float*)(p + 0x10);
        }
        if (out5 != 0) {
            out5[0] = p[0x14];
            out5[1] = p[0x15];
            out5[2] = p[0x16];
            out5[3] = p[0x17];
        }
    }
}
