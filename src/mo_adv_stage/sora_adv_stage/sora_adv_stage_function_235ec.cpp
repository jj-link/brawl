#pragma force_active on
struct Prefix {
    char padding[0x3c];
};

struct Obj : Prefix {
    virtual void v0(unsigned long);
    virtual void v1(unsigned long);
    virtual void v2(unsigned long);
    virtual void v3(unsigned long);
    virtual void v4(unsigned long);
    virtual void v5(unsigned long);
    virtual void v6(unsigned long);
    virtual void v7(unsigned long);
    virtual void v8(unsigned long);
    virtual void v9(unsigned long);
    virtual void v10(unsigned long);
    virtual void v11(unsigned long);
    virtual void v12(unsigned long);
    virtual void v13(unsigned long);
    virtual void v14(unsigned long);
    virtual void v15(unsigned long);
    virtual void v16(unsigned long);
    virtual void v17(unsigned long);
    virtual void v18(unsigned long);
    virtual void v19(unsigned long);
    virtual void v20(unsigned long);
    virtual void v21(unsigned long);
    virtual void v22(unsigned long);
    virtual void v23(unsigned long);
    virtual void v24(unsigned long);
    virtual void v25(unsigned long);
    virtual void v26(unsigned long);
    virtual void v27(unsigned long);
    unsigned char pad[0x14d - 0x40];
    unsigned char flag;
};

extern "C" {
void setEnableCollisionStatus__6GroundFb(void*, bool);
}

extern "C" void fn_40_235EC(Obj* self)
{
    self->v27(0);
    setEnableCollisionStatus__6GroundFb(self, false);
    self->flag = 1;
}
