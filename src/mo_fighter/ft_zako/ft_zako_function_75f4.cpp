#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" void fn_126_75F4(void* self, u32 index) {
    s32* arr = *(s32**)((char*)self + 0xc);
    arr[index] = arr[index] - 1;
}
