#pragma force_active on
extern void fn_803A9644(void* a, void* b, int c);

void fn_803C16BC(void* a, unsigned char* b)
{
    fn_803A9644(b + 0x160c, a, 11);
    b[0x1617] = 0;
}
