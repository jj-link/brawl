#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
typedef struct { unsigned char data[96]; } Entry;
typedef struct { unsigned char pad[0xa0]; Entry entries[2]; } State;
extern State *lbl_804F6810[];
void fn_802209A4(int arg0, void *arg1) {
    int level = OSDisableInterrupts();
    unsigned char *p1 = (unsigned char *)arg1;
    unsigned char *base = (unsigned char *)lbl_804F6810[arg0 & 0xFF];
    unsigned char *r7 = ((State *)base)->entries[base[0x8C8]].data;
    int i;
    for (i = 0; i < 96; i++) {
        r7[i] = 0;
    }
    *(unsigned short *)r7 = (unsigned short)((p1[1] | (p1[2] << 8)) & 0x9F1F);
    if (*(int *)(base + 0x8B8) == 0) {
        r7[0x29] = 0;
    } else {
        ((signed char *)r7)[0x29] = -4;
    }
    r7[0x28] = base[0x8C1];
    *(int *)(base + 0x848) = (p1[1] >> 7) & 1;
    base[0x8C8] = (base[0x8C8] == 0);
    OSRestoreInterrupts(level);
}