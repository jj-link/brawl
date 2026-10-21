#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" int fn_81_387C(u8* ths, u32 arg)
{
    u8* p = *(u8**)(ths + 0x9c);
    if (p == 0)
        return 0;

    u32 n = *(u32*)(p + 0x18);
    for (u32 i = 0; i != n; i++) {
        u32 idx = ths[0xa9a] + i;
        if (idx >= 30)
            idx -= 30;

        if (idx != arg) {
            u32 k = ths[0xa7c + idx];
            switch (ths[0x374 + k * 60]) {
            case 6:
            case 7:
            case 8:
            case 9:
                return 0;
            }
        }
    }
    return 1;
}
