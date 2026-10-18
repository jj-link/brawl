#pragma force_active on
class fn27Obj {
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
    virtual void v12(float f);
    char pad[0x3C];
    float m_40;
};

extern "C" void fn_27_25068(fn27Obj* self)
{
    self->v12(-self->m_40);
}
