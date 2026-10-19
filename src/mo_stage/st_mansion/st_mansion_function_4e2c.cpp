#pragma force_active on
extern "C" void* fn_47_4E2C(int* base, int index)
{
    int s = base[2] >> 30;
    int i = s + index;
    if (i >= 1) {
        i -= 1;
    }
    return (char*)base + 0xc + i * 0x78;
}
