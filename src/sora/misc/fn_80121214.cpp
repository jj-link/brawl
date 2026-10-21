#pragma force_active on
extern "C" unsigned short fn_80121214(void *arg0) {
    unsigned short result = 0;
    unsigned char val = *(unsigned char *)((unsigned char *)arg0 + 0x10);
    if (val & 1) result |= 2;
    if (val & 8) result |= 1;
    if (val & 2) result |= 4;
    if (val & 4) result |= 8;
    return result;
}
