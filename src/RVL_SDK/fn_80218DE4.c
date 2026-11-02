#pragma force_active on

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern int lbl_804F6810[];
extern int fn_8022E1E4(unsigned char);
extern void fn_80239968(void *p);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern void *memset(void *dst, int c, unsigned long n);

void fn_80218DE4(int arg0, int arg1) {
    unsigned char sp8[6];
    int p;
    int s;
    int r;
    void (*fn)(void);

    p = lbl_804F6810[arg0];
    if (arg1 != -1) {
        if (arg1 == 0) {
            *(int *)(p + 0x8DC) = 1;
            fn = *(void (**)(void))(p + 0x8A4);
            if (fn != 0) {
                fn();
            }
        } else {
            s = OSDisableInterrupts();
            r = *(int *)(p + 0x8BC);
            OSRestoreInterrupts(s);
            if (r != -1) {
                p = lbl_804F6810[arg0];
                s = OSDisableInterrupts();
                p = *(unsigned char *)(p + 0x8C3);
                OSRestoreInterrupts(s);
                r = fn_8022E1E4(p);
                if (r != 0) {
                    memcpy(sp8, (void *)r, 6);
                } else {
                    memset(sp8, 0, 6);
                }
                fn_80239968(sp8);
            }
        }
    }
}
