#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned, unsigned);
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
    virtual void v18(unsigned);
};

extern "C" void fn_116_13BA8(void*, void* self) {
    Obj* obj = *(Obj**)((char*)self + 0xd8);
    obj = *(Obj**)((char*)obj + 0x64);
    obj->v18(0x22000000);
    obj = *(Obj**)((char*)self + 0xd8);
    obj = *(Obj**)((char*)obj + 0x64);
    obj->v5(0, 0x20000001);
}
