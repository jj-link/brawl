#pragma force_active on
extern "C" void fn_801BAE18(void *, unsigned short *);

extern "C" void fn_801BA188(void *p, const unsigned short *src) {
    unsigned short buf[16];

    buf[0] = src[0];
    buf[1] = 0;
    buf[2] = src[1];
    buf[3] = 0;
    buf[4] = src[2];
    buf[5] = 0;
    buf[6] = src[3];
    buf[7] = 0;
    buf[8] = src[4];
    buf[9] = 0;
    buf[10] = src[5];
    buf[11] = 0;
    buf[12] = src[6];
    buf[13] = 0;
    buf[14] = src[7];
    buf[15] = 0;

    fn_801BAE18(p, buf);
}
