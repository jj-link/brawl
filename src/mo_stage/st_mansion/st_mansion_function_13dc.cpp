#pragma force_active on
extern "C" int fn_47_13DC(unsigned char* self, void* unused, int* out1, int* out2) {
    unsigned char i;
    if (self[0x26a] == 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        unsigned char* p = self + (unsigned char)i;
        if (p[0x24c] == 1) {
            *out1 = 6;
            *out2 = 3;
            return 1;
        }
    }
    return 0;
}
