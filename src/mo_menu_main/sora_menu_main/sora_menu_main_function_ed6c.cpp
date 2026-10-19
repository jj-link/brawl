#pragma force_active on
extern "C" int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

extern "C" int fn_2_ED6C(void* p) {
    char* self = (char*)p;
    int r = fn_800BEEB8(1, *(int*)(*(int*)(self + 0xd4) + 4), 6, (int)(self + 0xb0), *(int*)(self + 0x29c), 0x17, 0, 0x2a, 0x2b, 0, 1, 0xf0);
    *(int*)(self + 0x298) = r;
    return r;
}
