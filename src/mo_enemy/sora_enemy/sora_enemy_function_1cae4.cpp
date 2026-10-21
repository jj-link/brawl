#pragma force_active on
typedef unsigned char u8;

extern "C" bool fn_41_1AE7C(void* p);

extern "C" bool fn_41_1CAE4(void* p) {
    if (fn_41_1AE7C(p) == 1) {
        return false;
    }

    float f1 = *(float*)((u8*)p + 0x1c);
    if ((int)f1 == 0x8bcf) {
        return false;
    }
    if ((int)f1 == 0x8bd3) {
        return false;
    }

    bool gt = *(float*)((u8*)p + 0x4c) > f1;
    return gt == 0;
}
