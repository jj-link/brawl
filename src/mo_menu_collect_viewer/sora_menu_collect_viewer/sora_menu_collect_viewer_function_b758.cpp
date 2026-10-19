#pragma force_active on
extern "C" int fn_800BEEB8(int, int, int, int, int, int, int, int, int, int, int, int);

extern "C" void fn_6_B758(void* p) {
    int value = *(int*)((char*)p + 0x78);
    int result = fn_800BEEB8(
        0,
        *(int*)((char*)value + 4),
        0x10,
        *(int*)((char*)p + 0x144),
        *(int*)((char*)p + 0x74),
        *(int*)((char*)p + 0x148) + 7,
        0,
        0x2A,
        0x2B,
        0,
        0,
        0xF0
    );
    *(int*)((char*)p + 0x140) = result;
}
