#pragma force_active on
typedef unsigned char u8;

extern "C" int fn_70_4CD4(u8* p) {
    switch (p[0x1a9]) {
    case 0x14:
    case 0xb:
        return 0;
    case 0x13:
        return 0;
    case 0x24:
        return 0;
    default:
        break;
    }

    switch (p[0x1bc]) {
    case 1:
    case 8:
    case 9:
    case 10:
        return 0;
    default:
        return 1;
    }
}
