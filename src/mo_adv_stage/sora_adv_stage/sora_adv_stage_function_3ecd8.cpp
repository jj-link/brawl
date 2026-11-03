#pragma force_active on
extern unsigned char lbl_40_rodata_930[];
extern "C" unsigned char fn_40_3ECD8(void* obj, int value, int direction)
{
    int index;
    for (index = 0; index < 4; ++index) {
        if (value == lbl_40_rodata_930[index * 2]) break;
    }
    int offset;
    if (direction) {
        do {
            ++index;
            if (index >= 4) index = 0;
            offset = index * 2;
        } while (value != lbl_40_rodata_930[index * 2] &&
                 !(((unsigned char*)obj)[0xc2c] & lbl_40_rodata_930[offset + 1]));
    } else {
        do {
            --index;
            if (index < 0) index = 3;
            offset = index * 2;
        } while (value != lbl_40_rodata_930[index * 2] &&
                 !(((unsigned char*)obj)[0xc2c] & lbl_40_rodata_930[offset + 1]));
    }
    return *(unsigned char*)((unsigned long)lbl_40_rodata_930 + (index << 1));
}