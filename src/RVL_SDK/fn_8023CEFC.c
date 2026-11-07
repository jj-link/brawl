#pragma force_active on
extern void *fn_8022EFF8(unsigned int);
extern void fn_80245D9C(void *, int, int, void *, int);
extern void *memcpy(void *, const void *, unsigned long);
extern char lbl_80529CF8[];

int fn_8023CEFC(int arg0, unsigned char *arg1) {
    unsigned char buf[6];
    void *packet;
    int size;
    unsigned char *p;
    p = buf;
    size = 6;
    packet = fn_8022EFF8(2);
    if (packet != 0) {
        switch (arg0) {
        case 1:
            memcpy(p, arg1, 3);
            memcpy(buf + 3, arg1 + 3, 3);
            break;
        case 2:
            p = arg1;
            break;
        case 0:
            size = 0;
            break;
        default:
            return 5;
        }
        lbl_80529CF8[0x1844] = 1;
        fn_80245D9C(packet, 1, arg0, p, size);
        return 1;
    }
    return 3;
}