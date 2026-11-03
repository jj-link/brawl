#pragma force_active on
extern void *fn_803974FC(void);

void *fn_80390044(void *arg0, void *arg1) {
    void *obj = fn_803974FC();
    {
        void *(*f)(void *, void *) =
            *(void *(**)(void *, void *))(
                (char *)obj + 0x7c4);
        if (f != 0) {
            return f(arg0, arg1);
        }
    }
    return 0;
}