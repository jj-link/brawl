#pragma force_active on
extern "C" void fn_8015D500(unsigned char* p, unsigned long unused, unsigned long size);

extern "C" void fn_801BEFC8(unsigned char* p, unsigned long unused, unsigned long size)
{
    unsigned long a = *(unsigned long*)(p + 0x18);
    unsigned long b = *(unsigned long*)(p + 0x70);
    unsigned long c = *(unsigned long*)(p + 0x74);
    unsigned long end = b + c;
    if (a + size > end) {
        size = ((end - a) + 0x1f) & ~0x1fUL;
    }
    fn_8015D500(p, unused, size);
}
