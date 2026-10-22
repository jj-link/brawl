#pragma force_active on
typedef unsigned char u8;

typedef struct Obj {
    int unk0;
    u8 pad4[0x10];
    int unk14;
    u8 pad18[0xC];
    int unk24;
    int unk28;
} Obj;

extern int snprintf(char *s, unsigned long n, const char *format, ...);
extern char lbl_80490DA0[];

int fn_8038D54C(Obj *arg0, int arg1, char *arg2) {
    if (arg0 == 0 || arg2 == 0 || arg0->unk0 == 0 || arg0->unk24 == 0) {
        return 0;
    }
    return (((unsigned int)snprintf(arg2, 0x80, lbl_80490DA0, (char *)arg0 + 4, arg1, arg0->unk14, arg0->unk28)) >> 31) ^ 1;
}
