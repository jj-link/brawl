#pragma force_active on
typedef unsigned char u8;
typedef int s32;

class fnInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual s32 getCount();
};

class fnOuter {
public:
    u8 m_pad[0x2c];
    fnInner* m_inner;
};

extern "C" void fn_27_871D4(fnOuter* self, s32 n);

extern "C" void fn_27_B70B0(fnOuter* self, s32 n) {
    if (n >= self->m_inner->getCount()) {
        fn_27_871D4(self, n);
    }
}
