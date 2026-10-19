#pragma force_active on
extern "C" void fn_27_12BAF8(void* object, int param);

class FtIface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f7(int a, unsigned int b);
};

extern "C" void fn_119_76C4(void* object, int param) {
    fn_27_12BAF8(object, param);
    char* p = *(char**)((char*)object + 0x60);
    char* q = *(char**)(p + 0xd8);
    FtIface* iface = *(FtIface**)(q + 0x64);
    iface->f7(0, 0x10000040);
}
