#pragma force_active on

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Request {
    char name[0x40];
    char pad40[0xC0];
    int field100;
    int field104;
    int field108;
} Request;

extern int lbl_8059ECD0;
extern int lbl_805A0C1C;
extern u32 fn_80211AF8(const char *, u32);
extern Request *fn_802137A4(int, int, int);
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_80213C80(void);
extern int fn_80212C08(int, int, void *, int, int, int, void (*)(void), void *);

int fn_802148C4(const char *name, int arg1, int arg2) {
    u32 length;
    Request *request;

    if (name == 0 || lbl_8059ECD0 < 0 ||
        (length = fn_80211AF8(name, 0x40)) == 0x40) {
        return -101;
    }

    request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (request == 0) {
        return -118;
    }

    memcpy(request->name, name, length + 1);
    request->field100 = arg1;
    request->field104 = arg2;
    request->field108 = 0;

    return fn_80212C08(lbl_8059ECD0, 7, request, 0x40, 0, 0,
                       fn_80213C80, request);
}