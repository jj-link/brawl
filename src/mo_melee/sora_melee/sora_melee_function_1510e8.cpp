#pragma force_active on
class fn27Iface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

extern "C" void fn_27_1510E8(void* p) {
    ((fn27Iface*)((char*)p + 0x30))->v5();
}
