#pragma force_active on
extern "C" unsigned char fn_27_5AA9C(const unsigned char *p, unsigned int index)
{
    const unsigned char *base = p;
    base += ((index & 0xFF) << 1);
    return base[0x59];
}
