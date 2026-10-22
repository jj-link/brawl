#pragma force_active on
extern "C" void fn_800309F8(int a1, int a2, int a3);
extern "C" int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

extern "C" void fn_800DAECC(void* p) {
    char* self = (char*)p;
    fn_800309F8(*(int*)(self + 0x60), 0x2B, 2);
    if (*(int*)(self + 0x5C) == 0) {
        *(int*)(self + 0x5C) = fn_800BEEB8(3, *(int*)(self + 0x4C), 0x45, *(int*)(self + 0x40), *(int*)(self + 0x44), *(int*)(self + 0x58), 0, 0x2A, 0x2B, 0, 0, 0xF0);
    }
    *(int*)(self + 0x64) = 30;
}
