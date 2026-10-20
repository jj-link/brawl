#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_27_2F00C(u8* p, u32 bit, u32 flag);

class fn27Inner {
public:
    virtual void vf0() = 0;
    virtual u8* vf1(u32 a, u32 b) = 0;
};

class fn27Owner {
public:
    u8 pad[0x28];
    fn27Inner* m_inner;
};

extern "C" void fn_27_29924(fn27Owner* owner, u32 bit, u32 flag, u32 arg) {
    u8* p = owner->m_inner->vf1(arg, flag);
    fn_27_2F00C(p, bit, flag);
}
