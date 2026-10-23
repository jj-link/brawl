#pragma force_active on
extern "C" int fn_24_33CC(unsigned char* s, unsigned mask) {
    for (int i = 0; i < 4; ++i, s += 0x40) {
        if (*(unsigned*)(s + 0xC) & mask)
            return 1;
        if (*(unsigned*)(s + 0x10C) & mask)
            return 1;
    }
    return 0;
}
