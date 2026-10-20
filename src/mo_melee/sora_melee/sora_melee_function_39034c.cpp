#pragma force_active on
typedef int s32;

extern "C" {
void* fn_27_39034C(char* self, s32 idx) {
    s32 n = (*(s32*)(self + 8) >> 29) + idx;
    if (n >= 2) {
        n -= 2;
    }
    return self + n * 60 + 12;
}
}
