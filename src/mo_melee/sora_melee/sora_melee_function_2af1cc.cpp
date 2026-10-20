#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_27_2ADA28(void* self, s32 index, s32 value);

extern "C" void fn_27_2AF1CC(void* self, s32 index, s32* value) {
    s32 result = fn_27_2ADA28(self, index - 1, -1);
    if (result >= 0) {
        *(s32*)((u8*)self + result * 12 + 0x10) = *value;
    }
}
