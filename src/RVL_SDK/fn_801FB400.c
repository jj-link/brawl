#pragma force_active on
#pragma optimization_level 2
extern int lbl_805A0944;
extern void fn_801FDDF0(int);
extern void fn_801FDDFC(void *);
extern void fn_801FB330(int);
void fn_801FB400(void) {
 lbl_805A0944 = 0;
 fn_801FDDF0(0);
 fn_801FDDFC((void *)fn_801FB330);
 do {} while (lbl_805A0944 == 0);
}
