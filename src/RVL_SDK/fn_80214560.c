#pragma force_active on

typedef unsigned int u32;

typedef struct Stat {
    int value;
    unsigned short value4;
    char name[64];
    unsigned char value46;
    unsigned char value47;
    unsigned char value48;
    unsigned char value49;
} Stat;

extern int lbl_8059ECD0;
extern int lbl_805A0C1C;
extern u32 fn_80211AF8(const char *, u32);
extern void *fn_802137A4(int, int, int);
extern void fn_802137A8(int, void *);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void *memcpy(void *, const void *, unsigned int);

int fn_80214560(const char *name, int *a1, unsigned short *a2, int *a3,
                int *a4, int *a5, int *a6)
{
    int result;
    u32 length;
    Stat *st;
    void *request = 0;

    if (name == 0 || lbl_8059ECD0 < 0 ||
        (length = fn_80211AF8(name, 64)) == 64 ||
        a1 == 0 || a2 == 0 || a3 == 0 || a4 == 0 || a5 == 0 || a6 == 0) {
        result = -101;
    } else {
        request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
        if (request == 0) {
            result = -22;
        } else {
            memcpy(request, name, length + 1);
            st = (Stat *)(((u32)request + 0x5f) & ~31);
            result = fn_80212D40(lbl_8059ECD0, 6, request, 0x40, st, 0x4C);
            if (result == 0) {
                *a1 = st->value;
                *a2 = st->value4;
                *a3 = st->value49;
                *a4 = st->value46;
                *a5 = st->value47;
                *a6 = st->value48;
            }
        }
    }

    if (request != 0) {
        if (request != 0) {
            fn_802137A8(lbl_805A0C1C, request);
        }
    }

    return result;
}
