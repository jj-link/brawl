#pragma force_active on

typedef signed short s16;
typedef signed int s32;

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
    virtual void vf10(void** p);
};

class soOuter {
public:
    char pad[0x10];
    soInner m_inner;
};

extern "C" void fn_27_11B884(s16* a, const s16* b);

extern "C" {
void fn_27_11B268(soOuter* self, s16* mask, soVisitor* visitor) {
    s32 count = self->m_inner.vf3();
    for (s32 i = 0; i < count; i++) {
        s16 kind;
        fn_27_11B884(&kind, (s16*)self->m_inner.vf1(i));
        if (kind & *mask) {
            void* p = self->m_inner.vf1(i);
            visitor->vf10(&p);
        }
    }
}
}
