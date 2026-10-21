#pragma force_active on
extern "C" int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

extern "C" void fn_14_72DC(void* p, int a2, int value) {
    char* self = (char*)p;

    switch (*(int*)(self + 0x2a28)) {
    case 0:
        break;
    case 1:
        value = 0x21;
        break;
    case 2:
        value = 0x22;
        break;
    case 3:
        value = 0x23;
        break;
    case 4:
        value = 0x24;
        break;
    }

    *(int*)(self + 0x24ec) = fn_800BEEB8(
        1, *(int*)(*(int*)(self + 0x24cc) + 4), value,
        *(int*)(self + 0x24f0), *(int*)(self + 0x2a1c),
        0x1f, 0, 0x2a, 0x2b, 0, 0, 0xf0);
}
