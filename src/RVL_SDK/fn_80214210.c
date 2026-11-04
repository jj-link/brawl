#pragma force_active on

typedef unsigned int u32;

typedef struct {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    char pad20[0xE0];
    int field100;
    int field104;
    int field108;
    void *field10C;
    char pad110[0x30];
} Request;

extern int lbl_8059ECD0;
extern int lbl_805A0C1C;
extern u32 fn_80211AF8(const char *, u32);
extern Request *fn_802137A4(int, int, int);
extern void *memcpy(void *, const void *, u32);
extern void fn_80213C80(void);
extern int fn_80212FAC(int, int, int, int, void *, void (*)(void), void *);

int fn_80214210(const char *name, int flags, int *data, int a3, int a4)
{
    u32 length;
    Request *request;
    int aligned;
    int aligned2;
    int inCount;
    int outCount;

    if (name == 0 || data == 0 || lbl_8059ECD0 < 0 ||
        (flags & 0x1F) ||
        (length = fn_80211AF8(name, 0x40)) == 0x40) {
        return -0x65;
    }

    request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (request == 0) {
        return -0x76;
    }

    request->field100 = a3;
    request->field104 = a4;
    request->field108 = 2;
    aligned = (u32)request + 0x3F & 0xFFFFFFE0;
    request->field10C = data;
    memcpy((void *)aligned, name, length + 1);
    request->field0 = aligned;
    request->field4 = 0x40;
    aligned2 = aligned + 0x5F & 0xFFFFFFE0;
    request->field8 = aligned2;
    request->fieldC = 4;
    if (flags != 0) {
        inCount = 2;
        outCount = 2;
        *(int *)aligned2 = *data;
        request->field10 = flags;
        request->field14 = *data * 0xD;
        request->field18 = aligned2;
        request->field1C = 4;
    } else {
        inCount = 1;
        outCount = 1;
    }

    return fn_80212FAC(lbl_8059ECD0, 4, inCount, outCount, request,
                       fn_80213C80, request);
}
