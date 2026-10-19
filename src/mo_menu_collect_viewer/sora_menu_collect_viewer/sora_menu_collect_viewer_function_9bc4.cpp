#pragma force_active on
extern "C" int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

extern "C" int fn_6_9BC4(char* p) {
    *(int*)(p + 0x750) = fn_800BEEB8(
        0,
        *(int*)(*(int*)(p + 0x74) + 4),
        0xb,
        *(int*)(p + 0x754),
        *(int*)(p + 0x70),
        *(int*)(p + 0x758) + 3,
        0, 0x2a, 0x2b, 0, 0, 0xf0);
    return *(int*)(p + 0x750);
}
