#pragma force_active on
typedef unsigned char u8;

class fn_27_Sub {
public:
    virtual void f0();
    virtual fn_27_Sub* f1();
    u8 pad[0xB0];
    u8 unkB4;
};

class fn_27_Owner {
public:
    u8 pad[0x48];
    fn_27_Sub* m_sub;
};

extern "C" u8 fn_27_4945C(const fn_27_Owner* self) {
    return self->m_sub->f1()->unkB4;
}
