#pragma force_active on
extern "C" void* fn_27_C8F28(void*);

class Foo {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int v4();
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
};

extern "C" void* fn_27_C8810(void* self) {
    Foo* obj = (Foo*)self;
    int idx = (int)fn_27_C8F28(self);
    if (obj->v4() != 1 && idx >= 0) {
        obj->v13();
    }
    return (void*)((char*)self + idx * 0x18 + 0xc);
}
