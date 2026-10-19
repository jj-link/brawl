#pragma force_active on
class fn27Iface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual bool vf4(unsigned int arg);
};

class fn27Owner {
public:
    unsigned char pad[0x2AAC];
    fn27Iface m_iface;
};

extern "C" bool fn_27_28FE04(fn27Owner* self) {
    return self->m_iface.vf4(0x1000000E) != 0;
}
