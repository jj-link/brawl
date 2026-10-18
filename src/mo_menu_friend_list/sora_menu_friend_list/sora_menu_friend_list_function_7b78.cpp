#pragma force_active on
extern "C" int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
extern "C" int lbl_14_rodata_4B8[3];

extern "C" void fn_14_7B78(void* self) {
    char* p = (char*)self;
    int* tbl = lbl_14_rodata_4B8;
    int val = *(int*)(*(char**)(p + 0x24CC) + 4);
    int r = fn_800BEEB8(0, val, tbl[*(int*)(p + 0x2AC4)], *(int*)(p + 0x24F0), *(int*)(p + 0x2A1C), 0x1F, 0, 0x2A, 0x2B, 0, 0, 0xF0);
    *(int*)(p + 0x24EC) = r;
}
