#pragma force_active on
extern int lbl_805A0998;
extern void (*lbl_805A09A0)(int, int);
extern char lbl_80476B18[];
extern char lbl_804E4420[];
extern char lbl_804E44AC[];
extern void fn_801FBED8(void);
int fn_8020BB4C(void *, void *, int, void *, void *);

void fn_801FBFF4(int arg0) {
    if (arg0 == 0 || arg0 == -6) {
        if (arg0 == -6) {
            lbl_805A0998 = 1;
        }
        if (fn_8020BB4C(lbl_80476B18, lbl_804E4420, 3, fn_801FBED8, lbl_804E44AC) != 0) {
            if (lbl_805A09A0 != 0) {
                lbl_805A09A0(2, 0);
            }
        }
    } else {
        if (lbl_805A09A0 != 0) {
            lbl_805A09A0(2, 0);
        }
    }
}
