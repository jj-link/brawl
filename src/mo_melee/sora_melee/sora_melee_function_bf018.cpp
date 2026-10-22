#pragma force_active on
extern "C" void fn_27_C1054(char* p);
extern "C" void fn_27_C1088(void* p);

class Iface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual bool isActive();
    virtual void v10();
    virtual void v11();
    virtual bool check(unsigned int id);
};

struct S {
    char pad0[0x2c];
    void* acc;
    char pad1[0x140 - 0x30];
    int id;
    bool valid() const { return id != -1; }
};

extern "C" void fn_27_BF018(S* self) {
    if (self->valid()) {
        void* obj = *(void**)((char*)self->acc + 0xd8);
        Iface* obj3 = *(Iface**)((char*)obj + 0x6c);
        if (obj3->check(self->id) == true) {
            fn_27_C1054((char*)self + 0x30);
        }
    }

    void* obj = *(void**)((char*)self->acc + 0xd8);
    Iface* obj3 = *(Iface**)((char*)obj + 0x44);
    if (obj3->isActive() == false) {
        fn_27_C1088((char*)self + 0x30);
        fn_27_C1088((char*)self + 0xb8);
    }
}
