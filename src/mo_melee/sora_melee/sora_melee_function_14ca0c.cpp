#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_14B700(void* self);
extern "C" const float lbl_27_rodata_18D0;

struct VBase {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual float v21();
};

extern "C" void fn_27_14CA0C(char* self) {
    VBase* o = (VBase*)self;
    fn_27_14B700(self);
    *(u32*)(self + 0x538) = 0;
    VBase* c = (VBase*)*(char**)(*(char**)(*(char**)(self + 0x14) + 0xd8) + 0xc);
    float r = c->v21();
    if (lbl_27_rodata_18D0 != r) {
        o->v18();
        *(u32*)(self + 0x538) |= 1;
    }
}
