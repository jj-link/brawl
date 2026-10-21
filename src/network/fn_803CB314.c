#pragma force_active on
extern int lbl_8059FE98;
extern char lbl_804927E0[];
extern char lbl_80563940[];
extern int lbl_805A1234;
extern int *lbl_805A1238;

void OSLockMutex(void *);
void OSUnlockMutex(void *);
void OSReport(const char *, ...);
int fn_80212D40(int, int, void *, int, int *, int);

int fn_803CB314(int *arg0, int *arg1)
{
    char *base = lbl_804927E0;
    int result = (int)0xC1000000;

    if (lbl_8059FE98 >= 0 && arg1 != 0) {
        OSLockMutex(lbl_80563940);
        if (lbl_805A1234 != 0) {
            OSUnlockMutex(lbl_80563940);
        } else {
            lbl_805A1234 = 1;
            OSUnlockMutex(lbl_80563940);
            result = fn_80212D40(*arg0, 11, 0, 0, lbl_805A1238, 4);
            if (result != 0) {
                OSReport(base + 0x124);
                lbl_805A1234 = 0;
            } else {
                *arg1 = *lbl_805A1238;
                lbl_805A1234 = 0;
            }
        }
    }

    if (result != 0) {
        OSReport(base + 0xAC, base + 0x110, result);
    }

    return result;
}
