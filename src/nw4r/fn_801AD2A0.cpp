#pragma force_active on
typedef unsigned char u8;
typedef float f32;

extern "C" bool fn_801AD2A0(const void* a, const void* b) {
    const char* pa = reinterpret_cast<const char*>(a);
    const char* pb = reinterpret_cast<const char*>(b);

    int x0 = *reinterpret_cast<const u8*>(pa + 0xD1);
    int x1 = *reinterpret_cast<const u8*>(pb + 0xD1);

    if (x0 == x1) {
        return *reinterpret_cast<const f32*>(pa + 0x98) <
               *reinterpret_cast<const f32*>(pb + 0x98);
    }

    return x0 < x1;
}
