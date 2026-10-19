#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

class fn_27_Sub {
public:
    virtual void f0();
    virtual fn_27_Sub* f1(u32 x);
    u8 pad[0xB0 - 4];
    u8 unkB0;
};

class fn_27_Owner {
public:
    u8 pad[0x48];
    fn_27_Sub* m_sub;
};

extern "C" void fn_27_494D4(fn_27_Owner* self, u8 a, u32 b) {
    self->m_sub->f1(b)->unkB0 = a;
}
