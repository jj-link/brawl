#pragma force_active on
extern void *fn_803CD2C4(void);

void fn_803D4848(void) {
    void *p = fn_803CD2C4();
    if (p) {
        *(unsigned int *)((char *)p + 0x34) = 0;
        *(unsigned int *)((char *)p + 0x38) = 0;
    }
}
