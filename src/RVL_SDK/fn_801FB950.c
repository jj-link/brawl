#pragma force_active on
extern int fn_8020BCA8(void*, void*, void*);
extern int fn_801FB924(int);
extern char lbl_804E4420[0x8C];
extern char lbl_804E44AC[0xD4];
typedef int (*FnPtr)(int, int);
extern FnPtr lbl_805A09A0;

void fn_801FB950(void) {
    if (fn_8020BCA8(&lbl_804E4420, fn_801FB924, &lbl_804E44AC) && lbl_805A09A0) {
        lbl_805A09A0(2, 0);
    }
}
