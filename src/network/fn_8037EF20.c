#pragma force_active on
extern int fn_8037C720();
extern void fn_8037C5AC();

void fn_8037EF20(void) {
    if (fn_8037C720() != 0) {
        fn_8037C5AC();
    }
}
