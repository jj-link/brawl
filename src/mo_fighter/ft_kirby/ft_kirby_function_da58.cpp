#pragma force_active on
extern "C" void fn_96_1D994(void* self, int a, float b, int c, int d, float e, float f);
extern "C" void fn_27_135848(void* self, int a, float b, int c, int d, float e, float f, int g);

extern "C" void fn_96_DA58(void* self, int a, float b, int c, int d, float e, float f, int g) {
    if (c != 0) {
        fn_96_1D994(reinterpret_cast<unsigned char*>(self) + 0x20000 - 0x48d4, a, b, c, d, e, f);
    }
    fn_27_135848(self, a, b, c, d, e, f, g);
}
