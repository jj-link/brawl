#pragma force_active on
extern "C" {
int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

void fn_14_7218(char* self) {
    *(int*)(self + 0x24ec) = fn_800BEEB8(0, *(int*)(*(int*)(self + 0x24cc) + 4), 0x1d, *(int*)(self + 0x24f0), *(int*)(self + 0x2a1c), 0x1f, 0, 0x2a, 0x2b, 0, 0, 0xf0);
}
}
