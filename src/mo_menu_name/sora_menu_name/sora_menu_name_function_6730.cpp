#pragma force_active on
extern "C" int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

extern "C" void fn_16_6730(char* p) {
    int r = fn_800BEEB8(0, *(int*)(p + 0x458), 0xc, *(int*)(p + 0x460), *(int*)(p + 0xa8), *(int*)(p + 0x3e4) + 0xc, 0, 0x2a, 0x2b, 0, 0, 0xf0);
    *(int*)(p + 0x45c) = r;
}
