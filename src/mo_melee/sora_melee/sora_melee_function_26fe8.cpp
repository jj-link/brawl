#pragma force_active on
struct fn27Obj {
    virtual void* f0();
    virtual void* f1(void* p);
    virtual void* f2();
};

struct fn27Owner {
    char pad[0x28];
    fn27Obj* m_obj;
};

extern "C" {
void fn_27_2EF34(void* result, void* p);
void fn_27_26FE8(fn27Owner* self, void* a, void* b);
}

extern "C" void fn_27_26FE8(fn27Owner* self, void* a, void* b) {
    void* r = self->m_obj->f1(b);
    fn_27_2EF34(r, a);
}
