#pragma force_active on
extern "C" void fn_802162A4(int, int);
extern "C" void fn_8021A558(int, int);

class gfPadSystem {
public:
    void stopMotor(int arg);
};

void gfPadSystem::stopMotor(int arg) {
    unsigned char* p = (unsigned char*)this;
    if ((p[0x35] >> 6) & 1) {
        if (arg < 4) {
            fn_802162A4(arg, 0);
        } else {
            fn_8021A558(arg - 4, 0);
        }
        *(unsigned short*)(p + arg * 2 + 0xB58) = 0;
    }
}
