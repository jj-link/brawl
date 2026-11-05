#pragma force_active on
extern void *lbl_805A10F0;
extern int fn_8035A590(void *);
extern int fn_8035A598(void *, int);
extern void fn_80386704(int);

void fn_80386C14(void) {
    int i;
    if (lbl_805A10F0 == 0 || fn_8035A590(lbl_805A10F0) == 0) {
        fn_80386704(0);
    } else {
        for (i = fn_8035A590(lbl_805A10F0) - 1; i >= 0; i--) {
            fn_80386704(fn_8035A598(lbl_805A10F0, i));
        }
    }
}