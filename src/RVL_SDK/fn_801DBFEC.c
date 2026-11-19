#pragma force_active on
extern unsigned short lbl_80467E40[];
extern unsigned short lbl_80467FC0[];

static inline int valid(unsigned int lo) {
    return lo >= 0x40 && lo <= 0xFC && lo != 0x7F;
}

int fn_801DBFEC(unsigned int type, unsigned int c) {
    if (type == 1) {
        if (c >= 0x20 && c <= 0xDF)
            return lbl_80467E40[c - 0x20];
        if (c > 0x889E && c <= 0x9872) {
            int base = (((c >> 8) & 0xFF) - 0x88) * 0xBC;
            unsigned int lo = c & 0xFF;
            if (!valid(lo))
                return 0;
            lo -= 0x40;
            if ((int)lo >= 0x40)
                lo -= 1;
            return base + lo + 0x2BE;
        }
        if (c >= 0x8140 && c < 0x879E) {
            int base = (((c >> 8) & 0xFF) - 0x81) * 0xBC;
            unsigned int lo = c & 0xFF;
            if (!valid(lo))
                return 0;
            lo -= 0x40;
            if ((int)lo >= 0x40)
                lo -= 1;
            return lbl_80467FC0[base + lo];
        }
    } else if (c > 0x20 && c <= 0xFF) {
        return c - 0x20;
    }
    return 0;
}