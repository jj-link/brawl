#pragma force_active on
extern "C" void fn_80190540(void*, unsigned int, int, int, int);
extern "C" void fn_8019E150(void*, unsigned int);
extern "C" void fn_801D7774(void*, unsigned int);
extern "C" void fn_80190840(unsigned char** self, unsigned char count) {
    unsigned char* data;
    if (count >= 1U && count <= 16U) {
        data = *self;
        if (data[0xC] > count) {
            unsigned char* p;
            int i;
            for (unsigned int i = count; i < data[0xC]; ++i) {
                fn_80190540(self, i, 255, 255, 255);
            }
            i = (count + 1) / 2;
            p = data + 0x80 + i * 0x30;
            for (; (unsigned int)i < (data[0xC] + 1U) / 2; p += 0x30, ++i) {
                fn_8019E150(p, 0x30);
                fn_801D7774(p, 0x30);
            }
        }
        data[0xC] = count;
    }
}
