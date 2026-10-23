#pragma force_active on

extern unsigned char lbl_8040D9E8[256];

unsigned char fn_80256114(unsigned short count, unsigned char *data, unsigned char extra) {
    unsigned char val = 0xFF;
    while (count-- != 0) {
        val = lbl_8040D9E8[val ^ *data++];
    }
    return lbl_8040D9E8[val ^ extra] == 0xCF;
}
