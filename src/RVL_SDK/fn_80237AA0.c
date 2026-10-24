#pragma force_active on
extern char lbl_80480358[];

char *fn_80237AA0(int arg0) {
    char *base = lbl_80480358;

    switch (arg0) {
    case 0x170d: return base + 0x108;
    case 0x170c: return base + 0x120;
    case 0x1700: return base + 0x138;
    case 0x1701: return base + 0x14c;
    case 0x1702: return base + 0x164;
    case 0x1703: return base + 0x178;
    case 0x1706: return base + 0x190;
    case 0x1704: return base + 0x1a8;
    case 0x1705: return base + 0x1bc;
    case 0x1708: return base + 0x1d4;
    case 0x1707: return base + 0x1f0;
    case 0x170f: return base + 0x204;
    case 0x170a: return base + 0x21c;
    case 0x1709: return base + 0x238;
    case 0x170b: return base + 0x250;
    case 0x170e: return base + 0x268;
    default: return base + 0x284;
    }
}
