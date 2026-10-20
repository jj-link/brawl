#pragma force_active on
typedef unsigned char u8;

extern "C" void* fn_27_1B04BC(void* p, int idx)
{
    u8* base = (u8*)p;
    int n = *(int*)(base + 0x8);
    int i = (n >> 27) + idx;
    if (i >= 8) {
        i -= 8;
    }
    return base + 0xc + i * 0x68;
}
