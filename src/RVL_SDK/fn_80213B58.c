#pragma force_active on
extern void OSReport(const char *, ...);
extern unsigned int fn_80211AE0(void);
extern int fn_80211AE8(void);
extern void fn_80211AF0(unsigned int);
extern int fn_802123A8(int, int);
extern int fn_80213468(int, int);
extern char *strcpy(char *, const char *);

extern char lbl_8047C5A8[];
extern int lbl_8059ECD0;
extern char lbl_8059ECD8;
extern int lbl_805A0C08;
extern int lbl_805A0C0C;
extern int lbl_805A0C14;
extern unsigned int lbl_805A0C18;
extern int lbl_805A0C1C;

int fn_80213B58(void)
{
    int result = 0;
    int r30;
    int r;

    if (lbl_805A0C08 == 0) {
        lbl_805A0C14 = fn_80211AE8();
        lbl_805A0C18 = fn_80211AE0();
    }
    r = (lbl_805A0C14 + 0x1F) & ~0x1F;
    lbl_805A0C0C = r;
    if (lbl_805A0C08 == 0 && (unsigned int)(r + 0x40) > lbl_805A0C18) {
        OSReport(lbl_8047C5A8);
        result = -22;
    } else {
        strcpy((char *)r, &lbl_8059ECD8);
        r = fn_802123A8(lbl_805A0C0C, 0);
        lbl_8059ECD0 = r;
        if (r < 0) {
            result = r;
        } else {
            r30 = lbl_805A0C0C;
            if (lbl_805A0C08 == 0 && (unsigned int)(r30 + 0x1540) > lbl_805A0C18) {
                OSReport(lbl_8047C5A8);
                result = -22;
            } else {
                if (lbl_805A0C08 == 0) {
                    fn_80211AF0(r30 + 0x1540);
                    lbl_805A0C08 = 1;
                }
                r = fn_80213468(r30, 0x1540);
                lbl_805A0C1C = r;
                if (r < 0) {
                    result = -22;
                }
            }
        }
    }
    return result;
}
