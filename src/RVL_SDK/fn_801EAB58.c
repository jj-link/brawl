#pragma force_active on
void fn_801EA098(int);
void fn_801EA4E4(int, unsigned char *, int);

void fn_801EAB58(unsigned char arg0) {
    unsigned char buf[2];

    buf[1] = arg0;
    buf[0] = 0x6E;
    fn_801EA4E4(0xE0, buf, 2);
    fn_801EA098(2);
}
