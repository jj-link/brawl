#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void vf0();
    virtual void* vf1(s32 idx);
    virtual void vf2();
    virtual s32 vf3();
};

class soVisitor {
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
    virtual void visit(void* p);
};

class soOuter {
public:
    virtual void vf0();
    u8 m_pad[0xC];
    soInner m_inner;
};

extern "C" {
void fn_27_1CF51C(s16* dest, s16* src);

void fn_27_1C1FC4(soOuter* self, s16* mask, soVisitor* visitor) {
    s16 sp8;
    void* spC;
    s32 n = self->m_inner.vf3();
    for (s32 i = 0; i < n; i++) {
        fn_27_1CF51C(&sp8, (s16*)self->m_inner.vf1(i));
        if (sp8 & *mask) {
            spC = self->m_inner.vf1(i);
            visitor->visit(&spC);
        }
    }
}
}
