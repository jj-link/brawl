#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_105_185E8(void* self, void* unused, int index, int element)
{
    int firstIndex = *(int*)((char*)self + 0x14);
    int** rows = (int**)((char*)self + 0x2C + (index - firstIndex) * 4);
    return (u32)rows[0][element];
}
