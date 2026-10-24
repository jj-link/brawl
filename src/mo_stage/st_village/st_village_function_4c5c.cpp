#pragma force_active on
typedef unsigned char u8;

extern "C" int fn_70_4C5C(u8* p) {
    switch (p[0x1a9]) {
    case 11:
    case 20:
        return 0;
    case 19:
        return 0;
    case 36:
        return 0;
    case 10:
        return 0;
    case 22:
    case 23:
        return 0;
    default:
        break;
    }
    switch (p[0x1bc]) {
    case 10:
    case 9:
    case 8:
        return 0;
    default:
        return 1;
    }
}
