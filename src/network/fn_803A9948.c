#pragma force_active on
unsigned short fn_803A9948(unsigned char *arg) {
    return (arg[0] & ~0xFF00) | ((arg[1] << 8) & 0xFF00);
}
