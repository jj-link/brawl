#pragma force_active on
extern "C" void fn_27_5AB60(int);

struct soIface {
    virtual void v0();
    virtual int v1(int);
    virtual void v2();
    virtual int v3();
};

class soControllerModuleImpl {
public:
    void activate();

private:
    char pad[0x10];
    soIface* m_iface;
};

void soControllerModuleImpl::activate() {
    int count = m_iface->v3();
    for (int i = 0; i < count; i++) {
        fn_27_5AB60(m_iface->v1(i));
    }
}
