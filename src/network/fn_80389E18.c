#pragma force_active on
typedef struct {
    unsigned int words[65];
} Copy104;

typedef struct {
    unsigned char pad0[4];
    void *field4;
    unsigned char pad8[0xF8];
    int mode;
} Context;

extern int fn_80389B5C(const void *, const void *);
extern int fn_80389BF8(const void *, const void *);
extern int fn_80389CD0(const void *, const void *);
extern int fn_80389D74(const void *, const void *);
extern void *lbl_805A1134;
extern void fn_8035AAC0(void *, int (*)(const void *, const void *));
extern unsigned int strlen(const char *);
extern int strcmp(const char *, const char *);

void fn_80389E18(void *arg0, int arg1, Context *arg2) {
    int (*callback)(const void *, const void *);
    char *base = (char *)arg0;

    switch (arg2->mode) {
    case 0:
        callback = fn_80389B5C;
        break;
    case 1:
        callback = fn_80389BF8;
        break;
    case 2:
        callback = fn_80389CD0;
        break;
    case 3:
        callback = fn_80389D74;
        break;
    default:
        callback = fn_80389D74;
        break;
    }

    if (strlen(base + 0x59C) == 0) {
        *(Copy104 *)(base + 0x59C) = *(Copy104 *)arg2;
    } else if (strcmp((const char *)arg2, base + 0x498) != 0) {
        *(Copy104 *)(base + 0x59C) = *(Copy104 *)(base + 0x498);
    }

    *(Copy104 *)(base + 0x498) = *(Copy104 *)arg2;
    *(int *)(base + 0x6A0) = arg1;
    lbl_805A1134 = arg0;
    fn_8035AAC0(*(void **)(base + 4), callback);
}
