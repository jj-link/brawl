#pragma force_active on
extern "C" {
int fn_801AAC9C(unsigned char* obj, int type, int enable)
{
    switch (type) {
    case 1:
        if (enable) *(unsigned int*)(obj + 0xcc) |= 0x10;
        else *(unsigned int*)(obj + 0xcc) &= ~0x10u;
        break;
    case 2:
        if (enable) *(unsigned int*)(obj + 0xcc) |= 1;
        else *(unsigned int*)(obj + 0xcc) &= ~1u;
        break;
    case 3:
        if (enable) *(unsigned int*)(obj + 0xcc) |= 2;
        else *(unsigned int*)(obj + 0xcc) &= ~2u;
        break;
    case 4:
        if (enable) *(unsigned int*)(obj + 0xcc) |= 4;
        else *(unsigned int*)(obj + 0xcc) &= ~4u;
        break;
    case 5:
        if (enable) *(unsigned int*)(obj + 0xcc) |= 8;
        else *(unsigned int*)(obj + 0xcc) &= ~8u;
        break;
    case 6:
        if (enable) *(unsigned int*)(obj + 0xcc) |= 0x20;
        else *(unsigned int*)(obj + 0xcc) &= ~0x20u;
        break;
    case 7:
        if (enable) *(unsigned int*)(obj + 0xcc) |= 0x40;
        else *(unsigned int*)(obj + 0xcc) &= ~0x40u;
        break;
    case 8:
        if (enable) *(unsigned int*)(obj + 0xcc) |= 0x80;
        else *(unsigned int*)(obj + 0xcc) &= ~0x80u;
        break;
    case 9:
        if (enable) *(unsigned int*)(obj + 0xcc) |= 0x10000000;
        else *(unsigned int*)(obj + 0xcc) &= ~0x10000000u;
        break;
    default:
        return 0;
    }
    return 1;
}
}