#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_27_28F618(void* obj, u32 arg);

class fn27Sub {
public:
    virtual void v2() = 0;
    virtual fn27Sub* v3(u32 arg) = 0;
    void* m_04;
};

class fn27Base {
public:
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual bool isReady(u32 arg) = 0;
    u8 m_pad[0x34];
    fn27Sub* m_38;
};

extern "C" {
void fn_27_BA9B8(fn27Base* self, u32 a, u32 b) {
    if (self->isReady(b)) {
        fn27Sub* r = self->m_38->v3(b);
        fn_27_28F618(r->m_04, a);
    }
}
}
