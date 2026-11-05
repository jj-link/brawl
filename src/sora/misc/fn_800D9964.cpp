#pragma force_active on
struct Pair {
    int a;
    int b;
};

extern "C" unsigned char fn_800C8548();
extern "C" void netReport__FPCce(const char*, ...);
extern "C" Pair fn_80052250();
extern char lbl_80459A10[0xD0];

extern "C" Pair fn_800D9964(unsigned char* arg0) {
    unsigned char idx = fn_800C8548();
    unsigned char* p;
    if (idx == 0xFF) {
        p = 0;
    } else {
        int addr = (int)arg0 + idx * 0x218;
        p = (unsigned char*)(addr + 0x70);
    }
    if (p == 0) {
        netReport__FPCce(lbl_80459A10);
        return fn_80052250();
    }
    return *(Pair*)(p + 0x30);
}
