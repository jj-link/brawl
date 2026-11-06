#pragma force_active on
typedef unsigned int u32;

typedef struct Request {
    char data[0x100];
    int field100;
    int field104;
    int field108;
    int field10c;
    int field110;
    int field114;
    int field118;
    int field11c;
    int field120;
} Request;

extern int lbl_8059ECD0;
extern int lbl_805A0C1C;
extern u32 fn_80211AF8(const char *, u32);
extern Request *fn_802137A4(int, int, int);
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_80213C80(void);
extern int fn_80212C08(int, int, void *, int, int, int, void (*)(void), void *);

int fn_802146B8(const char *name, int a1, int a2, int a3, int a4,
                int a5, int a6, int a7, int a8)
{
    u32 length;
    Request *request;

    if (name == 0 || lbl_8059ECD0 < 0 ||
        (length = fn_80211AF8(name, 0x40)) == 0x40 ||
        a1 == 0 || a2 == 0 || a3 == 0 || a4 == 0 || a5 == 0 || a6 == 0) {
        return -101;
    }

    request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (request == 0) {
        return -118;
    }

    request->field10c = a1;
    request->field110 = a2;
    request->field114 = a3;
    request->field118 = a4;
    request->field11c = a5;
    request->field120 = a6;
    request->field100 = a7;
    request->field104 = a8;
    request->field108 = 3;
    memcpy(request, name, length + 1);

    return fn_80212C08(lbl_8059ECD0, 6, request, 0x40,
                       ((u32)request + 0x5f) & ~31, 0x4c,
                       fn_80213C80, request);
}