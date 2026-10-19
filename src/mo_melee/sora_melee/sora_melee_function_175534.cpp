#pragma force_active on
extern "C" void fn_27_17496C(void);

class soIface {
public:
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9(int arg);
};

extern "C" {
void fn_27_175534(void* unused, char* obj) {
    fn_27_17496C();
    char* sub = *(char**)(obj + 0xd8);
    soIface* iface = *(soIface**)(sub + 0x58);
    iface->vfn9(1);
}
}
