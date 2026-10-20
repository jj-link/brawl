#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void* v1(void* arg);
};

struct Obj {
    char pad0[0x30];
    void* m30;
    char pad1[0x58 - 0x34];
    Inner* m58;
};

extern "C" void fn_27_422C4(void* a, void* b, void* c);

extern "C" void fn_27_43BAC(Obj* self, void* a, void* b) {
    void* p = self->m58->v1(b);
    fn_27_422C4(p, self->m30, a);
}
