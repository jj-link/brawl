#pragma force_active on
struct FtNessComposite {
    virtual void m0(void*);
    virtual void m1(void*);
    virtual void m2(void*);
    virtual void m3(void*);
    virtual void m4(void*);
    virtual void m5(void*);
    virtual void m6(void*);
    virtual void m7(void*);
    virtual void m8(void*);
    virtual void m9(void*);
    virtual void m10(void*);
};

extern "C" void fn_101_B4D8(FtNessComposite* self, int* args, int count) {
    if (args == 0 || count <= 0)
        return;
    for (int i = 0; i < count; ++i) {
        self->m10(args + i);
    }
}
