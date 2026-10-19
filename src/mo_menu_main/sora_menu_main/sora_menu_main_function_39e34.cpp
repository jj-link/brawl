#pragma force_active on
extern "C" int fn_800B61C0(void*);

struct MenuSub {
    virtual void v0() = 0;
    virtual void v1() = 0;
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
    virtual void doSomething(int) = 0;
};

struct MenuMain {
    char m_pad0[0x44];
    void* m_44;
    char m_pad1[0x24];
    int m_6c;
    MenuSub* m_70;
    char m_pad2[0xC4];
    int m_138;
};

extern "C" {
int fn_2_39E34(MenuMain* self) {
    if (fn_800B61C0(self->m_44)) {
        self->m_70->doSomething(self->m_6c);
        return 0xb;
    }
    return self->m_138;
}
}
