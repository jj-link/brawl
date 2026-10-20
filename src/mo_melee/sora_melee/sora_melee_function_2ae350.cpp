#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_27_2AC698(void* self, s32 a, s32 b);

extern "C" void fn_27_2AE350(void* self, s32 a, s32* value) {
    s32 idx = fn_27_2AC698(self, a - 1, -1);
    if (idx >= 0) {
        *(s32*)((u8*)self + idx * 12 + 0xc) = *value;
    }
}
