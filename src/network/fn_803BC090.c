#pragma force_active on
extern void fn_803B84E8(void *p);

void fn_803BC090(void *arg0) {
    unsigned short i;
    unsigned char *base = (unsigned char *)arg0;
    unsigned char *p;

    for (i = 0; i < 5; i++) {
        p = base + (unsigned short)i * 0x290;
        *(unsigned int *)(p + 0x40) = 0;
        fn_803B84E8(p + 0x44);
    }
    *(unsigned int *)(base + 0xD10) &= ~1;
    *(unsigned int *)(base + 0xD40) &= ~1;
    *(unsigned int *)(base + 0xD70) &= ~1;
    *(unsigned int *)(base + 0xDA0) &= ~1;
    *(unsigned int *)(base + 0xDD0) &= ~1;
    *(unsigned int *)(base + 0x15E0) = 0;
}
