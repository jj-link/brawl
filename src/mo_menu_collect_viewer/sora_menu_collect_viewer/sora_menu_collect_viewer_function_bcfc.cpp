#pragma force_active on
extern "C" int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

extern "C" void fn_6_BCFC(char* p) {
    int r = fn_800BEEB8(1, *(int*)(*(int*)(p + 0x78) + 4), 0xf, *(int*)(p + 0x144), *(int*)(p + 0x74), *(int*)(p + 0x148) + 7, 0, 0x2a, 0x2b, 0, 0, 0xf0);
    *(int*)(p + 0x140) = r;
}
