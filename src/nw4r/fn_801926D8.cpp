#pragma force_active on
extern "C" void fn_801926D8(char** self, int* out0, int* out1, char* out2) {
    char* p = *self;
    if (out0 != 0) {
        *out0 = *(int*)(p + 0x14);
    }
    if (out1 != 0) {
        *out1 = *(int*)(p + 0x18);
    }
    if (out2 != 0) {
        *out2 = p[0x1c];
    }
}
