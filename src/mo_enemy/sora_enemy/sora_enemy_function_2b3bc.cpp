#pragma force_active on
class emSubBase {
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
};

struct emSubOwner {
    char pad[0x2c];
    emSubBase* m_sub;
};

extern "C" void fn_41_2B3BC(emSubOwner* owner) {
    owner->m_sub->v7();
}
