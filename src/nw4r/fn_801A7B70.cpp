#pragma force_active on
extern "C" void fn_801A7B70(char** self, float* out0, float* out1, float* out2, float* out3, float* out4, float* out5) {
    char* p = *self;
    if (p != 0) {
        if (out0 != 0) {
            *out0 = *(float*)(p + 0xdc);
        }
        if (out1 != 0) {
            *out1 = *(float*)(p + 0xe0);
        }
        if (out2 != 0) {
            *out2 = *(float*)(p + 0xe4);
        }
        if (out3 != 0) {
            *out3 = *(float*)(p + 0xe8);
        }
        if (out4 != 0) {
            *out4 = *(float*)(p + 0xec);
        }
        if (out5 != 0) {
            *out5 = *(float*)(p + 0xf0);
        }
    }
}
