#pragma force_active on
extern void fn_801F0530(void);
extern void fn_801EEE74(void);
extern unsigned char lbl_805A0898;

typedef struct {
    int a, b, c, d, e, f, g, h, i;
} Ctx;

extern Ctx lbl_804DED84;

int fn_801EEF7C(Ctx *arg0) {
    if (lbl_805A0898 == 0) {
        return 0;
    }
    fn_801F0530();
    fn_801EEE74();
    *arg0 = lbl_804DED84;
    return 1;
}
