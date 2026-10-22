#pragma force_active on

typedef unsigned int u32;

typedef struct Request {
    int value;
    short value4;
    char name[64];
    signed char value46;
    signed char value47;
    signed char value48;
    signed char value49;
    char padding[2];
} Request;

extern int lbl_8059ECD0;
extern int lbl_805A0C1C;
extern u32 fn_80211AF8(const char *, u32);
extern Request *fn_802137A4(int, int, int);
extern void fn_802137A8(int, void *);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void *memcpy(void *, const void *, unsigned int);

int fn_80213ED4(const char *name, signed char value49,
                signed char value46, signed char value47,
                signed char value48)
{
    Request *request = 0;
    int result;
    u32 length;

    if (name == 0 || lbl_8059ECD0 < 0 ||
        (length = fn_80211AF8(name, 64)) == 64) {
        result = -101;
    } else {
        request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
        if (request == 0) {
            result = -22;
        } else {
            memcpy(request->name, name, length + 1);
            request->value49 = value49;
            request->value46 = value46;
            request->value47 = value47;
            request->value48 = value48;
            result = fn_80212D40(lbl_8059ECD0, 3, request, 0x4C, 0, 0);
        }
    }

    if (request != 0) {
        if (request != 0) {
            fn_802137A8(lbl_805A0C1C, request);
        }
    }

    return result;
}
