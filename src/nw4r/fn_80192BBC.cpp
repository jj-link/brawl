#pragma force_active on
extern "C" void fn_801D7748(void *, int);

extern "C" void fn_80192BBC(void **arg0) {
    void *p = *arg0;
    int x = *(int *)((char *)p + 4);
    fn_801D7748(p, x);
}
