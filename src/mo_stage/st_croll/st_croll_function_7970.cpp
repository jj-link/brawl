#pragma force_active on
extern "C" char lbl_90_data_0[];

extern "C" int fn_90_7970(int r3, void** r4) {
    char* base = lbl_90_data_0;
    switch (r3) {
    case 0xD:
    case 0xE:
        *r4 = base + 0x2658;
        return 2;
    case 0x3:
    case 0x17:
        *r4 = base + 0x2660;
        return 2;
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x1E:
        *r4 = base + 0x2668;
        return 4;
    default:
        return 1;
    }
}
