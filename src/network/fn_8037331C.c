#pragma force_active on
extern int fn_8035DA18(int arg0);
extern int fn_8035DA30(int arg0, int arg1);
extern void fn_8035DAA4(signed char *buf, void *dst, unsigned int len, int flag);
extern unsigned int strlen(const char *s);

void fn_8037331C(unsigned char *src, void *dst) {
    signed char buf[0x20];
    signed char *p;
    signed char k;
    unsigned int i;
    unsigned int len;

    len = strlen((const char *)src);
    fn_8035DA18(0x79707367);
    p = buf;
    i = 0;
    while (i < len) {
        k = fn_8035DA30(0, 0xFF);
        *p = k ^ *src;
        i++;
        src++;
        p++;
    }
    buf[i] = 0;
    fn_8035DAA4(buf, dst, len, 1);
}
