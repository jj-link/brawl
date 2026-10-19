#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;

class fn_27_Base {
public:
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    virtual void v9() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void target(s32 a, s32 b, u16* out, s32 timeout);
};

extern "C" void fn_27_84A40(fn_27_Base* self, s32 a, s32 b) {
    u16 result = 0;
    self->target(a, b, &result, -1);
}
