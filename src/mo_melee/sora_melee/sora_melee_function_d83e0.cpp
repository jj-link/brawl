#pragma force_active on

typedef int s32;
typedef unsigned int u32;

class soArraySub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 isBusy();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void onOverflow();
    virtual void v14();
};

class soArray {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void prepare();
    virtual void v7();

    void* m_unk4;
    void* m_unk8;
    void* m_unkC;
    soArraySub m_sub;
};

extern "C" void* fn_27_D83E0(soArray* self, s32 index) {
    self->prepare();
    if (self->m_sub.isBusy() != 1) {
        if (index >= 0) {
            self->m_sub.onOverflow();
        }
    }
    return (void*)((char*)self + index * 0x18 + 0x1C);
}
