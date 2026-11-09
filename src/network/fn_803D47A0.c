#pragma force_active on
int fn_803D47A0(int arg0) {
    switch (arg0) {
    case 0x60:
    case 0x40:
        return 0x40;
    case 0xE0:
    case 0x80:
        return 0x80;
    case 0x1E0:
    case 0x100:
        return 0x100;
    default:
        return 0x40;
    }
}