#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" void fn_120_9B64(void* self, s32 val, u32 idx) {
    s32* arr = *(s32**)((char*)self + 0xc);
    arr[idx] -= val;
}
