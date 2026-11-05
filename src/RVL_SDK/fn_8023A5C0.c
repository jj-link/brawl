#pragma force_active on

extern unsigned char lbl_80529CF8[];
extern const char lbl_80480D18[];
extern void fn_80231A44(unsigned int, const char *, unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned char fn_80246A34(unsigned char, unsigned char);

int fn_8023A5C0(unsigned char arg0, unsigned char arg1)
{
    if (lbl_80529CF8[0x27C0] >= 3U) {
        fn_80231A44(0xD0002, lbl_80480D18, arg0,
                     lbl_80529CF8[0x27BD], arg1, lbl_80529CF8[0x27BE]);
    }
    if (!(lbl_80529CF8[0x645] & 8) &&
        !(lbl_80529CF8[0x644] & 0x10) &&
        !(lbl_80529CF8[0x645] & 0x10)) {
        return 4;
    }
    if (lbl_80529CF8[0x27BD] != arg0 || lbl_80529CF8[0x27BE] != arg1) {
        if (fn_80246A34(arg0, arg1)) {
            lbl_80529CF8[0x27BD] = arg0;
            lbl_80529CF8[0x27BE] = arg1;
        } else {
            return 3;
        }
    }
    return 0;
}
