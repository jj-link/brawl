#pragma force_active on
extern "C" int fn_800B5854(void* p, int a, int b, int c, int d);

extern "C" void fn_10_F2D0(unsigned char* self, unsigned int value) {
    if (self[0x5ec] != value) {
        if (*(int*)(self + 0x5e8) == 2) {
            fn_800B5854(*(void**)(self + 0x3c4), (value != 0) + 1, 0x11, 1, 0);
        }
        self[0x5ec] = (unsigned char)value;
    }
}
