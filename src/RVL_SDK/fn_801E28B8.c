#pragma force_active on
extern int lbl_805A070C;
extern int lbl_805A0710;
extern int lbl_804DDFA0[8];
extern char lbl_804DDFC0[32];

int fn_80212D40(int, int, void *, int, void *, int);

int fn_801E28B8(int arg)
{
    if (lbl_805A070C == 0) {
        return -6;
    }
    lbl_804DDFA0[0] = arg;
    return fn_80212D40(lbl_805A0710, 0x6002, lbl_804DDFA0, 0x20, lbl_804DDFC0, 0x20);
}
