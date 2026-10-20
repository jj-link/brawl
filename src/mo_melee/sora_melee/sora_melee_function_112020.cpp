#pragma force_active on
typedef unsigned char u8;

extern "C" {
u8 fn_27_112020(void *self, int off)
{
    char *base = *(char **)self;
    return *(u8 *)(base + off + 0x70);
}
}
