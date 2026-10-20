#pragma force_active on
extern "C" {
int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

void fn_16_639C(int self) {
    *(int*)(self + 0x45c) = fn_800BEEB8(
        1,
        *(int*)(self + 0x458),
        (*(int*)(self + 0x44c) == 0) ? 1 : 2,
        *(int*)(self + 0x460),
        *(int*)(self + 0xa8),
        *(int*)(self + 0x3e4) + 0xc,
        0,
        0x2a,
        0x2b,
        0,
        0,
        0xf0);
}
}
