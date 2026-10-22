#pragma force_active on
typedef unsigned int u32;

typedef struct Request {
    char data[0x100];
    int field100;
    int field104;
    int field108;
} Request;

extern int lbl_805A0C1C;
extern u32 fn_80211AF8(const char *, u32);
extern Request *fn_802137A4(int, int, int);
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_80213C80(void);
extern int fn_80212290(Request *, int, void (*)(void), Request *);

int fn_80214E80(const char *name, int a1, int a2, int a3)
{
    u32 length;
    Request *request;

    if (name == 0 || (length = fn_80211AF8(name, 0x40)) == 0x40) {
        return -101;
    }

    request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (request == 0) {
        return -118;
    }

    request->field100 = a2;
    request->field104 = a3;
    request->field108 = 0;
    memcpy(request, name, length + 1);

    return fn_80212290(request, a1, fn_80213C80, request);
}
