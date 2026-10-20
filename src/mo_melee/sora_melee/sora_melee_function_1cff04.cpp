#pragma force_active on
extern "C" void fn_27_1CFF04(void *p)
{
    unsigned int *word = (unsigned int *)((char *)p + 8);
    *word &= 0xFFF7FFFF;
}
