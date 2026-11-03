#pragma force_active on
extern "C" int fn_8006CA64();
extern "C" int fn_8006C90C();
extern "C" int fn_8006C9EC();
extern "C" int fn_8006C790();
extern "C" void fn_800B881C(unsigned char* p, int index) {
    int flags = 0;
    if ((unsigned int)((p[16] >> 7) & 1) != 1) {
        unsigned char old = p[index];
        p[index] = 0;
        for (int i = 0; i < 16; i++) flags |= p[i];
        if ((old & 2) && !(flags & 2U)) fn_8006CA64();
        if ((old & 1) && !(flags & 1)) fn_8006C90C();
        if ((old & 4) && !(flags & 4)) fn_8006C9EC();
        if ((old & 8) && !(flags & 8)) fn_8006C790();
    }
}