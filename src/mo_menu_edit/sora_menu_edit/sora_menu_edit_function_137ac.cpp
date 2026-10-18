#pragma force_active on
extern "C" {
void* fn_800C3538(void*, void*);

void* fn_5_137AC(void* unused, char* p)
{
    char* a = *(char**)(p + 0x1ac);
    unsigned int idx = *(unsigned int*)(a + 0x1a0);
    char* b = a + (idx << 4);
    return fn_800C3538(unused, *(void**)(b + 0x1ac));
}
}
