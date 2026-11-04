#pragma force_active on
extern char lbl_80474FB8[];
extern char *lbl_805A07F4;

char *fn_801E80BC(unsigned int arg0)
{
    switch (arg0) {
    case 0: return lbl_80474FB8;
    case 1: return lbl_80474FB8 + 0x26;
    case 4: return lbl_80474FB8 + 0x4C;
    case 5: return lbl_80474FB8 + 0x72;
    case 20: return lbl_80474FB8;
    case 21: return lbl_80474FB8 + 0x26;
    case 8: return lbl_80474FB8 + 0x98;
    case 9: return lbl_80474FB8 + 0xBE;
    case 2:
    case 10:
    case 22: return lbl_80474FB8 + 0xE4;
    case 3: return lbl_80474FB8 + 0x10A;
    case 16: return lbl_80474FB8 + 0x4C;
    case 17: return lbl_80474FB8 + 0x72;
    case 24: return lbl_80474FB8 + 0x130;
    case 26: return lbl_80474FB8 + 0x156;
    case 6: return lbl_80474FB8 + 0x17C;
    case 28:
    case 29:
    case 30: return lbl_805A07F4;
    default: return 0;
    }
}
