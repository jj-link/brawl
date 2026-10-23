#pragma force_active on
extern "C" void fn_800DDB54(void*);
extern "C" void fn_800DDCF8(void*, void*);

extern "C" void fn_800DDA50(unsigned char* self, unsigned int a1, int a2,
                           int a3, void* a4, unsigned int a5) {
    union Value {
        unsigned int word;
        struct {
            unsigned int high : 26;
            unsigned int option : 1;
            unsigned int low : 5;
        } bits;
    } value;

    value.word = self[0];
    *(unsigned int*)(self + 0x8) = a1;
    value.word &= 0xFFFFFF1F;
    *(unsigned int*)(self + 0xC) = a5;
    self[0] = (unsigned char)value.word;

    if (a2 != 0) {
        value.word &= 0xFF;
        value.word |= 0x80;
        value.bits.option = a3;
        self[0] = (unsigned char)value.word;
        if (a2 == 2) {
            value.word = (value.word & 0xFF) | 0x40;
            self[0] = (unsigned char)value.word;
        }
    }

    if ((self[0] >> 7) & 1) {
        fn_800DDB54(self);
        fn_800DDCF8(self, a4);
    }

    *(unsigned int*)(self + 0x4) = 0;
}
