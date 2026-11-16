#pragma force_active on

extern "C" int fn_802D99B4(unsigned short* arg0, int* arg1) {
    int ret = 0;
    switch (*arg0) {
    case 0x19:
        ret |= 2;
        break;
    case 0x17:
        ret |= 2;
        break;
    case 0x18:
        arg1[2] += 0x20;
        arg1[1] += 0x40;
        break;
    case 0x1a:
        arg1[2] += 0x20;
        arg1[1] += 0x20;
        break;
    }
    return ret;
}