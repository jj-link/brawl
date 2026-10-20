#pragma force_active on
typedef int s32;

extern "C" void* fn_27_D9700(char* self, s32 idx) {
    s32 i = (((s32*)self)[2] >> 27) + idx;
    if (i >= 10) {
        i -= 10;
    }
    return self + (i << 4) + 12;
}
