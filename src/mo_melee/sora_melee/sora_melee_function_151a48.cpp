#pragma force_active on
extern "C" void fn_27_19476C(void* a, void* b);

class VBase {
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
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void* get();
};

struct Mid {
    char pad[0x70];
    VBase* p;
};

struct Obj {
    char pad[0xd8];
    Mid* m;
};

extern "C" {
void fn_27_151A48(void*, Obj* obj) {
    fn_27_19476C(obj, obj->m->p->get());
}
}
