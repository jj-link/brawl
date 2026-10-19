#pragma force_active on
typedef int s32;

extern "C" void* fn_41_43C04(void* p, s32 n) {
    if (n == 2) {
        return (char*)p + 0x6c;
    }
    if (n == 1) {
        return (char*)p + 0x40;
    }
    if (n == 0) {
        return (char*)p + 0x14;
    }
    return 0;
}
