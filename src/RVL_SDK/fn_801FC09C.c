#pragma force_active on
typedef int (*FnPtr)(int, int);

extern char lbl_80476B18[];
extern char lbl_804E44AC[0xD4];
extern FnPtr lbl_805A09A0;

int fn_8020A7F8(void *, int, int, void *, void *);
void fn_801FBFF4(void);

void fn_801FC09C(int arg0) {
    if (arg0 == 0 || arg0 == -6) {
        if (fn_8020A7F8(lbl_80476B18, 0x3F, 0, fn_801FBFF4, lbl_804E44AC) && lbl_805A09A0) {
            lbl_805A09A0(2, 0);
        }
    } else if (lbl_805A09A0) {
        lbl_805A09A0(2, 0);
    }
}
