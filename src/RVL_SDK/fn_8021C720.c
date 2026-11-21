#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on

extern int lbl_804F6810[];
extern int fn_8021C564(int);

static inline int enqueue(void *p, const void *copy) {
    void *records;
    int lvl1, lvl2;
    int d, n;
    signed char idx;
    int wrote;
    lvl1 = OSDisableInterrupts();
    lvl2 = OSDisableInterrupts();
    d = (signed char)(((unsigned char *)p)[0x161] -
                      ((unsigned char *)p)[0x160]);
    if (d < 0) d = (signed char)(d + *(int *)((char *)p + 0x168));
    OSRestoreInterrupts(lvl2);
    if ((unsigned int)(*(int *)((char *)p + 0x168) - 1) ==
        (unsigned int)d) {
        OSRestoreInterrupts(lvl1);
        return 0;
    }
    {
        records = *(void **)((char *)p + 0x164);
        memset((char *)records +
                   (signed char)((unsigned char *)p)[0x161] * 0x30,
               0, 0x30);
        records = *(void **)((char *)p + 0x164);
        memcpy((char *)records +
                   (signed char)((unsigned char *)p)[0x161] * 0x30,
               copy, 0x30);
        idx = (signed char)((unsigned char *)p)[0x161];
        n = *(int *)((char *)p + 0x168) - 1;
        ((unsigned char *)p)[0x161] = (idx == n) ? 0 : idx + 1;
        OSRestoreInterrupts(lvl1);
        return 1;
    }
}

int fn_8021C720(int arg0, void *arg1, int arg2) {
    void *p;
    void *records;
    int copy[12];
    int hdr[12];
    int lvl1, lvl2;
    int r30_val, r29_val;
    int d;
    int n;
    signed char idx;
    int wrote;

    p = (void *)lbl_804F6810[arg0];
    lvl1 = OSDisableInterrupts();
    r30_val = *(int *)((char *)p + 0x8bc);
    r29_val = *(int *)((char *)p + 0x8dc);
    OSRestoreInterrupts(lvl1);
    if (r30_val == -1) return -1;
    if (r29_val == 0) return -2;
    if (fn_8021C564(arg0) != 0) return -2;

    hdr[0] = 0x18;
    *(short *)((char *)hdr + 0x1a) = 0x15;
    ((char *)hdr)[4] = (char)((arg2 * 8) & 0xf8);
    hdr[11] = 0;
    memcpy((char *)hdr + 5, arg1, arg2);
    copy[0] = hdr[0];
    copy[1] = hdr[1];
    copy[2] = hdr[2];
    copy[3] = hdr[3];
    copy[4] = hdr[4];
    copy[5] = hdr[5];
    copy[6] = hdr[6];
    copy[7] = hdr[7];
    copy[8] = hdr[8];
    copy[9] = hdr[9];
    copy[10] = hdr[10];
    copy[11] = hdr[11];

    {
        int en = OSDisableInterrupts();
        int en2 = OSDisableInterrupts();
        int count = (signed char)(((unsigned char *)p)[0x161] - ((unsigned char *)p)[0x160]);
        if (count < 0) count = (signed char)(count + *(int *)((char *)p + 0x168));
        OSRestoreInterrupts(en2);
        if ((unsigned int)(*(int *)((char *)p + 0x168) - 1) == (unsigned int)count) {
            OSRestoreInterrupts(en);
            wrote = 0;
        } else {
            void *buf = *(void **)((char *)p + 0x164);
            memset((char *)buf + (signed char)((unsigned char *)p)[0x161] * 0x30, 0, 0x30);
            buf = *(void **)((char *)p + 0x164);
            memcpy((char *)buf + (signed char)((unsigned char *)p)[0x161] * 0x30, copy, 0x30);
            {
                signed char tail = (signed char)((unsigned char *)p)[0x161];
                int size = *(int *)((char *)p + 0x168) - 1;
                ((unsigned char *)p)[0x161] = tail == size ? 0 : tail + 1;
            }
            OSRestoreInterrupts(en);
            wrote = 1;
        }
    }
    if (wrote == 0) return -2;
    lvl1 = OSDisableInterrupts();
    ((unsigned char *)p)[0x8cf] = ((unsigned char *)p)[0x8cf] + 1;
    OSRestoreInterrupts(lvl1);
    return 0;
}
