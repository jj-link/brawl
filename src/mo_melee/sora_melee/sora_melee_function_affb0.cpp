#pragma force_active on
extern "C" void *fn_27_AFFB0(void *p, int index)
{
    int offset = *(int *)((char *)p + 0x18) >> 27;
    int slot = offset + index;
    if (slot < 8) {
    } else {
        slot -= 8;
    }
    return (char *)p + slot * 12 + 0x1C;
}
