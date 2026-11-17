#pragma force_active on
extern int fn_80211080(void);
extern unsigned int fn_801D718C(int, int);
extern int fn_801D9A90(unsigned int, unsigned int);
extern int fn_8021111C(long long, unsigned int);
extern int fn_802112C8(long long, unsigned int, int *);
extern void *memcpy(void *, const void *, int);
extern void *memset(void *, int, int);

void fn_801D9E10(long long id) {
    int sp8;
    unsigned int buf;
    unsigned int buf2;
    int idx;

    sp8 = 1;
    if (fn_80211080() == 0) {
        buf = fn_801D718C(0xE0, 0x20);
        if (buf != 0) {
            memset((void *)buf, 0, 0xE0);
            if (fn_802112C8(id, 0U, &sp8) == 0) {
                buf2 = fn_801D718C((sp8 * 0xD8 + 0x1F) & ~0x1F, 0x20);
                if (buf2 != 0 && fn_802112C8(id, buf2, &sp8) == 0) {
                    idx = fn_801D9A90(buf2, sp8);
                    if (idx >= 0) {
                        memcpy((void *)buf, (void *)(buf2 + idx * 0xD8), 0xD8);
                        if (fn_8021111C(id, buf) == 0) {
                            for (;;) {
                            }
                        }
                    }
                }
            }
        }
    }
}
