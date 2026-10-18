#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_95_B834(void* self, u32 index)
{
    u32* arr = *(u32**)((char*)self + 0x1c);
    arr[index] = 0;
}
