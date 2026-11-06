#pragma force_active on
extern "C" int fn_800557F8(int arg0, int arg1, int arg2);

extern "C" int fn_80058320(int arg0) {
    int ret = 0;
    switch (arg0) {
    case 0x72:
        ret = fn_800557F8(1, 1, 0);
        break;
    case 0x2F:
        ret = fn_800557F8(1, 3, 0);
        break;
    case 0xE:
        ret = fn_800557F8(1, 0xD, 0);
        break;
    case 0x6D:
        ret = fn_800557F8(1, 6, 0);
        break;
    case 0x55:
        ret = fn_800557F8(1, 0x10, 0);
        break;
    case 0x50:
        ret = fn_800557F8(1, 0x14, 0);
        break;
    case 0x47:
        ret = fn_800557F8(1, 0x18, 2);
        break;
    case 0x28:
        ret = fn_800557F8(1, 0x1A, 0);
        break;
    case 0x56:
        ret = fn_800557F8(1, 0x1F, 0);
        break;
    case 0x76:
        ret = fn_800557F8(1, 0x20, 0);
        break;
    case 0x4C:
        ret = fn_800557F8(1, 0x24, 0);
        break;
    case 0x2B:
        ret = fn_800557F8(1, 0x2B, 2);
        break;
    case 0x45:
        ret = fn_800557F8(1, 0x27, 0);
        break;
    case 0x5E:
        ret = fn_800557F8(1, 0x2F, 2);
        break;
    }
    return ret;
}
