#pragma force_active on
extern "C" void fn_27_194790(void* self, void* arg);

class IFoo {
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

extern "C" void fn_27_151A94(void* unused, void* obj) {
    void* a = *(void**)((unsigned char*)obj + 0xd8);
    IFoo* b = *(IFoo**)((unsigned char*)a + 0x70);
    void* c = b->get();
    fn_27_194790(obj, c);
}
