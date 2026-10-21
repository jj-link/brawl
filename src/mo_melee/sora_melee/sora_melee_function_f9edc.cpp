#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0();
    virtual void* get(s32 index);
    virtual void vf2();
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
    virtual void apply(void** p);
};

struct Outer {
    char pad[0x10];
    Inner m_inner;
};

extern "C" void fn_27_FE190(short* a, const short* b);

extern "C" void fn_27_F9EDC(Outer* self, short* mask, Visitor* visitor) {
    s32 count = self->m_inner.count();
    short sp8;
    void* p;
    for (s32 i = 0; i < count; i++) {
        void* item = self->m_inner.get(i);
        fn_27_FE190(&sp8, (const short*)item);
        if (sp8 & *mask) {
            p = self->m_inner.get(i);
            visitor->apply(&p);
        }
    }
}
