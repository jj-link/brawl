#pragma force_active on
typedef unsigned int u32;

typedef struct Request {
    char data[0x100];
    int arg2;
    int arg3;
    int zero;
} Request;

extern int lbl_8059ECD0;
extern int lbl_805A0C1C;

extern u32 fn_80211AF8(const void *, u32);
extern Request *fn_802137A4(int, int, int);
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_80213C80(int, void *);
extern int fn_80212C08(int, int, void *, int, int, int,
                     void (*)(int, void *), void *);

int fn_80214994(const void *arg0, const void *arg1, int arg2, int arg3)
{
    u32 len0;
    u32 len1;
    Request *request;

    if (arg0 == 0 || arg1 == 0 || lbl_8059ECD0 < 0 ||
        (len0 = fn_80211AF8(arg0, 0x40)) == 0x40 ||
        (len1 = fn_80211AF8(arg1, 0x40)) == 0x40) {
        return -0x65;
    }

    request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (request == 0) {
        return -0x76;
    }

    request->arg2 = arg2;
    request->arg3 = arg3;
    request->zero = 0;
    memcpy(request, arg0, len0 + 1);
    memcpy((char *)request + 0x40, arg1, len1 + 1);

    return fn_80212C08(lbl_8059ECD0, 8, request, 0x80, 0, 0,
                      fn_80213C80, request);
}
