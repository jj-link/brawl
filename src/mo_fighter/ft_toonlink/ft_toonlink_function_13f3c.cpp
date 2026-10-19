#pragma force_active on
extern "C" void fn_27_1DACB8(void* fighter);

struct VObj {
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
    virtual void v16();
    virtual void v17();
    virtual void call(unsigned int arg);
};

extern "C" void fn_121_13F3C(void* fighter) {
    VObj* obj = *(VObj**)((char*)fighter + 0x60);
    obj = *(VObj**)((char*)obj + 0xd8);
    obj = *(VObj**)((char*)obj + 0x64);
    obj->call(0x12000004);
    fn_27_1DACB8(fighter);
}
