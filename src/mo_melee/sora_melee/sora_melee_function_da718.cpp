#pragma force_active on
struct fn_27_DA718_Interface {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void call();
};

extern "C" void fn_27_DA718(void* self) {
    ((fn_27_DA718_Interface**)((char*)self + 8))[0]->call();
}
