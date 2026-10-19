#pragma force_active on
extern "C" int fn_61_2070(unsigned char* self, int* out1, int* out2, int* out3) {
    if (self[0xbe1] == 0)
        return 0;

    unsigned char value = self[0x1e0];
    if (value == 0 && self[0x1e1] == 6) {
        *out2 = 6;
        *out3 = 3;
        return 1;
    }

    self[0x1e1] = value;
    return 0;
}
