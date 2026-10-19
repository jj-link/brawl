#pragma force_active on
extern "C" void fn_27_12BAF8(void* object, int param);

struct VBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int a, unsigned int b);
};

extern "C" {
void fn_104_9984(void* object, int param) {
    fn_27_12BAF8(object, param);
    unsigned char* p = static_cast<unsigned char*>(object);
    void* a = *reinterpret_cast<void**>(p + 0x60);
    void* b = *reinterpret_cast<void**>(static_cast<unsigned char*>(a) + 0xd8);
    VBase* c = *reinterpret_cast<VBase**>(static_cast<unsigned char*>(b) + 0x64);
    c->v5(0, 0x10000040u);
}
}
