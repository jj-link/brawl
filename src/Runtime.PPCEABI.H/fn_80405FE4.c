#pragma force_active on
extern void fn_8025FCC8(void);

int gdev_cc_post_stop(void) {
    fn_8025FCC8();
    return 0;
}
