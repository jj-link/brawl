#pragma force_active on
extern int fn_803C3340(void *);
extern int fn_803C3F48(const char *);
extern int fn_803C40C4(void *, int);
extern char lbl_8059FCC8[4];

int fn_80398EEC(void *p)
{
    int result = fn_803C3340(p);

    if (result == 0xB001)
        return -20;

    if (result != 0) {
        if (result == 5) {
            switch (fn_803C3F48(lbl_8059FCC8)) {
            case -15:
            case -5:
                return -46;
            case -4:
                return -38;
            default:
                return -43;
            }
        }
        return -43;
    }

    result = fn_803C40C4(p, 1);
    if (result != 0) {
        if (result == 5) {
            switch (fn_803C3F48(lbl_8059FCC8)) {
            case -15:
            case -5:
                return -46;
            case -4:
                return -38;
            default:
                return -43;
            }
        }
        return -43;
    }

    return 0;
}
