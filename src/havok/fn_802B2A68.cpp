#pragma force_active on
extern "C" void fn_802B2A68(void *arg0, unsigned int arg1) {
    unsigned char *p = (unsigned char *)arg0;
    int count = p[0x32];
    unsigned char *p2 = p + 0x34;
    for (int i = 0; i < count; i++) {
        unsigned short val = *(unsigned short *)(p2 + 2);
        if (val == arg1) {
            p2[0] = 0;
            p2[1] = 0;
            return;
        }
        p2 += 8;
    }
}
