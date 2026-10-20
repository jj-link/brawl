#pragma force_active on
typedef unsigned char u8;

class fn27Iface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct fn27Holder {
    u8 pad[0xc];
    fn27Iface iface;
};

extern "C" {
void fn_27_D5868(fn27Holder* p) {
    fn27Iface* i = (fn27Iface*)((char*)p + 0xc);
    i->f4();
}
}
