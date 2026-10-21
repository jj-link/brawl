#pragma force_active on
extern "C" {
void fn_8018508C(unsigned char *arg0, unsigned int arg1, unsigned char arg2) {
    unsigned char *p = arg0 + ((arg1 >> 1) & 0x7FFFFFFC);
    p = p + (arg1 & 3);
    *(unsigned char *)(p + 0xD8) = arg2;
}
}
