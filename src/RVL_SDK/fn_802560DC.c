#pragma force_active on
extern unsigned char lbl_8040D9E8[256];

unsigned char fn_802560DC(unsigned short count, unsigned char *data) {
    unsigned char val = 0xFF;
    while (count-- != 0) {
        val = lbl_8040D9E8[val ^ *data++];
    }
    return 0xFF - val;
}
