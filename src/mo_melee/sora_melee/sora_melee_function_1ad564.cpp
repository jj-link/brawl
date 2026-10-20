#pragma force_active on
typedef int s32;

extern "C" {
void* fn_27_1AD564(char* self, s32 idx) {
    s32 i = (*(s32*)(self + 0x18) >> 27) + idx;
    if (i >= 12) {
        i -= 12;
    }
    return self + i * 12 + 0x1c;
}
}
