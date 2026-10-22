#pragma force_active on
extern "C" void fn_802162A4(int, int);
extern "C" void fn_8021A558(int, int);

extern "C" void startMotor__11gfPadSystemFi(void* self, int arg) {
    unsigned char* p = (unsigned char*)self;
    if ((p[0x35] >> 6) & 1) {
        unsigned short flags = *(unsigned short*)(p + 0xB4A);
        if ((flags & (1 << arg)) == 0) {
            if (arg < 4) {
                fn_802162A4(arg, 1);
            } else {
                int val = *(int*)(p + arg * 64 + 0x480);
                if (val != 1) {
                    fn_8021A558(arg - 4, 1);
                }
            }
            *(unsigned short*)(p + arg * 2 + 0xB58) = 0xFFFF;
        }
    }
}
