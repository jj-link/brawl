#pragma force_active on
extern void fn_8025FCCC(void);

int gdev_cc_pre_continue(void) {
    fn_8025FCCC();
    return 0;
}
