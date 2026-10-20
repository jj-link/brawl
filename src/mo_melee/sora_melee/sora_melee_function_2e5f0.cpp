#pragma force_active on
extern "C" void fn_27_3030C(void* p, int v);

class soInner {
public:
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
};

class soObj {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
};

class soSelf {
public:
    char pad0[0x28];
    soInner* m_inner;
    char pad1[0x44 - 0x2c];
    soObj* m_obj;
};

extern "C" void fn_27_2E5F0(soSelf* self) {
    void* p = self->m_inner->f1();
    fn_27_3030C(p, 0);
    self->m_obj->v10();
}
