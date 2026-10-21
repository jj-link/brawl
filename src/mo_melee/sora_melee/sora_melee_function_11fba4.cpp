#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void fn_27_11FBA4(u8* base, s32 value) {
    u8 idx = 0;
    s32 n;
    u8* e;
    for (n = 0; n < 2; n++) {
        e = base + (u8)idx * 0x30;
        if (*(s32*)(e + 0x338) != -1 && value == *(s32*)(e + 0x330)) {
            *(u8*)(e + 0x33c) = 0;
        }
        idx++;
        e = base + (u8)idx * 0x30;
        if (*(s32*)(e + 0x338) != -1 && value == *(s32*)(e + 0x330)) {
            *(u8*)(e + 0x33c) = 0;
        }
        idx++;
        e = base + (u8)idx * 0x30;
        if (*(s32*)(e + 0x338) != -1 && value == *(s32*)(e + 0x330)) {
            *(u8*)(e + 0x33c) = 0;
        }
        idx++;
        e = base + (u8)idx * 0x30;
        if (*(s32*)(e + 0x338) != -1 && value == *(s32*)(e + 0x330)) {
            *(u8*)(e + 0x33c) = 0;
        }
        idx++;
    }
}
