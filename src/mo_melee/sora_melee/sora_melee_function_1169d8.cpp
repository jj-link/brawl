#pragma force_active on
extern "C" void fn_27_130FC8(void *obj);

extern "C" void fn_27_1169D8(void *p)
{
    unsigned char *b = (unsigned char *)p;
    if (b[0xf] != 6) {
        return;
    }
    unsigned char idx = b[0xa];
    char *q = (char *)p + (idx << 3);
    fn_27_130FC8(*(void **)(q + 0x34));
}
