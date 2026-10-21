#pragma force_active on
extern void *fn_803974FC(void);

void fn_803900A0(void *arg0) {
    void (*fn)(void *);

    fn = *(void (**)(void *))((char *)fn_803974FC() + 0x7c8);
    if (fn != 0) {
        fn(arg0);
    }
}
