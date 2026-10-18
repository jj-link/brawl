#pragma force_active on
extern "C" {

unsigned int fn_96_1E1E8(void *obj)
{
    unsigned int v = *(unsigned int *)((unsigned char *)obj + 0x8);
    return (v >> 13) & 1;
}

}
