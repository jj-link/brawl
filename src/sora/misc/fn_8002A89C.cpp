#pragma force_active on
extern "C" void fn_802162A4(int, int);
extern "C" void fn_8021A558(int, int);

struct gfPadSystem {
    char pad0[0x35];
    unsigned char f0 : 1;
    unsigned char flag : 1;
    unsigned char f3 : 6;
    char pad36[0xB4A - 0x36];
    unsigned short mask;
    char padB4C[0xC];
    unsigned short motor[8];
    void maskMotor(unsigned short m);
};

void gfPadSystem::maskMotor(unsigned short m) {
    int v = mask & (unsigned char)m;
    if (v != 0) {
        for (int i = 0; i < 8; i++) {
            if ((v & (1 << i)) && flag) {
                if (i < 4) fn_802162A4(i, 0);
                else fn_8021A558(i - 4, 0);
                motor[i] = 0;
            }
        }
    }
    mask = (unsigned char)m;
}
