#pragma force_active on
extern "C" int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

extern "C" void fn_6_9E34(void* p) {
    unsigned char* self = (unsigned char*)p;
    int r = fn_800BEEB8(0, *(int*)(*(int*)(self + 0x74) + 4), 8, *(int*)(self + 0x754), *(int*)(self + 0x70), *(int*)(self + 0x758) + 3, 0, 0x2a, 0x2b, 0, 0, 0xf0);
    *(int*)(self + 0x750) = r;
}
