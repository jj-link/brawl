#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern int lbl_804F6810[];
extern int fn_8022E1E4(unsigned char);
extern void fn_80239968(void *);
extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);

void fn_80218EB8(int arg0, int arg1) {
    unsigned char sp8[6];
    int s;
    int r;
    int p;
    int q;

    p = lbl_804F6810[arg0];
    if (arg1 != 0) {
        s = OSDisableInterrupts();
        *(unsigned char *)(p + 0x160) = 0;
        *(unsigned char *)(p + 0x161) = 0;
        memset(*(void **)(p + 0x164), 0, *(int *)(p + 0x168) * 0x30);
        OSRestoreInterrupts(s);
        if (arg1 != -1) {
            s = lbl_804F6810[arg0];
            q = OSDisableInterrupts();
            s = *(int *)(s + 0x8BC);
            OSRestoreInterrupts(q);
            if (s != -1) {
                r = lbl_804F6810[arg0];
                q = OSDisableInterrupts();
                r = *(unsigned char *)(r + 0x8C3);
                OSRestoreInterrupts(q);
                r = fn_8022E1E4(r);
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