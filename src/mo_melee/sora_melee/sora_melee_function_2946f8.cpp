#include <types.h>
#pragma force_active on

class Member {
public:
    virtual void v0();
    virtual void* getItem(s32 index);
    virtual void v2();
    virtual s32 getCount();
};

class Visitor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void visit(void** p);
};

class Owner {
public:
    virtual void v0();
    u8 m_pad[0xC];
    Member m_mem;
};

extern "C" {
void fn_27_FE140(s16* dest, s16* src);

void fn_27_2946F8(Owner* self, s16* mask, Visitor* v) {
    s32 n = self->m_mem.getCount();
    for (s32 i = 0; i < n; i++) {
        s16 flags;
        fn_27_FE140(&flags, (s16*)self->m_mem.getItem(i));
        if (flags & *mask) {
            void* p = self->m_mem.getItem(i);
            v->visit(&p);
        }
    }
}
}
