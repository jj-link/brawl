#pragma force_active on

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

extern "C" {
extern void* lbl_804666F8[];
void __dl__FPv(void*);

Object* fn_80073028(Object* self, int flag) {
    if (self != 0) {
        // Restore the vtable pointer, then invoke the two virtual cleanups.
        *(void**)self = lbl_804666F8;
        self->v2();          // vtable offset 0x10
        self->v5();          // vtable offset 0x1c
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
