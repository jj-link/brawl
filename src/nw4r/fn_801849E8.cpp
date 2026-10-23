#pragma force_active on

extern "C" void fn_801849E8(char *arg0, unsigned int arg1, signed char arg2) {
    char *p = arg0 + (arg1 & ~3u);
    p = p + (arg1 & 3u);
    *(p + 0xD4) = arg2;
}
