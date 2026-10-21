#pragma force_active on
extern "C" void fn_80300C30(void *unused, unsigned char *p, unsigned int key) {
    int n = p[0xe];
    unsigned char *q = p + 0x10;
    while (n > 0) {
        if ((unsigned short)*(unsigned short *)(q + 2) == key) {
            q[0] = 0;
            q[1] = 0;
            return;
        }
        q += 8;
        n--;
    }
}
