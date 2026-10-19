#pragma force_active on
struct fn27Inner {
    virtual void vfunc0();
    virtual void* vfunc1(void* p);
};

struct fn27Obj {
    char pad[0x48];
    fn27Inner* m_48;
};

extern "C" {
void fn_27_46E48(void* r, void* p);

void fn_27_49094(fn27Obj* self, void* a, void* b) {
    void* r = self->m_48->vfunc1(b);
    fn_27_46E48(r, a);
}
}
