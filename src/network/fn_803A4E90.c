#pragma force_active on
extern unsigned long strlen(const char *);
extern char *strncpy(char *, const char *, unsigned long);
extern int snprintf(char *, unsigned long, const char *, ...);
extern unsigned char *lbl_805A1170;
extern char lbl_8059FDF8[0x6];

typedef struct {
    unsigned short unk0;
    char pad[0xB2];
    char name[4];
} UnkArg0;

int fn_803A4E90(UnkArg0 *arg0, char *arg1, unsigned long arg2, int arg3, int arg4) {
    unsigned char *base;
    int ret;
    unsigned long len;
    unsigned short v;

    if (lbl_805A1170 != 0) {
        base = lbl_805A1170 + 0x3600;
    } else {
        base = 0;
    }
    if (arg0 == 0) {
        ret = -3;
    } else if (base == 0) {
        ret = -9;
    } else {
        v = arg0->unk0;
        if (v != 0xFFFF && v >= *(unsigned short *)(base + 0x14)) {
            ret = -3;
        } else {
            ret = 0;
        }
    }
    if (ret != 0) {
        return ret;
    }
    len = strlen(arg0->name);
    if (len == 0) {
        return -13;
    }
    if (len < 8) {
        return -2;
    }
    if (len + ((arg3 != 0) ? 3 : 0) + 1 > arg2) {
        return -11;
    }
    strncpy(arg1, arg0->name, len);
    arg1[len] = 0;
    if (arg3 != 0) {
        snprintf(arg1 + len, arg2 - len, lbl_8059FDF8, arg4);
    }
    return 0;
}
