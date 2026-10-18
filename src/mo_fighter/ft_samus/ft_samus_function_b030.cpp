#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_94_B030(void* self, u32 index) {
    u32* arr = *(u32**)((char*)self + 0xc);
    arr[index]++;
}
