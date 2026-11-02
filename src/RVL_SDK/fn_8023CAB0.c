#pragma force_active on

extern char lbl_80529CF8[];
extern int fn_803F6150(const void *, const void *, unsigned long);

typedef void (*Callback)(void *, int);

int fn_8023CAB0(const void *arg0)
{
    unsigned int i;
    char *p;

    if (*(unsigned char *)(lbl_80529CF8 + 0x1848) != 0 ||
        *(unsigned char *)(lbl_80529CF8 + 0x16AE) != 0 ||
        *(unsigned char *)(lbl_80529CF8 + 0x1844) != 0) {
        return 2;
    }

    p = lbl_80529CF8 + 0x16E4;
    i = 0;
    do {
        if (*(unsigned char *)(p + 0x1A) != 0 &&
            (arg0 == 0 || fn_803F6150(p + 0xA, arg0, 6) == 0)) {
            *(unsigned char *)(p + 0x1A) = 0;
            if (*(Callback *)(lbl_80529CF8 + 0x16BC) != 0) {
                (*(Callback *)(lbl_80529CF8 + 0x16BC))(p + 8, 0);
            }
        }
        ++i;
        p += 0x1C;
    } while (i < 12);
    return 0;
}
