#pragma force_active on

extern void OSLockMutex(void *);
extern void OSUnlockMutex(void *);
extern void OSReport(const char *, ...);
extern int fn_80212D40(int, int, void *, int, int *, int);

extern char lbl_804927E0[];
extern char lbl_80563940[];
extern int lbl_8059FE98;
extern int lbl_805A1230;
extern int lbl_805A1234;
extern int *lbl_805A1238;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
} SDHCArg;

int fn_803CB83C(SDHCArg *arg0)
{
    char *base = lbl_804927E0;
    int result;

    if (lbl_8059FE98 < 0) {
        result = 0xC1000000;
    } else {
        OSLockMutex(lbl_80563940);
        if (lbl_805A1234 != 0) {
            OSUnlockMutex(lbl_80563940);
            result = 0xC1000000;
        } else {
            lbl_805A1234 = 1;
            OSUnlockMutex(lbl_80563940);
            result = fn_80212D40(arg0->unk0, 4, 0, 0, lbl_805A1238, 4);
            if (result != 0) {
                if ((unsigned int)(result + 0x3F000000) == 0x20) {
                    OSReport(base + 0x240);
                } else {
                    OSReport(base + 0x26C, result);
                }
                arg0->unk10 = 0;
                lbl_805A1234 = 0;
            } else {
                arg0->unk10 = *lbl_805A1238;
                lbl_805A1230 = 0x10000;
                arg0->unk24 = 2;
                lbl_805A1234 = 0;
            }
        }
    }

    if (result != 0) {
        OSReport(base + 0x290, result);
    }

    return result;
}