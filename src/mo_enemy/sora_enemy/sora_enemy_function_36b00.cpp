#pragma force_active on
typedef int s32;

extern "C" {
void* fn_41_36B00(char* p, s32 n) {
    if (n == 1) {
        return p + 0x2388;
    }
    if (n == 0) {
        return p + 0x10;
    }
    return 0;
}
}
