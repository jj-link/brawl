#pragma force_active on
extern "C" {
void fn_80030F98(void* a, int b);

void fn_800DACB0(void* p)
{
    fn_80030F98(*(void**)((char*)p + 0x60), 0x2b);
}
}
