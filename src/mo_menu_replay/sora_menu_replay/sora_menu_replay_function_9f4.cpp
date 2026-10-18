#pragma force_active on
extern "C" {
void* fn_800C3538(void* a, void* b);
}

extern "C" void* fn_7_9F4(void* a, char* b)
{
    char* p = *(char**)(b + 0x1ac);
    unsigned int r0 = *(unsigned int*)(p + 0x1a0);
    p = p + (r0 << 4);
    p = *(char**)(p + 0x1ac);
    return fn_800C3538(a, p);
}
