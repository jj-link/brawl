#pragma force_active on
typedef int s32;

extern "C" void* fn_27_D98E0(char* self, s32 idx) {
    s32 adj = *(s32*)(self + 8) >> 30;
    s32 sum = adj + idx;
    if (sum >= 1) {
        sum = sum - 1;
    }
    return self + sum * 0x2c + 0xc;
}
