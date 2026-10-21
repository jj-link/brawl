#pragma force_active on
extern "C" void fn_802B2A24(unsigned char* self, short val) {
    unsigned char n = self[0x32];
    unsigned char* e = self;
    for (int i = 0; i < n; i++) {
        if (*(unsigned short*)(e + 0x36) == 0xFFFF) {
            *(short*)(self + i * 8 + 0x36) = val;
            return;
        }
        e += 8;
    }
}
