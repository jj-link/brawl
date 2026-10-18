#pragma force_active on
extern "C" {
void* fn_10_1B448(char* self, int* out0, float* out1) {
    if (out0 != 0) {
        *out0 = *(int*)(self + 0xb0);
    }
    if (out1 != 0) {
        out1[0] = *(float*)(self + 0xb4);
        out1[1] = *(float*)(self + 0xb8);
        out1[2] = *(float*)(self + 0xbc);
        out1[3] = *(float*)(self + 0xc0);
    }
    return *(void**)(self + 0xac);
}
}
