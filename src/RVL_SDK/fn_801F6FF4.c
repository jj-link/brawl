#pragma force_active on
extern void fn_801F6EE4(void);
extern void fn_801FD98C(int, int, void (*)(void));

void fn_801F6FF4(void) {
    fn_801FD98C(0, 0, fn_801F6EE4);
}
