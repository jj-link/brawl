#pragma force_active on
extern void fn_80397748(void *, int, int);
extern int fn_8039D440(int, int, void *, int, int *);
extern int fn_80398BD8(void *, int, int);
extern int lbl_805A1170;
extern int lbl_805A1190;

void fn_8039FB14(int src, int len, int *out) {
    char *buf = (char *)lbl_805A1170;
    char *p = (char *)src;
    int total = 0;
    int written;
    int r = 0;

    while (len >= 0x39) {
        fn_80397748(buf, 0, 0x400);
        r = fn_8039D440((int)p, 0x39, buf, 0x4C, &written);
        if (r != 0) {
            break;
        }
        buf[written++] = 0xD;
        buf[written++] = 0xA;
        buf[written] = 0;
        r = fn_80398BD8(buf, written, lbl_805A1190);
        if (r != 0) {
            break;
        }
        p += 0x39;
        len -= 0x39;
        total += written;
    }

    if (r == 0) {
        fn_80397748(buf, 0, 0x400);
        if (fn_8039D440((int)p, len, buf, 0x4C, &written) == 0) {
            buf[written++] = 0xD;
            buf[written++] = 0xA;
            buf[written++] = 0xD;
            buf[written++] = 0xA;
            buf[written] = 0;
            if (fn_80398BD8(buf, written, lbl_805A1190) == 0) {
                total += written;
            }
        }
    }

    *out = total;
}
