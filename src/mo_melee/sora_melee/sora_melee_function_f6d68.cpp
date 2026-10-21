#include <types.h>
#pragma force_active on

extern "C" void fn_27_FE118(s16* a, const s16* b);

class Mem {
public:
    virtual void v0();
    virtual void* get(s32 index);
    virtual void v2();
    virtual s32 count();
};

class Visitor {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void visit(void** p);
};

class Owner {
public:
    virtual void vf0();
    u8 m_pad[0xC];
    Mem m_mem;
};

extern "C" {
void fn_27_F6D68(Owner* self, s16* mask, Visitor* v) {
    s32 n = self->m_mem.count();
    for (s32 i = 0; i < n; i++) {
        s16 f;
        fn_27_FE118(&f, (const s16*)self->m_mem.get(i));
        if (f & *mask) {
            void* p = self->m_mem.get(i);
            v->visit(&p);
        }
    }
}
}
