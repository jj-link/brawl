#pragma force_active on

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Request {
    int field0;
    u16 field4;
    char name[0x40];
    u8 field46;
    u8 field47;
    u8 field48;
    u8 field49;
    char pad4A[0xB6];
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

int fn_80214CC4(const char *name, signed char a1, signed char a2,
                signed char a3, signed char a4, int a5, int a6)
{
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

    request->field100 = a5;
    request->field104 = a6;
    request->field108 = 0;
    memcpy(request->name, name, length + 1);
    request->field49 = a1;
    request->field46 = a2;
    request->field47 = a3;
    request->field48 = a4;

    return fn_80212C08(lbl_8059ECD0, 9, request, 0x4C, 0, 0,
                       fn_80213C80, request);
}
