#pragma force_active on
typedef unsigned char u8;

extern "C" bool fn_41_1AE7C(void* p);

extern "C" bool fn_41_1C9C4(void* p) {
    u8* b = (u8*)p;
    if (fn_41_1AE7C(p) == 1) {
        return true;
    }
    return !((b[5] >> 7) & 1);
}
