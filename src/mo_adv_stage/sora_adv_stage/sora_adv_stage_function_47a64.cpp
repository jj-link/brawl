#pragma force_active on
extern "C" {
void fn_800C2B94(void* a, int b);

void fn_40_47A64(void* self)
{
    fn_800C2B94(*(void**)((char*)self + 0x1b4), 0);
}
}
