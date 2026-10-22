#pragma force_active on
extern "C" void fn_800F00D4(void* a, int b, int c, int d);
extern "C" void fn_801B354C(void* a, int b);

extern "C" void fn_800DC9B0(void* self, int a, int b, int index)
{
    if (index >= 0)
        index = *(unsigned char*)((char*)self + index + 0x68);
    else
        index = -1;
    fn_800F00D4(*(void**)((char*)self + 0x70), a, b, index);
    fn_801B354C(*(void**)((char*)self + 0x18), 1);
    *((unsigned char*)self + 0xA9) = 1;
}
