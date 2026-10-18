#pragma force_active on
extern "C" void fn_800C3538(void* a, void* b);

extern "C" void fn_8_9E8(void* a, char* b)
{
    char* p = *(char**)(b + 0x1ac);
    unsigned int off = *(unsigned int*)(p + 0x1a0);
    p = *(char**)(p + (off << 4) + 0x1ac);
    fn_800C3538(a, p);
}
